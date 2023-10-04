#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/module.h>

// Function: print_self
// Prints out the process ID, and state of the current
// process and parent processes until init.
int print_self(void)
{
    struct task_struct *task;

    // 2D array to print out current state.
    char state_id[65][30] = {""};
        strcpy(state_id[0], "TASK_RUNNING");
        strcpy(state_id[1], "TASK_INTERRUPTIBLE");
        strcpy(state_id[2], "TASK_UNIINTERRUPTIBLE");
        strcpy(state_id[4], "TASK_STOPPED");
        strcpy(state_id[8], "TASK_TRACED");
        strcpy(state_id[16], "TASK_TRACED");
        strcpy(state_id[32], "EXIT_DEAD");
        strcpy(state_id[64], "TASK_NONINTERACTIVE");

        printk(KERN_INFO "Current state is %s\n", state_id[current->state]);



    // Switch case to print out message based on current state
    // switch(current->state)
    // {
    //     case 0:
    //         printk("TASK_RUNNING");
    //         break;
    //     case 1:
    //         printk("TASK_INTERRUPTIBLE");
    //         break;
    //     case 2:
    //         printk("TASK_UNINTERRUPTIBLE");
    //         break;
    //     case 4:
    //         printk("TASK_STOPPED");
    //         break;
    //     case 8:
    //         printk("TASK_TRACED");
    //         break;
    //     case 16:
    //         printk("EXIT_ZOMBIE");
    //         break;
    //     case 32:
    //         printk("EXIT_DEAD");
    //         break;
    //     case 64:
    //         printk("TASK_NONINTERACTIVE");
    //         break;
    //     case -1:
    //         printk("unrunable");
    //         break;
    //     default:
    //         printk("stopped");
    //         break;
    // }

    // Uses the current keyword to print out the PID and
    // the name of the process
    printk(KERN_INFO "Current process ID = %d\n", current->pid);
    printk(KERN_INFO "Name = %s\n", current->comm);

    // For loop to print out the parent processes.
    // Loops until task = init_task.
    printk(KERN_INFO "Parent process until init:\n");
    for(task = current; task != &init_task; task = task->parent)
    {
        printk(KERN_INFO "%s [%d] %s\n", task->comm, task->pid, state_id[task->state]);
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