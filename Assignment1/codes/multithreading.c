#include<stdio.h>
#include <unistd.h>
#include<pthread.h>

/*
The following code represents the given multithreaded code segment
Multiple threads are created using pthread library in C.

to run on terminal use-
gcc -o multithreading multithreading.c -pthread
*/



int x = 0; // global variable

// create a lock
pthread_mutex_t L1; // lock L1

void * foo()
{
    int y = 0;
    // acquire lock
    pthread_mutex_lock(&L1); // locks the function so that other threads doesnt execute 
    x = x + 1;
    y = y + 1;
    // release lock
    pthread_mutex_unlock(&L1); // uncloks the function so that other threads can execute
    printf("value of y is %d\n",y);

}


int main()
{
    pthread_t T1,T2;
    // creating threads T1,T2 and calling the function foo()
    pthread_create(&T1,NULL,foo,NULL); // Thread T2
    pthread_create(&T2,NULL,foo,NULL); // Thread T2
    // Waiting for both threads to finish execution
    pthread_join(T1, NULL); // waiting for T1 to finish execution
    pthread_join(T2, NULL); // waiting for T2 to finish execution
    printf("value of x is %d\n",x);
    return 0;
}