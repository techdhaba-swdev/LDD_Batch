#include <linux/init.h>
#include <linux/fs.h>
#include <linux/printk.h>
#include <linux/module.h>
dev_t device_number;

static int __init pro_init(void)
{
    int check_alloc;
    check_alloc = alloc_chrdev_region(&device_number, 0, 1, "dev_num");
    if (check_alloc < 0) {
        printk(KERN_INFO "FAILED TO ALLOCATE THE DEVICE NUMBER\n");
        return check_alloc; // Return the error code
    } else {
        printk(KERN_INFO "SUCCESSFULLY ALLOCATED THE DEVICE NUMBER\n");
        return 0;
    }
}

static void __exit pro_exit(void)
{
    unregister_chrdev_region(device_number, 1);
    printk(KERN_INFO "SUCCESSFULLY DEALLOCATED THE DEVICE NUMBER\n");
}

module_init(pro_init);
module_exit(pro_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MAYUR");
