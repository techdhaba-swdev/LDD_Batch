#include <linux/init.h>          // Include header file for kernel module initialization
#include <linux/module.h>        // Include header file for kernel modules
#include <linux/kobject.h>       // Include header file for kernel object management
#include <linux/sysfs.h>         // Include header file for sysfs support
#include <linux/uaccess.h>       // Include header file for user-space access
 
static int data;  // Define a variable to store data

static struct kobject *kobj;    // Define a pointer to a kernel object
static char *data_name = "my_data";  // Define a name for the data attribute

// Function to show the value of data in sysfs
static ssize_t data_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf) {
  return sprintf(buf, "%d\n", data);  // Copy the value of 'data' to the buffer
}

// Function to write to data through sysfs
static ssize_t data_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count) {
  long tmp;
  int res;

  // Convert the input buffer to a long integer
  res = kstrtol(buf, 0, &tmp);
  if (res < 0)
    return res;

  // Update the value of 'data'
  data = tmp;
  return count; // Return the number of bytes written
}

// Define attribute for data
static struct kobj_attribute data_attr = __ATTR(my_data, 0664, data_show, data_store); // Define attribute for 'my_data'

// Define default attributes array
static struct attribute *default_attrs[] = {
    &data_attr.attr, // Add 'data_attr' to the array of attributes
    NULL,            // Terminate the array
};

// Define attribute group
static struct attribute_group attr_group = {
    .attrs = default_attrs,  // Set the attributes array for the group
};

// Function to initialize the module
static int __init data_module_init(void) {
  int ret;

  // Create kobject for sysfs entry
  kobj = kobject_create_and_add("my_data_module", NULL); // Create a kobject with name "my_data_module"
  if (!kobj)
    return -ENOMEM;

  // Create sysfs entry for data
  ret = sysfs_create_group(kobj, &attr_group); // Create sysfs entries for attributes in 'attr_group'
  if (ret) {
    kobject_put(kobj); // Cleanup if creation fails
    return ret;
  }

  printk(KERN_INFO "Data module loaded!\n"); // Print message to kernel log
  return 0; // Return success
}

// Function to cleanup and exit the module
static void __exit data_module_exit(void) {
  // Remove sysfs entry
  sysfs_remove_group(kobj, &attr_group); // Remove the attribute group from sysfs
  kobject_put(kobj); // Cleanup the kobject

  printk(KERN_INFO "Data module unloaded!\n"); // Print message to kernel log
}

module_init(data_module_init);  // Define the function to be called when the module is loaded
module_exit(data_module_exit);  // Define the function to be called when the module is unloaded

MODULE_LICENSE("GPL");           // Set the license of the module to GPL
MODULE_AUTHOR("Dhriti");      // Set the author of the module
MODULE_DESCRIPTION("A simple kernel module for data access through sysfs");  // Set the description of the module

