#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Stack.h"
#include "Queue.h"

struct QueueType {
	Stack enqueue_stack; 
	Stack dequeue_stack; 
};

enum ERROR_CODE { Memorylack, EmptyQueue, DeallocatedQueue };

static void HandleError(enum ERROR_CODE code);

// O(1) 
Queue InitializeQueue() {
	// allocate Queue 
	Queue init_queue = malloc(sizeof(*init_queue));
	if (init_queue == NULL) {
		HandleError(Memorylack);
	}

	// allocate Queue member
	init_queue->enqueue_stack = InitStack(); 
	init_queue->dequeue_stack = InitStack();

	// return
	return init_queue; 
}

// O(1) 
bool IsEmptyQueue(Queue current_queue) {
	// handle error 
	if (current_queue == NULL) {
		HandleError(DeallocatedQueue);
	}

	// check two stack 
	return (IsEmptyStack(current_queue->dequeue_stack) && IsEmptyStack(current_queue->enqueue_stack));
}

// O(1) , amortized running time  
ItemType GetFrontItem(Queue current_queue) {
	// handle error ( empty queue check ) 
	if (current_queue == NULL) {
		HandleError(DeallocatedQueue);
	}
	if (IsEmptyStack(current_queue->dequeue_stack) && IsEmptyStack(current_queue->enqueue_stack)) {
		HandleError(EmptyQueue);
	}

	// check dequeue_stack
	if (IsEmptyStack(current_queue->dequeue_stack)) {
		// empty --> pop enqueue_stack and push dequeue_stack all of element , and return top of dequeue_stack  
		while (!IsEmptyStack(current_queue->enqueue_stack)) {
			PushStack(current_queue->dequeue_stack, PopStack(current_queue->enqueue_stack));
		}
	}

	// return top element of dequeue_stack 
	return GetTopElementStack(current_queue->dequeue_stack);
}

// O(1) 
void EnQueue(Queue current_queue, const ItemType inserting_item) {
	// handle error 
	if (current_queue == NULL) {
		HandleError(DeallocatedQueue);
	}

	// push enqueue_stack 
	PushStack(current_queue->enqueue_stack, inserting_item);

	return; 
}

// O(1) , amortized running time  
ItemType DeQueue(Queue current_queue) {
	// handle error ( empty queue check ) 
	if (current_queue == NULL) {
		HandleError(DeallocatedQueue);
	}
	if (IsEmptyStack(current_queue->dequeue_stack) && IsEmptyStack(current_queue->enqueue_stack)) {
		HandleError(EmptyQueue);
	}

	// check dequeue_stack
	if (IsEmptyStack(current_queue->dequeue_stack)) {
		// empty --> pop enqueue_stack and push dequeue_stack all of element , and return top of dequeue_stack  
		while (!IsEmptyStack(current_queue->enqueue_stack)) {
			PushStack(current_queue->dequeue_stack, PopStack(current_queue->enqueue_stack));
		}
	}

	// pop dequeue_stack and return 
	return PopStack(current_queue->dequeue_stack);
}

// O(N) 
void RemoveQueue(Queue* removing_queue) {
	// handle error 
	if (*removing_queue == NULL) {
		HandleError(DeallocatedQueue);
	}

	// remove two stack 
	RemoveStack(&((*removing_queue)->enqueue_stack));
	RemoveStack(&((*removing_queue)->dequeue_stack));

	// store NULL and deallocate for dangling pointer 
	Queue deallocating_queue = *removing_queue;
	*removing_queue = NULL;
	free(deallocating_queue);

	return; 
}


// O(1) 
static void HandleError(enum ERROR_CODE code) {
	switch (code){

	case Memorylack: printf("ERROR : MEMORY IS NOT ENOUGH\n\n"); break;
	case EmptyQueue: printf("ERROR : QUEUE IS  EMPTY\n\n"); break;
	case DeallocatedQueue: printf("ERROR : QUEUE IS DEALLOCATED\n\n"); break;

	default: printf("ERROR : ERROR CODE EXCEPTION\n\n"); break;
	}

	exit(0);
}

