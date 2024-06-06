#include <linux/module.h>
#include <linux/fs.h>
#include <linux/blkdev.h>
#include <linux/genhd.h>
#include <linux/hdreg.h>
#include <linux/vmalloc.h>

#define DEVICE_NAME "simple_block"
#define SECTOR_SIZE 512 //size of each sector
#define NSECTORS 1024  // Number of sectors in the device

//imagining creating a simple box in your computer

static int major_num = 0; //identification number of the box by the computer
static struct request_queue *queue; //a line or security guard where incoming requests wait(orders to store or retrieve data)
static struct gendisk *gd; //just like a control panel...keeps tracking everything
static char *device_data;

static void simple_block_request(struct request_queue *q) { //this call is like a worker that constantly checks queue for requests
    struct request *req;
    while ((req = blk_fetch_request(q)) != NULL) { //checks if req is related to storing or retrieving data everytime
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
//opening the box
static int simple_block_open(struct block_device *bdev, fmode_t mode) { //allowing access to device
    return 0;
}
//closing the box
static void simple_block_release(struct gendisk *gd, fmode_t mode) { //denying access to device .....presently open and close are empty but in real driver code they are used for security purposes
}
//gives the box information....gives info about box layout like  no.of sectors and how they are organised
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

//here we are making the box usable and this api sets everything up when module is loaded(insmod)
static int __init simple_block_init(void) {
    // Allocate space for the device data
    device_data = vmalloc(NSECTORS * SECTOR_SIZE); //allocating space or creating compartments inside the box
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

    // Setup the request queue for incoming requests
    queue = blk_init_queue(simple_block_request, NULL);
    if (!queue) {
        unregister_blkdev(major_num, DEVICE_NAME);
        vfree(device_data);
        return -ENOMEM;
    }

    // Setup the control panel for the box or gendisk structure
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
//putting away the box....this api cleans up when we unload the module(rmmod)
static void __exit simple_block_exit(void) {
    del_gendisk(gd); //removing the control panel
    put_disk(gd);
    blk_cleanup_queue(queue); //cleaning up the wait request queue
    unregister_blkdev(major_num, DEVICE_NAME); //unregistering the box
    vfree(device_data); //freeing up the memory
    printk(KERN_INFO "simple_block: module unloaded\n");
}

module_init(simple_block_init);
module_exit(simple_block_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("SARATH");
MODULE_DESCRIPTION("A simple block device driver");
MODULE_VERSION("0.1");
