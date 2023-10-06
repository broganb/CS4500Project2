NAME OF PROJECT:
================
Project2

MEMBERS: 
========
Jaylen McKinney, Brogan Bewley

STATEMENT:
==========
We have neither given nor received unauthorized assistance on this work.

VIRTUAL MACHINE (VM) INFORMATION:
=================================
NAME OF VIRTUAL MACHINE (VM): Centos7VM
USERNAME: bbewley
PASSWORD: IloveCS4500

Describe where the files can be found.
Documents/Project2
Each part of the project has a subdirectory folder in the project 2 folder named Part1, Part2, Part3, and Part4.

Describe each file and the purpose it serves.
Hello.c: A helloworld module that prints out “Hello World!” when loaded and “Goodbye World!” when removed.
Print_self.c: A module that prints out the current processes name, ID, and state. Also prints out the parent processes name, ID, and state up until the init process.
Print_other.c: A module functionally similar to the one above, printing out info on a process and all its parent processes till init, but allows for users to input a process id.


Provide any special instructions to access or run your program.
Make sure you are in the right subdirectory. (Documents/Project2/Part1, Part2, or Part3)
To load the module, use “sudo insmod” with the name of the file you want to load. if you are running Part3, make sure to input a process id to check like "chosen_pid=123" for excample. Using pgrep bash before hand will give you one to use
i.e. sudo insmod print_self.ko OR sudo insmode print_other.ko chosen_pid=23234
Use dmesg -T | tail to see the output
Use lsmod to see that the module was loaded.
To remove the module, use “sudo rmmod” with the name of the file you want to remove.
i.e. sudo rmmod print_self

ROOT PASSWORD: IloveCS4500
==============
DESCRIPTION AND REMEDIATION:
============================
The purpose of this project was to get familiar with programming Linux kernel modules by figuring out how processes are managed.
Part 1: This part was not too difficult. We typed out the code to avoid encoding issues and then wrote the Makefile. We did have some issues with the Makefile for a bit due to missing an “s” in the word “modules,” but that was quickly fixed. We also had to change the names of the init_module and cleanup_module functions because those functions were already defined in another library.

Part 2 (Jaylen): This part took awhile to figure out. The website provided was immensely helpful. Printing out the current processes name, ID, and state did not take too long. However, printing out the state of all parent processes until init took a little longer to figure out. At first, I wanted to make a function that created a switch case, where each case corresponded to a state ID. I later decided to make a 2d array to hold the different messages that matched the state ID and printed out the state messages using that.

Part 3 (Brogan):  Using Jaylen's part 2 code as a basis and the links provided, I was able to figure out how to add input to the modules fairly easily. Issues did occur where the task would not parse correctly and the parent processes were not printing out but adding an initial task as the chosen one then tracking the rest with a different struct fixed this issue.
