#include <linux/module.h>
#include <linux/fs.h>
#include <linux/mm.h>
#include <linux/io.h>
#include <linux/uaccess.h>
#include <linux/slab.h>

#define DEVICE_NAME "my_device"
#define DEVICE_MEMORY_SIZE 4096  // 4KB
#define NUM_COUNT 10
static char *device_memory;
static int major_number;

static int my_device_open(struct inode *inode, struct file *file) { 
    printk(KERN_INFO "my_device: open\n");
    return 0;
}

static int my_device_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "my_device: release\n");
    return 0;
}

static ssize_t my_device_write(struct file *file, const char __user *buffer, size_t len, loff_t *ppos) {
   
      int num , sum = 0;
  
    // modification
      if (len <  sizeof(int) * NUM_COUNT+sizeof(char)) {
	      return -EINVAL;
    }

    if (copy_from_user(device_memory, buffer, len)) { // here buffer data write into device_memory like page tables 
        return -EFAULT;
    }

    for(int i = 0; i<NUM_COUNT;i++) {
	    memcpy(&num,device_memory + i * sizeof(int),sizeof(int)); // acessing data from device_memort from page table array
	    sum +=num; // each single iterate number is stored into num from memory each loop storing the sum and add next element need to add
    } 
    printk(KERN_ALERT "sum is  %d\n", sum);
     // result is strored in device_memeory in nextpass as an argument read from device_memeory and send it to user space
    memcpy(device_memory, &sum, sizeof(int)); // total sum is stored to device_memory and and with a size of 4kb

    return len;
}

static ssize_t my_device_read(struct file *file, char __user *buffer, size_t len, loff_t *ppos) {
    if (copy_to_user(buffer, device_memory, sizeof(int))) { // read here result is storedd iin device_memeory , 4kb we are sending 
        return -EFAULT;
    }
    return sizeof(int);
} 

//process for below mmap
 // iam doing 3 process here
  // 1 need to identify the physical address from page/pagetable it is identified by page frame number how can i do
  // i will shift the physical address with page shift to the right here page_offset is mapped from 1 to 32 bits thi is the size
  // what it will 'do struct vm_area_struct *vma' it is a page creation
  // vm_start it is beginning of the memory and vm_end is the end of the memeory
static int my_device_mmap(struct file *filp, struct vm_area_struct *vma) { // i have here created page is vma
    unsigned long offset = vma->vm_pgoff << PAGE_SHIFT;//here the process need to identify the physcial address by diving page table
    unsigned long physical_address = virt_to_phys(device_memory) + offset;//mapping with virtual to physcial address + physical memory
    unsigned long size = vma->vm_end - vma->vm_start; // total memory size 

    if (size > DEVICE_MEMORY_SIZE) {
        return -EINVAL;
    }

    if (remap_pfn_range(vma, vma->vm_start, physical_address >> PAGE_SHIFT, size, vma->vm_page_prot)) {
        return -EAGAIN;
    }

    return 0;
}

static const struct file_operations my_device_fops = { 
    .owner = THIS_MODULE,
    .open = my_device_open,
    .release = my_device_release,
    .write = my_device_write,
    .read = my_device_read,
    .mmap = my_device_mmap,
};

static int __init my_device_init(void) { // first how can i connect to kernel here steps 
					 // with major number we reigistering and intial minor number 0 let os choose it 
					 // i need one device structure device to intialize the registerdered device 
					 // i will use c dev_t is no necessorry but its second if first registering failed 
    major_number = register_chrdev(0, DEVICE_NAME, &my_device_fops);// here my code extracts/initilize aceessing resources of functions use of pointers    in module
    if (major_number < 0) {
        printk(KERN_ALERT "Registering char device failed with %d\n", major_number);
        return major_number;
    }

    device_memory = kmalloc(DEVICE_MEMORY_SIZE, GFP_KERNEL);
    if (!device_memory) {
        unregister_chrdev(major_number, DEVICE_NAME);
        return -ENOMEM;
    }

    printk(KERN_INFO "my_device: registered with major number %d\n", major_number);
    printk(KERN_INFO "my_device: memory allocated at %p\n", device_memory);
    return 0;
}

static void __exit my_device_exit(void) {
    kfree(device_memory);
    unregister_chrdev(major_number, DEVICE_NAME);
    printk(KERN_INFO "my_device: unregistered\n");
}

module_init(my_device_init);
module_exit(my_device_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Example Device Driver with mmap");
