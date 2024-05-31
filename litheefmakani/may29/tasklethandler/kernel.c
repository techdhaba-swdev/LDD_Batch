#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/interrupt.h>

struct tasklet_struct my_tasklet;

void my_tasklet_handler(unsigned long data)
{
    //struct tasklet_struct *tasklet = (struct tasklet_struct *)data;
    printk(KERN_INFO "Tasklet handler called\n");
}

void init_tasklet(void)
{
    tasklet_init(&my_tasklet, my_tasklet_handler, 0);
}

void schedule_tasklet(void)
{
    tasklet_schedule(&my_tasklet);
}

void exit_tasklet(void)
{
    tasklet_kill(&my_tasklet);
}

void my_interrupt_handler(void)
{
    // Placeholder function for interrupt handling
    // You can add your interrupt handling logic here

    // Schedule the tasklet
    schedule_tasklet();
}

static int __init my_module_init(void)
{
    printk(KERN_INFO "Loading tasklet module\n");
    // Initialize and schedule the tasklet
    init_tasklet();
    my_interrupt_handler(); // Simulate interrupt triggering
    return 0;
}

static void __exit my_module_exit(void)
{
    // Ensure the tasklet is killed before module exit
    exit_tasklet();
    printk(KERN_INFO "Unloading tasklet module\n");
}

module_init(my_module_init);
module_exit(my_module_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("techdhaba");
MODULE_DESCRIPTION("A simple tasklet example using functions");
