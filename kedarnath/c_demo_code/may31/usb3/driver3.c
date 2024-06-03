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
#define STATIC_MAJOR_NUMBER 240  // Use a static major number

static struct usb_device *device;
static struct usb_class_driver class;
static unsigned char bulk_buf[512];
static int major_number = STATIC_MAJOR_NUMBER;
static struct class *usb_class = NULL;
static struct device *usb_device = NULL;
static struct cdev usb_cdev;

static int usb_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "usb_example: Device opened\n");
    return 0;
}

static int usb_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "usb_example: Device closed\n");
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

    printk(KERN_INFO "usb_example: Read %d bytes from the device\n", read_cnt);
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

    printk(KERN_INFO "usb_example: Wrote %d bytes to the device\n", wrote_cnt);
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

    printk(KERN_INFO "usb_example: Registering device\n");

    major_number = register_chrdev(STATIC_MAJOR_NUMBER, DEVICE_NAME, &fops);
    if (major_number < 0) {
        printk(KERN_ERR "usb_example: failed to register a major number\n");
        return major_number;
    }
    printk(KERN_INFO "usb_example: registered with major number %d\n", major_number);

    usb_class = class_create(CLASS_NAME); 
    if (IS_ERR(usb_class)) {
        unregister_chrdev(major_number, DEVICE_NAME);
        printk(KERN_ERR "usb_example: failed to register device class\n");
        return PTR_ERR(usb_class);
    }
    printk(KERN_INFO "usb_example: device class registered\n");

    usb_device = device_create(usb_class, NULL, MKDEV(major_number, 0), NULL, DEVICE_NAME);
    if (IS_ERR(usb_device)) {
        class_destroy(usb_class);
        unregister_chrdev(major_number, DEVICE_NAME);
        printk(KERN_ERR "usb_example: failed to create the device\n");
        return PTR_ERR(usb_device);
    }
    printk(KERN_INFO "usb_example: device created\n");

    class.name = "dev/usb_example"; 
    class.fops = &fops;
    retval = usb_register_dev(interface, &class);
    if (retval) {
        device_destroy(usb_class, MKDEV(major_number, 0)); 
        class_destroy(usb_class);
        unregister_chrdev(major_number, DEVICE_NAME);
        printk(KERN_ERR "usb_example: not able to get a minor for this device\n");
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
    int result = usb_register(&usb_driver);
    printk(KERN_INFO "usb_example: usb_register returned %d\n", result);
    return result;
}

static void __exit usb_exit(void) {
    usb_deregister(&usb_driver);
    printk(KERN_INFO "usb_example: Module exited\n");
}

module_init(usb_init);
module_exit(usb_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("techdhaba");
MODULE_DESCRIPTION("A simple USB driver example");
MODULE_VERSION("1.0");




