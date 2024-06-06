#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kobject.h>
#include <linux/sysfs.h>
#include <linux/string.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MS");
MODULE_DESCRIPTION("A simple Linux sysfs driver");
MODULE_VERSION("0.1");

static struct kobject *example_kobject; //pointer to kobject struct representing sysfs entry
static int foo;

static ssize_t foo_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
    return sprintf(buf, "%d\n", foo);
}

static ssize_t foo_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count)
{
    sscanf(buf, "%du", &foo);
    return count;
}

static struct kobj_attribute foo_attribute = __ATTR(foo, 0660, foo_show, foo_store); //defining properties of sysfs entry named foo 1.name 2.mode 3.pointer to func that handles reading of attr value 4.pointer...that writes of attr value

static int __init example_init(void)
{
    int error = 0;

    example_kobject = kobject_create_and_add("example_kobject", kernel_kobj);//creating kernel object and adding to kobj tree
    if (!example_kobject)
        return -ENOMEM;

    error = sysfs_create_file(example_kobject, &foo_attribute.attr); //creating a sysfs entry named foo under example_kobect directory
    if (error) {
        pr_debug("failed to create the foo file in /sys/kernel/example_kobject\n");
    }

    return error;
}

static void __exit example_exit(void)
{
    kobject_put(example_kobject); //releasing sysfs entry by releasing refernce to kernel object
}

module_init(example_init);
module_exit(example_exit);
