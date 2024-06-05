#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/usb.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <linux/cdev.h>

#define VENDOR_ID 0x1234   // Replace with your USB device's vendor ID
#define PRODUCT_ID 0x5678  // Replace with your USB device's product ID

#define DEVICE_NAME "usb_example"
#define CLASS_NAME  "usb_class"

static struct usb_device *device;
static struct usb_class_driver class;
static unsigned char bulk_buf[512];
static int major_number;
static struct class *usb_class = NULL;
static struct device *usb_device = NULL;
static struct cdev usb_cdev;

static int usb_open(struct inode *inode, struct file *file) {
    return 0;
}

static int usb_release(struct inode *inode, struct file *file) {
    return 0;
}

static ssize_t usb_read(struct file *file, char __user *user_buffer, size_t count, loff_t *ppos) {
    int retval;
    int read_cnt;

    retval = usb_bulk_msg(device, usb_rcvbulkpipe(device, 0x81), bulk_buf, min(count, sizeof(bulk_buf)), &read_cnt, 5000);
    if (retval) {
        printk(KERN_ERR "usb_example: bulk message returned %d\n", retval);
        return retval;
    }
    if (copy_to_user(user_buffer, bulk_buf, read_cnt)) {
        return -EFAULT;
    }

    return read_cnt;
}

static ssize_t usb_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *ppos) {
    int retval;
    int wrote_cnt = min(count, sizeof(bulk_buf));

    if (copy_from_user(bulk_buf, user_buffer, wrote_cnt)) {
        return -EFAULT;
    }

    retval = usb_bulk_msg(device, usb_sndbulkpipe(device, 0x02), bulk_buf, wrote_cnt, &wrote_cnt, 5000);
    if (retval) {
        printk(KERN_ERR "usb_example: bulk message returned %d\n", retval);
        return retval;
    }

    return wrote_cnt;
}

static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = usb_open,
    .release = usb_release,
    .read = usb_read,
    .write = usb_write,
};

static int usb_probe(struct usb_interface *interface, const struct usb_device_id *id) {
    int retval;

    device = interface_to_usbdev(interface);

    major_number = register_chrdev(0, DEVICE_NAME, &fops);
    if (major_number < 0) {
        printk(KERN_ERR "usb_example: failed to register a major number\n");
        return major_number;
    }

    usb_class = class_create( CLASS_NAME);
    if (IS_ERR(usb_class)) {
        unregister_chrdev(major_number, DEVICE_NAME);
        printk(KERN_ERR "usb_example: failed to register device class\n");
        return PTR_ERR(usb_class);
    }

    usb_device = device_create(usb_class, NULL, MKDEV(major_number, 0), NULL, DEVICE_NAME);
    if (IS_ERR(usb_device)) {
        class_destroy(usb_class);
        unregister_chrdev(major_number, DEVICE_NAME);
        printk(KERN_ERR "usb_example: failed to create the device\n");
        return PTR_ERR(usb_device);
    }

    class.name = "usb/usb_example";
    class.fops = &fops;
    retval = usb_register_dev(interface, &class);
    if (retval) {
        device_destroy(usb_class, MKDEV(major_number, 0));
        class_destroy(usb_class);
        unregister_chrdev(major_number, DEVICE_NAME);
        printk(KERN_ERR "usb_example: not able to get a minor for this device.\n");
    } else {
        printk(KERN_INFO "usb_example: USB device connected\n");
    }

    return retval;
}

static void usb_disconnect(struct usb_interface *interface) {
    usb_deregister_dev(interface, &class);
    device_destroy(usb_class, MKDEV(major_number, 0));
    class_unregister(usb_class);
    class_destroy(usb_class);
    unregister_chrdev(major_number, DEVICE_NAME);
    printk(KERN_INFO "usb_example: USB device disconnected\n");
}

static struct usb_device_id usb_table[] = {
    { USB_DEVICE(VENDOR_ID, PRODUCT_ID) },
    { }
};
MODULE_DEVICE_TABLE(usb, usb_table);

static struct usb_driver usb_driver = {
    .name = "usb_example",
    .id_table = usb_table,
    .probe = usb_probe,
    .disconnect = usb_disconnect,
};

static int __init usb_init(void) {
    return usb_register(&usb_driver);
}

static void __exit usb_exit(void) {
    usb_deregister(&usb_driver);
}

module_init(usb_init);
module_exit(usb_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("techdhaba");
MODULE_DESCRIPTION("A simple USB driver example");
MODULE_VERSION("1.0");

