#include <linux/init.h>
#include <linux/module.h>
#include <linux/kobject.h>
#include <linux/sysfs.h>
#include <linux/uaccess.h>

// Define data variable with proper access control
static DEFINE_RWLOCK(data_lock); // Read-write lock for data access
static int data = 0;

// Define kobject and attribute name for sysfs entry
static struct kobject *kobj;
static const char data_name[] = "my_data";

// Function to show the value of data in sysfs
static ssize_t data_show(struct kobject *kobj, struct attribute *attr, char *buf) {
  read_lock(&data_lock); // Acquire lock before reading data
  int ret = sprintf(buf, "%d\n", data);
  read_unlock(&data_lock); // Release lock after reading
  return ret;
}

// Function to write to data through sysfs
static ssize_t data_store(struct kobject *kobj, struct attribute *attr, const char *buf, size_t count) {
  int new_data;
  write_lock(&data_lock); // Acquire lock before modifying data
  if (kstrtol(buf, 10, &new_data)) { // Safe integer conversion
    write_unlock(&data_lock);
    return -EINVAL; // Invalid input
  }
  data = new_data;
  write_unlock(&data_lock); // Release lock after modification
  return count;
}

// Define attribute for data
static struct attribute data_attr = __ATTR(my_data, 0664, data_show, data_store);

// Define attribute group (remains unchanged)
static struct attribute *attrs[] = {
  &data_attr,
  NULL,
};

static struct attribute_group attr_group = {
  .attrs = attrs,
};

// Module initialization (improved for clarity)
static int __init data_module_init(void) {
  int ret;

  // Create kobject for sysfs entry
  kobj = kobject_create_and_add("my_data_module", kernel_kobj);
  if (!kobj)
    return -ENOMEM;

  // Create sysfs entry for data
  ret = sysfs_create_group(kobj, &attr_group);
  if (ret) {
    kobject_put(kobj);
    return ret;
  }

  printk(KERN_INFO "Data module loaded!\n");
  return 0;
}

// Module cleanup (remains unchanged)
static void __exit data_module_exit(void) {
  sysfs_remove_group(kobj, &attr_group);
  kobject_put(kobj);

  printk(KERN_INFO "Data module unloaded!\n");
}

module_init(data_module_init);
module_exit(data_module_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("TechDhaba");
MODULE_DESCRIPTION("A simple kernel module for data access through sysfs");
