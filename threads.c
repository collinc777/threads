#include <stdlib.h> //malloc

#define SIZE_OF_STACK 131072

typedef void (*f)(void *arg);

struct stack
{
	char data[SIZE_OF_STACK];
};

struct thread{
	f function;	
	stack thread_stack;
	unsigned int *stack_ptr;
	//pionter to the threads stack
	//fields storing the current stack and base pointer when the thread yields.
	//futher storage to preserve teh thread's state. 
};

int main(){};
/* allocates a struct thread
	a new stack for the thread and sets default values
	has a initial stack pointer which must be divisible by 8*/
struct thread *thread_create(void (*f)(void *arg), void *arg){	
	thread t1;
	t1.function = f;

};

void thread_add_runqueue(struct thread *t){};
void thread_yield(void){};
void dispatch(void){};
void schedule(void){};
void thread_exit(void){};
void thread_start_threading(void){};