#include<linux/module.h>
#include<linux/init.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/uaccess.h>
#define DEVICE_NAME  "simple_driver"
#define BUFF_SIZE 1024
#define MIN(a,b) ( (a>b) ? (b) : (a) )
//--------------------karnel variable section---------------------//
char *kernBuffer; 
//-----------------end of the kernel variable section --------------//


//----------------variable declaration for the driver-----------------------//

static dev_t Device_num; // this variable store the 32 bit unsigned unique device number
static struct cdev myCharDriver; //this is the datastructer of vfs which is use to store all information regarding your driver
static struct file_operations my_fops; //this is the declaretion of the file operation struct

//------------------------end of variable declaration for the driver---------------//




 
 
 
//-------------------------device driver oprational function open close read write-------------------------//


//open function of the driver
static int Device_Open(struct inode *inode,struct file *file)
{
printk(KERN_INFO "device open ");
return 0;
}
//end of open function of driver


//read function of the driver
static ssize_t Device_Read(struct file *file,char __user *buffer, size_t len, loff_t *offset)
{
  int dataRead=0; //variable dataRead is use to store the data we read 
  dataRead=MIN(BUFF_SIZE,len); // here we taking the data of size len untill the size of len is less than BUFF_SIZE otherwise take BUFF_SIZ
  if(copy_to_user((char* __user) buffer,kernBuffer,strlen(kernBuffer))) //here we checking we get bytes written data
  {
    return -EFAULT; // not copy error msg
  }
  return dataRead;// how many bytes written

}
//end of the read function


//write function of the driver
 ssize_t device_write(struct file *file,const char __user *buffer, size_t len, loff_t *offset)
{

  int dataWrite=0; //variable dataRead is use to store the data we read 
  dataWrite=MIN(BUFF_SIZE,len); // here we taking the data of size len untill the size of len is less than BUFF_SIZE otherwise take BUFF_S
  if(copy_from_user(kernBuffer,(char* __user) buffer,dataWrite)) //here we checking we get bytes written data
  {
    return -EFAULT; // not copy error msg
  }
  return dataWrite;// how many bytes written

}
//end of the write function

//close function of the driver
static int Device_Close(struct inode *filp, struct file *file)
{
printk(KERN_INFO "device close ");
return 0;
}
//end of the close function


//-------------------------End of the device driver oprational function open close read write-------------------------//
 
 
 
 
 
 //------------------driver opration  defineing in the file opration struct------------------------//

static struct file_operations my_fops={    //this is defination of file_operation

  .owner = THIS_MODULE, //here we binding the struct file opration with this module
  .open = Device_Open, //here we binding the open system call of file to karnel function Driver_Open
  .write = device_write, //here we binding the write system call of file to karnel function Driver_write
  .read = Device_Read, //here we binding the read system call of file to karnel function Driver_read
  .release = Device_Close, //here we binding the realese system call of file to karnel function Driver_close
};

//------------------end of driver opration  defineing in the file opration struct------------------------//
 
 
 
 
 
 
 
 
//-----------------------entry point of the driver. initialization and termination function of driver-------------------------//



//initialization function for driver 
int __init device_init(void)
{
  int isRegister=-1; //this variable is use to check wheather your drviver successfully register with vfs or not 

  alloc_chrdev_region(&Device_num,0,1,"simple_driver"); //alloc_chrdev_region() API is use to get the unique device number and register the space in kernel 

  if (Device_num < 0) //if device number not allow then this if runs  
  {
    unregister_chrdev_region(Device_num,1); //unregister the halfly accuare space
    return -EFAULT;  //exit with the failer flag
  }

  cdev_init(&myCharDriver,&my_fops); //cdev() API is use to initialize the cdev struct where after initialization cdev.ops start pointing       tofile_oprations fops
  myCharDriver.owner=THIS_MODULE;  // here we giving the ownership  of cdev to this modules 
  
  isRegister=cdev_add(&myCharDriver,Device_num,1); //here we using the cdev_add() API to register your charecter driver  to vfs 

  if(!(isRegister==0)) // checking is registration with vfs done successfull if not then unitialize the resorce and exit 
  {
    cdev_del(&myCharDriver); // deleting the entry of this char device with vfs 
    unregister_chrdev_region(Device_num,1);  //unregister the space register by the device number
    return -EFAULT; //exit with the failer flag
  } 
  kernBuffer= (char *) kmalloc(BUFF_SIZE,GFP_KERNEL);
  if ( kernBuffer==NULL)
  {
    kfree(kernBuffer);
    return -EFAULT;
  }
  return 0; //success return if all initialization and registereration happend successfully
}
//end of the initialization function for driver





//termination  function for driver
void __exit device_exit(void)
{
 cdev_del(&myCharDriver); // deleting the entry of this char device with vfs 
 unregister_chrdev_region(Device_num,1);  //unregister the space register by the device number 
 kfree(kernBuffer); //the deallocate the memory allocation
 //return nothing 
} 


//--------------------------------end of the entry point of the driver initialization and termination function of driver---------------//






//-----------------------------Module registration section--------------------------------//

module_init(device_init);
module_exit(device_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MAYUR ADHAYGE");
MODULE_DESCRIPTION("This is the simple demostration of the  charector driver to show simple data transfer between the user space and kernel space");

//----------------------------End of Module registration section-------------------------------//

