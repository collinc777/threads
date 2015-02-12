#include <stdlib.h> //malloc
#include <stdio.h>

#define SIZE_OF_STACK 131072

//TODOS: make stack and base pointer point to top of stack cause they dont...
//todo:  add setjmp and longjmp to shit. 

typedef void (*f)(void *arg);

typedef struct stk
{
	char data[SIZE_OF_STACK];
} stack;

struct thread{
	f function;	
	stack *base_ptr;
	stack *thread_stack;
	struct thread *next;
	//pionter to the threads stack
	//fields storing the current stack and base pointer when the thread yields.
	//futher storage to preserve teh thread's state. 
};

static struct thread *current_thread;
static struct thread *last_thread;


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
		//printf("Thread is uninitialized\n");
		current_thread = t;
		last_thread = t;
		last_thread->next = current_thread;
		//printf("curent thread %lu == %lu\n", (long unsigned int) current_thread, (long unsigned int) t);
	}else{
		//current thread already exists
		last_thread->next = t;
		last_thread = t;
		last_thread->next = current_thread;
	}

	
};
/*
sspends current thread by saving context/ what is context?
save stack state..
calls scheduler which is inherently called by the dispatcher. 
*/
void thread_yield(void){
	if(current_thread == 0){
		printf("error: cannot call yield on null thread\n");
	}else{
		//current thread exists .
		printf("yaya we get here\n");
		struct thread *temp = current_thread;
		void schedule(void);
		void dispatch(void);
	}

};

/*
restores state of scheduled thread.
if never run
	set the initial stack and base pointer .*/
void dispatch(void){};
/*decides which thread to run next.*/
void schedule(void){
	if(current_thread->next == NULL){
		printf("should never be the case. if we get here WE MESSED UP\n");
	}else{
		last_thread = last_thread->next;
		current_thread = current_thread->next;
	}
};
/*
removes calling thread from run queue
frees stack and struct thread
sets current to next and calls dispatch*/
void thread_exit(void){
	last_thread->next = current_thread->next;
	struct thread *tmp = current_thread;
	current_thread = current_thread->next;
    tmp->next = NULL;
    //now to free up tmp
    free(tmp->thread_stack);
    free(tmp);
    void dispatch(void);
};
void thread_start_threading(void){};