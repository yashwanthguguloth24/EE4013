#include<stdio.h>
#include <unistd.h>
#include<pthread.h>
#include<sys/time.h>

/*
The following code represents the proof of multithreading by calling individual functions simulatenously using threads

to run on terminal use-
gcc -o multithread_proof multithread_proof.c -pthread
*/

// using sys/time.h library to compute the time 
suseconds_t t1,t2,t3; //variables

int x = 0; // global variable


void * foo()
{
    printf("*********** Thread1 execution started ************ \n");
    int y = 0;
    x = x + 1;
    y = y + 1;
    // computing current time
    struct timeval current_time;
    gettimeofday(&current_time,NULL);
    t2 = current_time.tv_usec;
    printf("Time elapsed from start of program to enter foo of thread1 %ld us\n",(t2-t1));// time in micro seconds
    struct timeval current_time1;
    gettimeofday(&current_time1,NULL);
    t3 = current_time1.tv_usec;
    printf("Time elapsed from start of program to end of foo of thread1 %ld us\n",(t3-t1)); // time in micro seconds
    printf("*********** Thread1 execution ended ************ \n");
}

void * foo1()
{
    printf("*********** Thread2 execution started ************\n");
    int y = 0; 
    x = x + 1;
    y = y + 1;
    // computing current time
    struct timeval current_time;
    gettimeofday(&current_time,NULL);
    t2 = current_time.tv_usec;
    printf("Time elapsed from start of program to enter foo1 of thread2 %ld us\n",(t2-t1)); // time in micro seconds
    struct timeval current_time1;
    gettimeofday(&current_time1,NULL);
    t3 = current_time1.tv_usec;
    printf("Time elapsed from start of program to end of foo1 of thread2 %ld us\n",(t3-t1));
    printf("*********** Thread2 execution ended ************  \n");
}


int main()
{
    pthread_t T1,T2;
    // computing current time
    struct timeval current_time0;
    gettimeofday(&current_time0,NULL);
    t1 = current_time0.tv_usec;
    // creating threads T1,T2 and calling the function foo()
    pthread_create(&T1,NULL,foo,NULL); // Thread T1
    pthread_create(&T2,NULL,foo1,NULL); // Thread T2
    // Waiting for both threads to finish execution
    pthread_join(T1, NULL); // waiting for T1 to finish execution
    pthread_join(T2, NULL); // waiting for T2 to finish execution
    printf("value of x is %d\n",x);
    return 0;
}