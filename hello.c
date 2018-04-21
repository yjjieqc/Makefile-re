#include <linux/init.h>   
#include <linux/module.h>   
  
MODULE_LICENSE("Dual BSD/GPL");  
  
static int hello_init(void)  
{  
    printk(KERN_INFO "Hello, world!\n");  
    return 0;  
}  
  
static void hello_exit()  
{  
    printk(KERN_INFO "Hello, exit!\n");  
}  
  
module_init(hello_init);  
module_exit(hello_exit);
