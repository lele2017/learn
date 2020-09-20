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
}s;

struct platform_device haoge_device ={
    .name= "haoge",
    .id=1,
    .dev = {
            .platform_data = &s,
     },
};

static int __init haoge_init(void)
{
    sprintf(s.a,"haogeverygood!\n");

    platform_device_register(&haoge_device);

    return 0;
}

static void __exit haoge_exit(void)
{

    platform_device_unregister(&haoge_device);
}

module_init(haoge_init);
module_exit(haoge_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("HaoGe");