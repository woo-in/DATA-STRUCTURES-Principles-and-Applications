/* Stack Array Version */
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

struct StackType {
	ItemType stack_storage[MAX_STACK_LENGTH]; 
	int top; // top element index  , if -1 : empty stack 
};

enum ERROR_CODE { Memorylack, FullStack, EmptyStack, DeallocatedStack };

static void ErrorHandingFunction(enum ERROR_CODE code);

// O(1) 
Stack InitStack() {
	// allocate 
	Stack init_stack = malloc(sizeof(*init_stack));
	if (init_stack == NULL) {
		ErrorHandingFunction(Memorylack);
	}

	// init 
	init_stack->top = -1;  

	return init_stack; 
}

// O(1) 
void PushStack(Stack current_stack, ItemType pushing_element) {
	// error handling 
	if (current_stack == NULL) {
		ErrorHandingFunction(DeallocatedStack);
	}
	if (current_stack->top >= MAX_STACK_LENGTH - 1) {
		ErrorHandingFunction(FullStack);
	}

	// + 1 index and push element to index 
	current_stack->top++;
	current_stack->stack_storage[current_stack->top] = pushing_element; 

	return; 
}

// O(1) 
ItemType PopStack(Stack current_stack) {
	// error handling 
	if (current_stack == NULL) {
		ErrorHandingFunction(DeallocatedStack);
	}
	if (current_stack->top < 0) {
		ErrorHandingFunction(EmptyStack);
	}

	// -1 index and pop element from index + 1 and return it 
	current_stack->top--; 
	return current_stack->stack_storage[current_stack->top + 1];
}

// O(1) 
ItemType GetTopElementStack(const Stack current_stack) {
	// error handling 
	if (current_stack == NULL) {
		ErrorHandingFunction(DeallocatedStack);
	}
	if (current_stack->top < 0) {
		ErrorHandingFunction(EmptyStack);
	}

	// return top index element 
	return current_stack->stack_storage[current_stack->top];
}

// O(1) 
int GetSizeStack(const Stack current_stack) {
	// error handling 
	if (current_stack == NULL) {
		ErrorHandingFunction(DeallocatedStack);
	}

	// return top + 1 
	return current_stack->top + 1; 
}

// O(1) 
bool IsEmptyStack(const Stack current_stack) {
	// error handling 
	if (current_stack == NULL) {
		ErrorHandingFunction(DeallocatedStack);
	}

	// judge empty stack  
	return (current_stack->top < 0);
}

/*
// O(N) 
void PrintElementStack(const Stack current_stack) {
	// error handling 
	if (current_stack == NULL) {
		ErrorHandingFunction(DeallocatedStack);
	}

	// print element of index ( 0 ~ top ) 
	for (int i = 0; i <= current_stack->top; i++) {
		printf("%d ", current_stack->stack_storage[i]);
	}
	printf("\n");

	return; 
}
*/



// O(1) 
void RemoveStack(Stack* remove_stack_address) {
	// error handling 
	if (*remove_stack_address == NULL) {
		ErrorHandingFunction(DeallocatedStack);
	}

	Stack* deallocating_address = remove_stack_address;

	// NULL for dangling pointer problem 
	(*remove_stack_address) = NULL;

	// deallocate 
	free(*remove_stack_address);

	return;
}

// O(1) 
static void ErrorHandingFunction(enum ERROR_CODE code) {
	switch (code)
	{
	case Memorylack: printf("ERROR : MEMORY IS NOT ENOUGH\n\n"); break;
	case FullStack: printf("ERROR : STACK IS FULL\n\n"); break;
	case EmptyStack: printf("ERROR : STACK IS  EMPTY\n\n"); break;
	case DeallocatedStack: printf("ERROR : STACK IS DEALLOCATED\n\n"); break;

	default: printf("ERROR : ERROR CODE EXCEPTION\n\n"); break;
	}

	exit(0);
}