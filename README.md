Simple shell Project
============
An end of semester project for students at Holberton School

## Learning Objectives
- Who designed and implemented the original Unix operating system
- Who wrote the first version of the UNIX shell
- Who invented the B programming language (the direct predecessor to the C programming language)
- Who is Ken Thompson
- How does a shell work
- What is a pid and a ppid
- How to manipulate the environment of the current process
- What is the difference between a function and a system call
- How to create processes
- What are the three prototypes of main
- How does the shell use the PATH to find the programs
- How to execute another program with the execve system call
- How to suspend the execution of a process until one of its children terminates
- What is EOF / “end-of-file”?

## Installation
- Clone the repo below
```
https://github.com/maleksal/simple_shell.git
```
- Compile with
```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
## Example Output
```
ubuntu@ubuntu$ ./hsh
$ pwd
/home/ubuntu/simple_shell
$ /bin/pwd
/home/ubuntu/simple_shell
$ ls -la
-rw-rw-r-- 1 vagrant vagrant  bytes <date> _helper.c
-rw-rw-r-- 1 vagrant vagrant   bytes <date> shell.h
```
## Authors
* [**Malek Salem**](https://github.com/maleksal)
* [**Khalil Kefi**](https://github.com/KhalilKefi)



