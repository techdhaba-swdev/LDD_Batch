#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>

//this is the basic device driver code 

//module init function which means this is the first fucntion will execute the first,when th linux device driver should be loaded in to the kernel.
static int __init hello_world_init(void){
    printk(KERN_INFO "HELO LITHEEF\n");
    printk(KERN_INFO "HOW ARE YOU\n");
    printk(KERN_DEBUG "DEBUGG IS STARTING\n");
    return 0;
}
//this is the exit function which means function tht will execute at ast when the linux device driver is unloaded from the kernel.
static void __exit hello_world_exit(void){
    printk(KERN_INFO "kernel module is unloaded sucefully\n");
    
}
module_init(hello_world_init);
module_exit(hello_world_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("YOUR NAME");
MODULE_DESCRIPTION("A SIMPLE BASIC BLOCK DRIVER");
MODULE_VERSION("1.0");
