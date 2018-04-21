#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>

static int __init demo_init(void)
{
    printk(KERN_INFO"demo_init:%s,%s,%d"__FILE__,__func__,__LINE__);
    return 0;
}

static void __exit demo_exit(void)
{
    printk(KERN_INFO"demo_exit:%s,%s,%d"__FILE__,__func__,__LINE__);
}

module_init(demo_init);
module_exit(demo_exit);

MODULE_LICENSE("GPL");
