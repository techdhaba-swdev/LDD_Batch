#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>

MODULE_LICENSE("GPL");

MODULE_AUTHOR("SRINU");



static int __init hellomodule_init(void )
{
	printk(KERN_INFO " HELLO FROM THE KERNEL MODULE ");
        return 0;

}
static void __exit hellomodule_exit(void )
{
	printk(KERN_INFO " bye from the kernel");

}

module_init(hellomodule_init);
module_exit(hellomodule_exit);

