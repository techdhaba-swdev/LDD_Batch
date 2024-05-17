#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Dual BSD");

static int_init hello_init(void) {
       	printk(KERN_INFO "Hello, world\n");
       	return 0;
}

static void_exit hello_exit(void) {
       	printk(KERN_INFO "Goodbye, cruel world\n");
}

module_init(hello_init);
module_exit(hello_exit);
