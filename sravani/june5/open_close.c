2.Open-closed principle :This principle is essential for writing code that is easy to maintain and revise. “You should be able to extend a class’s behavior without modifying it.”

* This principle contains two parameters
     1. Open for extension, meaning that the class’s behavior can be extended;
     2. Closed for modification, meaning that the source code is set and cannot be changed.
The idea of open-closed principle is that existing, well-tested classes will need to be modified when something needs to be added. Yet, changing classes can lead to problems or bugs. Instead of changing the class, you simply want to extend it.

example :

here in this example we are using separate function for handling IOCTL_CMD

static long handle_custom_ioctl(struct file *file, unsigned int cmd, unsigned long arg) {
    switch (cmd) {
        case IOCTL_CMD:
            return handle_ioctl_cmd(file, arg);  // Separate function for handling IOCTL_CMD
        default:
            return -ENOTTY;
    }
}

here we are using separate function for handling IOCTLs
static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = device_open,
    .release = device_release,
    .unlocked_ioctl = handle_custom_ioctl, // Use a separate function for handling IOCTLs
};
