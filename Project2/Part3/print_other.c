#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/stat.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

//pid to be set when running module
static int chosen_pid = 1;
module_param(chosen_pid, int, 0);

// Function: print_other
// Takes in a process_id and prints name, id, and state for
// chosend process and parent processes until init.
int print_other(void)
{
    struct task_struct *task;

    task = pid_task(find_vpid(chosen_pid), PIDTYPE_PID);

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

    printk(KERN_INFO "Chosen PID: %d\n", chosen_pid);

    if(task == NULL){
        printk(KERN_INFO "No process with that pid exists\n");
    }
    else{
        
        printk(KERN_INFO "Current state is %s\n", state_id[task->state]);

        // Uses the chosen to print out the PID and
        // the name of the process
        printk(KERN_INFO "Current process ID = %d\n", task->pid);
        printk(KERN_INFO "Name = %s\n", task->comm);

        // For loop to print out the parent processes.
        // Loops until task = init_task.
        printk(KERN_INFO "Parent process until init:\n");
        for(task = task->parent; task != &init_task; task = task->parent)
        {
            printk(KERN_INFO "%s [%d] %s\n", task->comm, task->pid, state_id[task->state]);
        }
    }
   

    return 0;
}

void exit_module(void)
{
    printk(KERN_INFO "Cleaning up.\n");
}


module_init(print_other);
module_exit(exit_module);

MODULE_LICENSE("GPL");