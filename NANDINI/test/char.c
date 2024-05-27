#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "char_dev"
#define BUF_LEN 80

MODULE_LICENSE("GPL");
MODULE_AUTHOR("NANDINI");
MODULE_DESCRIPTION("A simple character device driver");

static int Major;       //major number to device
static char msg[BUF_LEN];   //device gives when asked for msg
static char *msg_Ptr;       //pointer to msg

//process to open device

static int device_open(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "Device opened\n");
    return 0;
}

//process to close device

static int device_release(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "Device closed\n");
    return 0;
}

//process reads from our device

static ssize_t device_read(struct file *filp, char *buffer, size_t length, loff_t *offset)
{
    int bytes_read = 0;

    if (*msg_Ptr == 0)    //return 0 at end of msg
        return 0;

    while (length && *msg_Ptr) {             //loop till buffer is completed
        put_user(*(msg_Ptr++), buffer++);    //it copies bytes to user 
        length--;
        bytes_read++;
    }

    return bytes_read;      //return no.of bytes read
}

//process to write device

static ssize_t device_write(struct file *filp, const char *buffer, size_t length, loff_t *offset)
{
    int bytes_written = 0;

    if (length > BUF_LEN)    //if data length is more than buffer,returns error
        return -EINVAL;

    memset(msg, 0, BUF_LEN);   //it clear buffer
    strncpy(msg, buffer, length);  //copy data frm usr to krnl buffer 
    msg_Ptr = msg;
    bytes_written = length;

    return bytes_written;
}

//structure for file operations

static struct file_operations fops = {
    .read = device_read,
    .write = device_write,
    .open = device_open,
    .release = device_release,
};

//process of modules loaded

static int __init chardev_init(void)
{
    Major = register_chrdev(0, DEVICE_NAME, &fops);   //register car dev for major number
    if (Major < 0) {
        printk(KERN_ALERT "Registering char device failed with %d\n", Major);
        return Major;
    }
    printk(KERN_INFO "Registered char device with major number %d\n", Major);
    return 0;
}

//process when modules unloaded

static void __exit chardev_exit(void)
{
    unregister_chrdev(Major, DEVICE_NAME);    //unregister char dev
    printk(KERN_INFO "Unregistered char device\n");
}

module_init(chardev_init);   //module initialization
module_exit(chardev_exit);   //module clean
