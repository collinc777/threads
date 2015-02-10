#include <stdlib.h> //malloc
#include <stdio.h>

#define SIZE_OF_STACK 131072

typedef void (*f)(void *arg);

typedef struct stk
{
	char data[SIZE_OF_STACK];
} stack;

struct thread{
	f function;	
	stack *thread_stack;
	//pionter to the threads stack
	//fields storing the current stack and base pointer when the thread yields.
	//futher storage to preserve teh thread's state. 
};

struct runQ{
	struct thread *current_thread;
	struct thread *next_thread;
};

/* allocates a struct thread
	a new stack for the thread and sets default values
	has a initial stack pointer which must be divisible by 8*/
struct thread *thread_create(void (*f)(void *arg), void *arg){	
	//thread created. now need to initialize and malloc more mem

	struct thread *t1;
	t1 = (struct thread *) malloc(sizeof(struct thread));
	//create should work now lets initialize the struct
	t1->function = f;
	// if(t1->function){
	// 	printf("function has a value that is not null\n");
	// 	printf("%lu\n", sizeof(t1->function));
	// 	printf("%lu\n", (long unsigned int)t1->function);

	// }else{
	// 	printf("Fucntion DID NOT WORK\n");
	// }
	//can we be asured that it will always be divisible by 8? the world may never know
	t1->thread_stack = (stack *) malloc(sizeof(stack));
	// if(t1->thread_stack){
	// 	printf("thread stack is pointing to something that is not null\n");
	// 	printf("%lu\n", sizeof(t1->thread_stack->data));
	// 	printf("%lu\n", (long unsigned int)t1->thread_stack);
	// 	int isdivby8 = ((long unsigned int)t1->thread_stack % 8) == 0;
	// 	printf("is div by 8 %d\n", isdivby8);
	// }else{
	// 	printf("THREAD DID NOT MALLOC\n");
	// }
	

};
/*
add struct thread to end of run queue
uses round robing scheduler?
maintain ring of those structures
	always have a next field which points to the next thread to be scheduled
	static variable called current_thread points to current thread thatt is running. 
  */

void thread_add_runqueue(struct thread *t){
	struct runQ *rQ;
	rQ = (struct runQ*)malloc(sizeof(struct runQ));
	rQ->current_thread = t;
	rQ->next_thread = t;
	// if(rQ){
	// 	printf("RQ is not null\n");
	// 	printf("thread t poins to: %lu\n", (long unsigned int)t);
	// 	printf("current thread points to: %lu\n", (long unsigned int) rQ->current_thread);
	// 	printf("next thread points to %lu\n", (long unsigned int) rQ->next_thread);
	// }else{
	// 	printf("NULLAF\n");
	// }

	
};
/*
suspends current thread by saving its context.
calls cheduler and the dispatcher.
if thread is resumed later. it continues eecution with next instruction
immidealty following prior yield call. */
void thread_yield(void){

};
void dispatch(void){};
void schedule(void){};
void thread_exit(void){};
void thread_start_threading(void){};