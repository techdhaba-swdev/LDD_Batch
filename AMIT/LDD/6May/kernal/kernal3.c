#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/sysfs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Kernel Module with Sysfs Attribute");

static int my_data = 42; // Example data (you can replace with your own)

// Sysfs attribute handler function
static ssize_t my_data_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
    return snprintf(buf, PAGE_SIZE, "%d\n", my_data);
}

// Define the sysfs attribute
static struct kobj_attribute my_data_attr = __ATTR_RO(my_data);

// Create a kobject and associate the sysfs attribute
static struct kobject *my_kobj;

static int __init my_module_init(void)
{
    int result;

    // Create a kobject
    my_kobj = kobject_create_and_add("my_module", kernel_kobj);
    if (!my_kobj)
        return -ENOMEM;

    // Associate the sysfs attribute with the kobject
    result = sysfs_create_file(my_kobj, &my_data_attr.attr);
    if (result)
        kobject_put(my_kobj);

    return result;
}

static void __exit my_module_exit(void)
{
    // Remove the sysfs attribute and kobject
    sysfs_remove_file(my_kobj, &my_data_attr.attr);
    kobject_put(my_kobj);
}

module_init(my_module_init);
module_exit(my_module_exit);
