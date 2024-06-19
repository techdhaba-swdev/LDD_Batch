#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
MODULE_LICENSE("GPL");
MODULE_AUTHOR("AMAN");
MODULE_DESCRIPTION(" A SIMPLE LINUX KERNEL MODULE");
MODULE_VERSION("1.0");
static int __init simple_module_init(void){
	printk(KERN_INFO "simple module is loaded.\n");
	return 0;
}
static void __exit simple_module_exit(void){
	printk(KERN_INFO "simple module is unloaded");
}
module_init(simple_module_init);
module_exit(simple_module_exit);
