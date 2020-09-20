#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/device.h>

int my_match(struct device * dev,struct device_driver *drv)
{
    printk("--------^_^ %s------------\n",__FUNCTION__);
    
    //return !strncmp(dev->init_name,drv->name,strlen(drv->name)); //跟读注册代码发现，这样有问题
    return !strncmp(dev->kobj.name,drv->name,strlen(drv->name));

}


struct bus_type my_bus_type = {
    .name = "mybus",
    .match = my_match,
};

EXPORT_SYMBOL(my_bus_type);

static int __init mybus_init(void)
{
    printk("--------^_^ %s------------\n",__FUNCTION__);
    return bus_register(&my_bus_type);    
}
static void __exit mybus_exit(void)
{
    printk("--------^_^ %s------------\n",__FUNCTION__);
    bus_unregister(&my_bus_type);
}

module_init(mybus_init);
module_exit(mybus_exit);
MODULE_LICENSE("GPL");