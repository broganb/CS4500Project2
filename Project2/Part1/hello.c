#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

int load_module(void)
{
    printk(KERN_INFO "Hello world!\n");
    pr_info("Hello World!\n");
    return 0;
}

void exit_module(void)
{
    printk(KERN_INFO "Goodbye world!\n");
    pr_info("Goodbye World!\n");
}

module_init(load_module);
module_exit(exit_module);

MODULE_LICENSE("GPL");