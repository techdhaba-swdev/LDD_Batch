#include <linux/module.h>   // needed by all kernel modules
#include <linux/fs.h>       // file system operations
#include <linux/blkdev.h>   // block device structures
#include <linux/genhd.h>    // genral hard disk header
#include <linux/hdreg.h>    // hard disk geometry structure 
#include <linux/vmalloc.h>

#define DEVICE_NAME "simple_block"  // device name 
#define SECTOR_SIZE 512             // sector sizw
#define NSECTORS 1024  // Number of sectors in the device

static int major_num = 0;     // major number
static struct request_queue *queue;  // request queue for the device
static struct gendisk *gd;   //general disk structure
static char *device_data;    //pointer to device data

// function to handle the block request
static void simple_block_request(struct request_queue *q) {
    struct request *req;
    while ((req = blk_fetch_request(q)) != NULL) {
        if (req->cmd_type != REQ_TYPE_FS) {
            printk(KERN_NOTICE "Skip non-fs request\n");
            blk_end_request_all(req, -EIO);
            continue;
        }

        // Handle the request here
        // For now, we just complete it successfully
        blk_end_request_all(req, 0);
    }
}

static int simple_block_open(struct block_device *bdev, fmode_t mode) {
    return 0;
}

static void simple_block_release(struct gendisk *gd, fmode_t mode) {
}

static int simple_block_getgeo(struct block_device *bdev, struct hd_geometry *geo) {
    geo->heads = 1;
    geo->sectors = NSECTORS;
    geo->cylinders = 1;
    geo->start = 0;
    return 0;
}

static struct block_device_operations simple_block_ops = {
    .owner = THIS_MODULE,
    .open = simple_block_open,
    .release = simple_block_release,
    .getgeo = simple_block_getgeo,
};

static int __init simple_block_init(void) {
    // Allocate space for the device data
    device_data = vmalloc(NSECTORS * SECTOR_SIZE);
    if (!device_data) {
        printk(KERN_WARNING "vmalloc failure.\n");
        return -ENOMEM;
    }

    // Register the block device
    major_num = register_blkdev(0, DEVICE_NAME);
    if (major_num <= 0) {
        printk(KERN_WARNING "Unable to get major number\n");
        vfree(device_data);
        return -EBUSY;
    }

    // Setup the request queue
    queue = blk_init_queue(simple_block_request, NULL);
    if (!queue) {
        unregister_blkdev(major_num, DEVICE_NAME);
        vfree(device_data);
        return -ENOMEM;
    }

    // Setup the gendisk structure
    gd = alloc_disk(1);
    if (!gd) {
        blk_cleanup_queue(queue);
        unregister_blkdev(major_num, DEVICE_NAME);
        vfree(device_data);
        return -ENOMEM;
    }

    gd->major = major_num;
    gd->first_minor = 0;
    gd->fops = &simple_block_ops;
    gd->private_data = NULL;
    snprintf(gd->disk_name, 32, "simple_block");
    set_capacity(gd, NSECTORS);
    gd->queue = queue;

    add_disk(gd);
    printk(KERN_INFO "simple_block: module loaded\n");
    return 0;
}

static void __exit simple_block_exit(void) {
    del_gendisk(gd);
    put_disk(gd);
    blk_cleanup_queue(queue);
    unregister_blkdev(major_num, DEVICE_NAME);
    vfree(device_data);
    printk(KERN_INFO "simple_block: module unloaded\n");
}

module_init(simple_block_init);
module_exit(simple_block_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("techdhaba");
MODULE_DESCRIPTION("A simple block device driver");
MODULE_VERSION("0.1");
