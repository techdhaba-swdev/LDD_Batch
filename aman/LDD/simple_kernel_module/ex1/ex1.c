#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>
MODULE_LICENSE("GPL");
MODULE_AUTHOR("AMAN");
MODULE_DESCRIPTION("SIMPLE KERNEL MODULE1");
MODULE_VERSION("1.0");
static int __init simple_kernel1_init(void){
        printk(KERN_INFO "simple kernel1 is loaded");
        return 0;
}
static void __exit simple_kernel1_exit(void){
        printk(KERN_INFO "simple kernel1 is unloaded");
}
module_init(simple_kernel1_init);
module_exit(simple_kernel1_exit);

