#include <linux/init.h>
#include <linux/module.h>
MODULE_LICENSE("GPL");
static int hello_init(void) {
	printk(KERN_ALERT "hello World \n");
	return 0;

}
static void hello_exit(void) {
	printk(KERN_ALERT "Goodbye, cruel  World \n");
}
module_init(hello_init);
module_init(hello_exit);

