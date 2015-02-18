#include <stdio.h>
#include "threads.h"


void f3(void *arg)
{
    int i = 20;
    for(i = 20; i < 30; i++) {
        printf("thread 3: %d\n", i);
        thread_yield();
    }
    printf("do i even get to thread 3\n");
}

void f2(void *arg)
{
    int i = 10;
    for(i = 10; i < 20;i++) {
        printf("thread 2: %d\n",i);
        thread_yield();
    }
    printf("what happens at end of thread 2\n");
}

void f1(void *arg)
{
    int i = 0;
    struct thread *t2 = thread_create(f2, NULL);
    thread_add_runqueue(t2);
    struct thread *t3 = thread_create(f3, NULL);
    thread_add_runqueue(t3);
    for(i = 0;i  < 10; i ++){
        printf("thread 1: %d\n", i);
        thread_yield();
        
    }
    printf("what happens at end of thread1\n");
}

int main(int argc, char **argv)
{
    struct thread *t1 = thread_create(f1, NULL);
    thread_add_runqueue(t1);
    thread_start_threading();
    printf("\nexited\n");
    return 0;
}