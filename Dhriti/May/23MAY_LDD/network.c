#include <linux/module.h>
#include <linux/fs.h>
#include <linux/blkdev.h> //Defines block device related struct
#include <linux/hdreg.h> //Provides struct nd functions
#include <linux/vmalloc.h> //funcs for alocating memory in kernel's vms

#define DEVICE_NAME "simple_block"
#define SECTOR_SIZE 512
#define NSECTORS 1024  // Number of sectors in the device

static int major_num = 0;
static struct request_queue *queue;
static struct gendisk *gd;
static char *device_data;

// This function handles block device requests
static void simple_block_request(struct request_queue *q) {
    struct request *req;
    while ((req = blk_fetch_request(q)) != NULL) { //It proccesses block device req fetched from req queue
        if (req->cmd_type != REQ_TYPE_FS) { //If the reqnis not a fs req it skips the req and completes it with an error
            printk(KERN_NOTICE "Skip non-fs request\n");
            blk_end_request_all(req, -EIO);
            continue;
        }

        //Otherwise it  Handle the request here
        // For now, just complete it successfully
        blk_end_request_all(req, 0);
    }
}

// This function is called when the block device is opened
static int simple_block_open(struct block_device *bdev, fmode_t mode) {
    return 0;
}

// This function is called when the block device is released
static void simple_block_release(struct gendisk *gd, fmode_t mode) {
}

// This function provides geometry information about the device
static int simple_block_getgeo(struct block_device *bdev, struct hd_geometry *geo) { //geometry info refers to physical layout nd characs of the storage devices | set the values at hd_geometry
    geo->heads = 1;
    geo->sectors = NSECTORS;
    geo->cylinders = 1;
    geo->start = 0;
    return 0;
}

// Define block device operations
static struct block_device_operations simple_block_ops = {
    .owner = THIS_MODULE,
    .open = simple_block_open,
    .release = simple_block_release,
    .getgeo = simple_block_getgeo,
};

// Module initialization function
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

    // Configure the gendisk structure
    gd->major = major_num;
    gd->first_minor = 0;
    gd->fops = &simple_block_ops;
    gd->private_data = NULL;
    snprintf(gd->disk_name, 32, "simple_block");
    set_capacity(gd, NSECTORS);
    gd->queue = queue;

    // Add the disk to the system
    add_disk(gd);
    printk(KERN_INFO "simple_block: module loaded\n");
    return 0;
}

// Module cleanup function
static void __exit simple_block_exit(void) {
    // Remove the disk from the system
    del_gendisk(gd);
    put_disk(gd);
    // Cleanup the request queue
    blk_cleanup_queue(queue);
    // Unregister the block device
    unregister_blkdev(major_num, DEVICE_NAME);
    // Free the allocated memory
    vfree(device_data);
    printk(KERN_INFO "simple_block: module unloaded\n");
}

// Specify the module initialization and cleanup functions
module_init(simple_block_init);
module_exit(simple_block_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("techdhaba");
MODULE_DESCRIPTION("A simple block device driver");
MODULE_VERSION("0.1");
