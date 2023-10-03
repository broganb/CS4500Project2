#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/module.h>

int print_self(void)
{
    struct task_struct *task;

    printk(KERN_INFO "Current process ID = %d\n", current->pid);
    printk(KERN_INFO "Current state is ");
    switch(current->state)
    {
        case 0:
            printk("TASK_RUNNING");
            break;
        case 1:
            printk("TASK_INTERRUPTIBLE");
            break;
        case 2:
            printk("TASK_UNINTERRUPTIBLE");
            break;
        case 4:
            printk("TASK_STOPPED");
            break;
        case 8:
            printk("TASK_TRACED");
            break;
        case 16:
            printk("EXIT_ZOMBIE");
            break;
        case 32:
            printk("EXIT_DEAD");
            break;
        case 64:
            printk("TASK_NONINTERACTIVE");
            break;
        case -1:
            printk("unrunable");
            break;
        default:
            printk("stopped");
            break;
    }

    printk(KERN_INFO "Name = %s\n", current->comm);

    printk(KERN_INFO "Parent process until init:\n");
    for(task = current; task != &init_task; task = task->parent)
    {
        printk(KERN_INFO "%s [%d]\n", task->comm, task->pid);
    }

    return 0;
}

void exit_module(void)
{
    printk(KERN_INFO "Cleaning up.\n");
}


module_init(print_self);
module_exit(exit_module);

MODULE_LICENSE("GPL");