#include <linux/init.h>
#include <linux/module.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <linux/ioctl.h>

#define DEVICE_NAME "example"
#define IOCTL_MAGIC 'k'
#define IOCTL_add _IOWR(IOCTL_MAGIC , 1 , struct ioctl * )
#define IOCTL_sub _IOWR(IOCTL_MAGIC , 2 , struct ioctl * )

struct ioctl {
	int num1;
	int num2;
};

static int major;


static int ioctl_open (struct inode *inode , struct file *file)
{
	printk(KERN_INFO "ioctl device opened \n ");
	return 0;
}

static int ioctl_release (struct inode *inode , struct file *file)
{
	printk(KERN_INFO "ioctl device closed \n ");
	return 0;
}

static ssize_t  device_ioctl(struct file *file , unsigned int cmd , unsigned long arg)
{
struct ioctl data;

switch(cmd)
{
	struct ioctl data;
	case IOCTL_add :
		if (copy_from_user (&data ,(struct ioctl*)arg , sizeof(struct ioctl)) !=0 )
		{
			printk("value to copy from user is unsuccess \n");
			return -EFAULT;
		}
	printk(KERN_INFO "value from user space %d%d\n " , data.num1 , data.num2);
	int sum = data.num1 + data.num2;
		
		if(copy_to_user ((struct ioctl*)arg, &sum , sizeof(struct ioctl)) != 0)
		{
			printk("value to copy from kernel to user is failed\n");
			return -EFAULT;
		}
		printk(KERN_INFO "double value copied to user %d\n" , sum);

		break;
	
	case IOCTL_sub :
                if (copy_from_user (&data ,(struct ioctl*)arg , sizeof(struct ioctl)) !=0 )
                {
                        printk("value to copy from user is unsuccess \n");
                        return -EFAULT;
                }
        printk(KERN_INFO "value from user space %d%d\n " , data.num1 , data.num2);
        int sub = data.num1 - data.num2;

                if(copy_to_user ((struct ioctl*)arg, &sum , sizeof(struct ioctl)) != 0)
                {
                        printk("value to copy from kernel to user is failed\n");
                        return -EFAULT;
                }
                printk(KERN_INFO "double value copied to user %d\n" , sub);

                break;


	default :
		printk("command passes is un matched \n");
		return -1;
}
return 0;
}
static struct file_operations fops =
{
	.open = ioctl_open,
	.release = ioctl_release,
	.unlocked_ioctl = device_ioctl,
};

static int __init ioctl_start(void)
{
	major = register_chrdev(0 , DEVICE_NAME , &fops);
	if(major < 0)
	{
		printk(KERN_INFO "major number not registered for device \n");
		return -1;
	}
	printk(KERN_INFO "major number regidtered for device %d\n ", major);
	return 0;
}

static void __exit ioctl_stop(void)
{
	unregister_chrdev(major , DEVICE_NAME);
	printk(KERN_INFO "device unregistered with major number %d \n ", major);
}

module_init(ioctl_start);
module_exit(ioctl_stop);

MODULE_LICENSE ("GPL");
MODULE_AUTHOR("BADRINATH");
MODULE_DESCRIPTION("IOCTL DOUBLE VALUE");

