#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/platform_device.h>
#include <linux/types.h>
#include <linux/version.h>
#if LINUX_VERSION_CODE > KERNEL_VERSION(3, 3, 0)
	#include <asm/switch_to.h>
#else
	#include <asm/system.h>
#endif
struct haoge_data
{
    char a[1024];
};


static int haoge_probe(struct platform_device *dev)
{
    struct haoge_data * p =(dev->dev).platform_data;



    printk(KERN_ALERT "%s",p->a);

    return 0;
}


static struct platform_driver haoge_driver = {
    .probe        = haoge_probe,

    .driver        = {
        .name        = "haoge",
        .owner        = THIS_MODULE,
    },
};

static int __init haoge_init(void)
{

    return platform_driver_register(&haoge_driver);
}

static void __exit haoge_exit(void)
{


    platform_driver_unregister(&haoge_driver);
}

module_init(haoge_init);
module_exit(haoge_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("HaoGe");