3. Liskov Substitution Principle (LSP) : 

example : 

In this driver, LSP can be applied by ensuring that the struct file_operations remains consistent and can handle different devices without modification.

Using function pointers to ensure different implementations can be substituted without changing the dependent code.

#include <linux/fs.h>

typedef struct device_ops {
    int (*open)(struct inode *, struct file *);
    int (*release)(struct inode *, struct file *);
    long (*ioctl)(struct file *, unsigned int, unsigned long);
} device_ops_t;

static int device_open(struct inode *inode, struct file *file);
static int device_release(struct inode *inode, struct file *file);
static long device_ioctl(struct file *file, unsigned int cmd, unsigned long arg);

static device_ops_t dev_ops = {
    .open = device_open,
    .release = device_release,
    .ioctl = device_ioctl,
};
