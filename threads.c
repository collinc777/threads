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
	struct thread *next;
	//pionter to the threads stack
	//fields storing the current stack and base pointer when the thread yields.
	//futher storage to preserve teh thread's state. 
};

static struct thread *current_thread;


/* allocates a struct thread
	a new stack for the thread and sets default values
	has a initial stack pointer which must be divisible by 8*/
struct thread *thread_create(void (*f)(void *arg), void *arg){	
	//thread created. now need to initialize and malloc more mem


	struct thread *t1;
	t1 = (struct thread *) malloc(sizeof(struct thread));
	//create should work now lets initialize the struct
	t1->function = f;
	t1->next = NULL;
	t1->thread_stack = (stack *) malloc(sizeof(stack));
	// t1->thread_stack = (stack *) malloc(sizeof(stack));
	// if (current_thread == 0)	
	// {
	// 	printf("Thread is uninitialized\n");
	// 	current_thread = t1;
	// 	printf("curent thread %lu == %lu\n", (long unsigned int) current_thread, (long unsigned int) t1);
	// }
	// if(t1->function){
	// 	printf("function has a value that is not null\n");
	// 	printf("%lu\n", sizeof(t1->function));
	// 	printf("%lu\n", (long unsigned int)t1->function);

	// }else{
	// 	printf("Fucntion DID NOT WORK\n");
	// }
	//can we be asured that it will always be divisible by 8? the world may never know
	
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
	if (current_thread == 0)	
	{
		printf("Thread is uninitialized\n");
		current_thread = t;
		printf("curent thread %lu == %lu\n", (long unsigned int) current_thread, (long unsigned int) t);
	}else{
		//current thread already exists
		struct thread *temp;
		temp = current_thread;
		while(temp->next){
			printf("temps value: %lu\n", (long unsigned int )temp);
			temp = temp->next;
		}
		temp->next = t;
	}

	
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