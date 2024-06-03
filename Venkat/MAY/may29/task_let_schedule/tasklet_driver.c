#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/interrupt.h>

// Tasklet handler function
void my_tasklet_handler(struct tasklet_struct *t)
{
    printk(KERN_INFO "Tasklet handler called\n");
}

// Correctly declare the tasklet without the third argument
DECLARE_TASKLET(my_tasklet, my_tasklet_handler);

// Interrupt handler prototype
irqreturn_t my_interrupt_handler(int irq, void *dev_id)
{
    // Schedule the tasklet
    tasklet_schedule(&my_tasklet);
    return IRQ_HANDLED;
}

// Assume we have a valid IRQ number for demonstration purposes
#define MY_IRQ_NUMBER 123

static int __init my_module_init(void)
{
    printk(KERN_INFO "Loading tasklet module\n");
    // Register the interrupt handler
    if (request_irq(MY_IRQ_NUMBER, my_interrupt_handler, IRQF_SHARED, "my_interrupt_handler", NULL))
    {
        printk(KERN_ERR "my_module: Cannot register IRQ %d\n", MY_IRQ_NUMBER);
        return -EIO;
    }
    return 0;
}

static void __exit my_module_exit(void)
{
    // Free the IRQ
    free_irq(MY_IRQ_NUMBER, NULL);
    // Ensure the tasklet is killed before module exit
    tasklet_kill(&my_tasklet);
    printk(KERN_INFO "Unloading tasklet module\n");
}

module_init(my_module_init);
module_exit(my_module_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("techdhaba");
MODULE_DESCRIPTION("A simple tasklet example with interrupt handling");
