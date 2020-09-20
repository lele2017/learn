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
}s2;

struct platform_device haoge2_device ={
    .name= "haoge",
    .id = 2,
    .dev = {
            .platform_data = &s2,
     },
};

static int __init haoge_init(void)
{
    sprintf(s2.a,"haoge very handsone!\n");

    platform_device_register(&haoge2_device);

    return 0;
}

static void __exit haoge_exit(void)
{

    platform_device_unregister(&haoge2_device);
}

module_init(haoge_init);
module_exit(haoge_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("HaoGe");