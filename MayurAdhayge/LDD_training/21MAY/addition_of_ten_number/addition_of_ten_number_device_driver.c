#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/mm.h>
#include <linux/io.h>
#include <linux/uaccess.h>
#include <linux/slab.h>
#include <linux/device.h>
#include <linux/ctype.h>
#define DEVICE_NAME "mmap_addition_10"
#define DEVICE_MEMORY_SIZE 4096  // 4KB




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

ssize_t device_write(struct file *filp, const char *buf, size_t len, loff_t *offset) {
int result;
char ans[10];
int number[10];
char oprator[10];
char tmp_num[5]="\0";
int count =0;
int tmp_indx=0;

int len_mem=strlen(device_memory);

for (int i=0;i<len_mem;i++)
{
   if(isdigit(device_memory[i]))
        {
          tmp_num[tmp_indx]=device_memory[i];
          tmp_indx++;
        }
    else
        {
        if (tmp_indx > 0)
        {
           tmp_num[tmp_indx]='\0';
           printk(KERN_INFO "%s ",tmp_num);
           //sprintf(number[count],"%d",tmp_num);
           kstrtoint(tmp_num,10,&number[count]);
           oprator[count]=device_memory[i];
           strcpy(tmp_num,"\0");
           count++;
           tmp_indx=0;
           memset(tmp_num,0,sizeof(tmp_num));
        }
}
}

kstrtoint(tmp_num,10,&number[count]);

result=number[0];

for(int j=1;j<(count+1);j++)
{
        switch(oprator[j-1])
        {
        case '+':
                 result=result+number[j];
                 break;
        case '-':
                 result=result-number[j];
                 break;
        default:
                break;
        }
}



printk(KERN_INFO "sum is %d",result);

sprintf(ans, "%d", result);

strcpy(device_memory, ans);


//printk(KERN_INFO "USER DATA %s",device_memory);
//strcpy(device_memory,"data from kernel");
return 0;
}

static int my_device_mmap(struct file *filp, struct vm_area_struct *vma) {
    unsigned long offset = vma->vm_pgoff << PAGE_SHIFT;
    unsigned long physical_address = virt_to_phys(device_memory) + offset;
    unsigned long size = vma->vm_end - vma->vm_start;

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
    .write = device_write,
    .release = my_device_release,
    .mmap = my_device_mmap,
};

static int __init my_device_init(void) {

    

    major_number = register_chrdev(0, DEVICE_NAME, &my_device_fops);
    
  
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
