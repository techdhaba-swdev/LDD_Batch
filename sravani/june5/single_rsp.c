SOLID is an acronym that stands for five key design principles: 
1.Single responsibility principle. 
2.Open-closed principle. 
3.Liskov substitution principle. 
4.Interface segregation principle. 
5.Dependency inversion principle. 

1. single responsibility principle :  this principle states that, “a class should have only one reason to change.” 
 *Means that each class only does one thing and every class or module only has responsibility for one part of the software’s functionality.
example :

the flowing are the example of single responsibility principle whare initialize_device function has only one responsibility to do that is intitialization of character driver and same like cleanup_device has only one responsibility that is to clean up module

// Function to initialize the character device
static int initialize_device(void) {
    major_number = register_chrdev(0, DEVICE_NAME, &fops);
    if (major_number < 0) {
        printk(KERN_ALERT "Registering char device failed with %d\n", major_number);
        return major_number;
    }

    cdev_init(&my_cdev, &fops);
    my_cdev.owner = THIS_MODULE;
    if (cdev_add(&my_cdev, MKDEV(major_number, 0), 1)) {
        unregister_chrdev(major_number, DEVICE_NAME);
        printk(KERN_ALERT "Adding cdev failed\n");
        return -1;
    }

    printk(KERN_INFO "Device registered with major number %d\n", major_number);
    return 0;
}

// Function to clean up the character device
static void cleanup_device(void) {
    cdev_del(&my_cdev);
    unregister_chrdev(major_number, DEVICE_NAME);
    printk(KERN_INFO "Device unregistered\n");
}

static int __init my_ioctl_init(void) {
    return initialize_device();
}

static void __exit my_ioctl_exit(void) {
    cleanup_device();
}
