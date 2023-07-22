#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Stack.h"
#include "Queue.h"

struct StackType {
	Queue push_queue; 
	Queue pop_queue; 
};

enum ERROR_CODE { Memorylack, EmptyStack, DeallocatedStack };

static void HandleError(const enum ERROR_CODE code);

// O(1) 
Stack InitializeStack() {
	// allocate Stack 
	Stack init_stack = malloc(sizeof(*init_stack));
	if (init_stack == NULL) {
		HandleError(Memorylack);
	}

	// allocate member queue 
	init_stack->push_queue = InitQueue();
	init_stack->pop_queue = InitQueue();

	// return 
	return init_stack; 
}

// O(1)
void PushStack(Stack current_stack, const ItemType pushing_element) {
	// handle error 
	if (current_stack == NULL) {
		HandleError(DeallocatedStack);
	}
	// enqueue element to push_queue 
	EnQueue(current_stack->push_queue, pushing_element);

	return; 
}

// O(N) 
ItemType PopStack(Stack current_stack) {
	// handle error ( empty stack ) 
	if (current_stack == NULL) {
		HandleError(DeallocatedStack);
	}
	if (IsEmptyQueue(current_stack->push_queue)) {
		HandleError(EmptyStack);
	}

	// dequeue all element in push_queue and enqueue all element in pop_queue ( remember how many element : count) 
	int count = 0; 
	while (!IsEmptyQueue(current_stack->push_queue)) {
		EnQueue(current_stack->pop_queue, DeQueue(current_stack->push_queue));
		count++; 
	}

	// dequeue count - 1 element in pop_queue and enqueue count - 1 element in push_queue 
	for (int i = 0; i < count - 1; i++) {
		EnQueue(current_stack->push_queue, DeQueue(current_stack->pop_queue));
	}
 
	// dequeue last element in pop queue and return it
	return DeQueue(current_stack->pop_queue);
}

// O(N) 
ItemType GetTopElementStack(Stack current_stack) {
	// handle error ( empty stack ) 
	if (current_stack == NULL) {
		HandleError(DeallocatedStack);
	}
	if (IsEmptyQueue(current_stack->push_queue)) {
		HandleError(EmptyStack);
	}

	// dequeue all element in push_queue and enqueue all element in pop_queue ( remember how many element : count) 
	int count = 0;
	while (!IsEmptyQueue(current_stack->push_queue)) {
		EnQueue(current_stack->pop_queue, DeQueue(current_stack->push_queue));
		count++;
	}

	// dequeue count - 1 element in pop_queue and enqueue count - 1 element in push_queue 
	for (int i = 0; i < count - 1; i++) {
		EnQueue(current_stack->push_queue, DeQueue(current_stack->pop_queue));
	}

	// dequeue last element in pop queue and store(for return) and enqueue in push queue  
	ItemType get_item = DeQueue(current_stack->pop_queue);
	EnQueue(current_stack->push_queue, get_item);
	return get_item; 
}

// O(1) 
bool IsEmptyStack(Stack current_stack) {
	// handle error 
	if (current_stack == NULL) {
		HandleError(DeallocatedStack);
	}

	return IsEmptyQueue(current_stack->push_queue);
	// check is empty and return
}

// O(1) 
void RemoveStack(Stack* remove_stack_address) {
	// handle error 
	if (*remove_stack_address == NULL) {
		HandleError(DeallocatedStack);
	}

	// remove two queue
	RemoveQueue(&((*remove_stack_address)->push_queue));
	RemoveQueue(&((*remove_stack_address)->pop_queue));

	// store NULL and deallocate for dangling pointer 
	Stack deallocating_stack = *remove_stack_address;
	*remove_stack_address = NULL;
	free(deallocating_stack);

	return;
}

// O(1) 
static void HandleError(const enum ERROR_CODE code) {

	switch (code){

	case Memorylack: printf("ERROR : MEMORY IS NOT ENOUGH\n\n"); break;
	case EmptyStack: printf("ERROR : STACK IS  EMPTY\n\n"); break;
	case DeallocatedStack: printf("ERROR : STACK IS DEALLOCATED\n\n"); break;

	default: printf("ERROR : ERROR CODE EXCEPTION\n\n"); break;
	}

	exit(0);
}