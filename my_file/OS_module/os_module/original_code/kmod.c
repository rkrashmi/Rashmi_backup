/** System Includes **/
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <linux/device.h>
#include <linux/slab.h>

MODULE_LICENSE("Dual BSD/GPL");

/** contents **/
#define FIRST_MINOR 0
#define NR_DEVS 1   //Number of device numbers

//Functions Declarations for syscall definition
int myOpen(struct inode *inode, struct file *filep);
int myRelease(struct inode *in, struct file *fp);

//Initialization routines
static int myInit(void);
static void myExit(void);

struct file_operations fops={
	.owner = THIS_MODULE,
	.open = myOpen,
	.release = myRelease
};

/*Global variables */
char *devname; //contains device name
int majNo;
static dev_t mydev; //encodes major number and minor number
struct cdev *my_cdev; //holds character device driver descriptor

/* To accept input from the command line */
module_param(devname, charp, 0000);

//class and device structures
static struct class *mychar_class;
static struct device *mychar_device;

/*
*myOpen:open function of the pseudo driver
*
*/
int myOpen(struct inode *inode, struct file *filep)
{
	printk(KERN_INFO "open successful\n");
	return 0;
}

/*
*myRelease : class function of the pseudo driver
*
*/
int myRelease(struct inode *in,struct file *fp)
{
	printk(KERN_INFO "File released\n");
	return 0;
}

static int __init myInit(void)
{
	int ret = -ENODEV;
	int status;
	printk(KERN_INFO "Initializing Character Device\n");

	//Allocating device number
	status = alloc_chrdev_region(&mydev, FIRST_MINOR, NR_DEVS, devname);
	if(status < 0)
	{
		printk(KERN_NOTICE "Device numbers allocation failed: %d\n",status);
		goto err;
	}
	printk(KERN_INFO "major number allocated :%d\n",MAJOR(mydev));
	my_cdev = cdev_alloc();
	if(my_cdev == NULL)
	{
		printk(KERN_ERR "cdev_alloc failed");
		goto err_cdev_alloc;
	}
	cdev_init(my_cdev, &fops);
	my_cdev->owner = THIS_MODULE;

	status = cdev_add(my_cdev, mydev, NR_DEVS);
	if(status)
	{
		printk(KERN_ERR "cdev_add failed");
		goto err_cdev_add;
	}

	//create class and entry in sysfs

	mychar_class = class_create( THIS_MODULE, devname);
	if(IS_ERR(mychar_class))
	{
		printk(KERN_ERR "class_crete failed");
		goto err_class_create;
	}

	//create mychar_device in sysfs and add entry in /dev

	mychar_device = device_create(mychar_class, NULL, mydev, NULL, devname);
	if(IS_ERR(mychar_device))
	{
		printk(KERN_ERR "device_create failed");
		goto err_device_create;
	}

	return 0;

	err_device_create:
		class_destroy(mychar_class);

	err_class_create:
		cdev_del(my_cdev);

	err_cdev_add:
		kfree(my_cdev);
	
	err_cdev_alloc:
		unregister_chrdev_region(mydev, NR_DEVS);

	err:
		return ret;

}

/*
*myExit :cleanup function to the kernel module
*
*/

static void myExit(void)
{
	printk(KERN_INFO "exiting the character driver");
	device_destroy(mychar_class, mydev);
	class_destroy(mychar_class);
	cdev_del(my_cdev);
	unregister_chrdev_region(mydev, NR_DEVS);
	return ;
}

module_init (myInit);
module_exit(myExit);
