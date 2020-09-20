#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/device.h>

extern struct bus_type my_bus_type;


int my_probe(struct device *dev)
{
    printk("--------^_^ %s------------\n",__FUNCTION__);

    return 0;
}

struct device my_dev = {
    .init_name = "my_dev",  //与驱动一致
    .bus = &my_bus_type, //驱动属于哪条总线，来自于外部的，需要: EXPORT_SYSBOL
};
static int __init mydevice_init(void)
{
    printk("--------^_^ %s------------\n",__FUNCTION__);
    return device_register(&my_dev);
}
static void __exit mydevice_exit(void)
{
    printk("--------^_^ %s------------\n",__FUNCTION__);
    device_unregister(&my_dev);
}

module_init(mydevice_init);
module_exit(mydevice_exit);
MODULE_LICENSE("GPL");