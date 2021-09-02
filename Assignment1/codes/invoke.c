#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/*
The following code, creates two processes using fork() library with 1 parent and 1 child process
fork()
   - fork is a function in C/C++ that clones a process, spawning an identical copy
   - fork is an operation whereby a process creates a copy of itself
   - fork is the primary method of process creation on Unix-like operating systems.

*/

int main()
{
  
    // child process has pid_t = 0,this how we differentiate between child and parent process
    pid_t pid = fork(); // creating a parent process and a child proccess using fork
    if(pid == 0)
    {
        printf("**********************************\n");
        printf("Executing Process P1.... \n");
        // this excetutes for child process
        system("./multithreading"); // invoking the multithreaded code given
        printf("Finished executing process P1. \n");
        printf("**********************************\n");
        exit(0); // terminates the child process
    }
    else
    {
        // this executes for parent process
        waitpid(pid,NULL,0); // allows parent process to wait for child process to execute
        printf("Executing Process P2.... \n");
        system("./multithreading"); // invoking the multithreaded code segment
        printf("Finished executing process P2.\n");
        printf("**********************************\n");
    }
    return 0;
}