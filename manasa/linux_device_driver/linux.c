#include<linux/init.h>
#include<linux/module.h>
#include<linux/printk.h>
MODULE_LICENSE("GPL");
MODULE_AUTHOR("TECHDHABA");
static int __init hello_init(void)
{
        printk(KERN_INFO "Hello,World/n");
        return 0;
}
static void __exit hello_exit(void)
{
        printk(KERN_INFO "Good Bye,Cruel world\n");
}
module_init(hello_init);
module_exit(hello_exit);
