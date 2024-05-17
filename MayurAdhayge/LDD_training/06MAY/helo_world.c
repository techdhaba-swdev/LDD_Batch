#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MAYUR");

static int helo_init(void)
{
    printk(KERN_INFO "Hello, world!\n");
    return 0;
}

static void helo_exit(void)
{
    printk(KERN_INFO "Goodbye, world!\n");
}

module_init(helo_init);
module_exit(helo_exit);
