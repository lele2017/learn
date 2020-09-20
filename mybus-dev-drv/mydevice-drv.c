#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/device.h>

extern struct bus_type my_bus_type;


int my_probe(struct device *dev)
{
    printk("--------^_^ %s------------\n",__FUNCTION__);

    //如果是实际应用的驱动，这里会做很多硬件初始化操作

    return 0;
}

struct device_driver my_driver = {
    .name = "my_dev",
    .bus = &my_bus_type, //驱动属于哪条总线，来自于外部的，需要: EXPORT_SYSBOL
    .probe = my_probe,
};
static int __init mydriver_init(void)
{
    printk("--------^_^ %s------------\n",__FUNCTION__);
    return driver_register(&my_driver);
}
static void __exit mydriver_exit(void)
{
    printk("--------^_^ %s------------\n",__FUNCTION__);
    driver_unregister(&my_driver);
}

module_init(mydriver_init);
module_exit(mydriver_exit);
MODULE_LICENSE("GPL");