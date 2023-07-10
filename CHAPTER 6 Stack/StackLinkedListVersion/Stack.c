/* Stack LinkedList Version */
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

struct Node {
	ItemType item;
	struct Node* next;
};

struct StackType {
	struct Node* stack_item;
	int item_count; 
};

enum ERROR_CODE { Memorylack, EmptyStack, DeallocatedStack };

static void ErrorHandingFunction(enum ERROR_CODE code);
static struct Node* Get_Node(); 

// O(1) 
Stack InitStack() {
	// allocate 
	Stack init_stack = malloc(sizeof(*init_stack));
	if (init_stack == NULL) {
		ErrorHandingFunction(Memorylack);
	}

	// init 
	init_stack->stack_item = NULL; 
	init_stack->item_count = 0; 

	return init_stack;
}

// O(1) 
void PushStack(Stack current_stack, ItemType pushing_element) {
	// error handling 
	if (current_stack == NULL) {
		ErrorHandingFunction(DeallocatedStack);
	}
	
	// get new node ==> new item storage 
	struct Node* item_node = Get_Node(); 
	item_node->item = pushing_element; 

	// connect 
	item_node->next = current_stack->stack_item; 
	current_stack->stack_item = item_node; 

	// count + 1 
	current_stack->item_count++; 

	return;
}

// O(1) 
ItemType PopStack(Stack current_stack) {
	// error handling 
	if (current_stack == NULL) {
		ErrorHandingFunction(DeallocatedStack);
	}
	if (current_stack->stack_item == NULL) {
		ErrorHandingFunction(EmptyStack);
	}

	// get pop_node
	struct Node* pop_node = current_stack->stack_item; 

	// get item of pop_node
	ItemType get_item = pop_node->item;  

	// disconnect and dealloc 
	current_stack->stack_item = pop_node->next;  
	free(pop_node);

	// count - 1 
	current_stack->item_count--; 
	
	return get_item;  
}

// O(1) 
ItemType GetTopElementStack(const Stack current_stack) {
	// error handling 
	if (current_stack == NULL) {
		ErrorHandingFunction(DeallocatedStack);
	}
	if (current_stack->stack_item == NULL) {
		ErrorHandingFunction(EmptyStack);
	}

	// return 
	return current_stack->stack_item->item; 
}

// O(1) 
int GetSizeStack(const Stack current_stack) {
	// error handling 
	if (current_stack == NULL) {
		ErrorHandingFunction(DeallocatedStack);
	}

	// return 
	return current_stack->item_count;
}

// O(1) 
bool IsEmptyStack(const Stack current_stack) {
	// error handling 
	if (current_stack == NULL) {
		ErrorHandingFunction(DeallocatedStack);
	}

	// judge empty stack  
	return (current_stack->item_count == 0);
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



// O(N) , size of stack 
void RemoveStack(Stack* remove_stack_address) {
	// error handling 
	if (*remove_stack_address == NULL) {
		ErrorHandingFunction(DeallocatedStack);
	}

	// rotate for free 
	if ((*remove_stack_address)->stack_item != NULL) {
		struct Node* tmp = (*remove_stack_address)->stack_item;
		struct Node* tmp_next = tmp->next;
		while (tmp_next != NULL) {
			free(tmp);
			tmp = tmp_next;
			tmp_next = tmp_next->next;
		}
		free(tmp);
	}

	Stack* deallocating_address = remove_stack_address;

	// NULL for dangling pointer problem 
	(*remove_stack_address) = NULL;

	// deallocate Stack 
	free(*remove_stack_address);

	return;
}

// O(1) 
static void ErrorHandingFunction(enum ERROR_CODE code) {
	switch (code)
	{
	case Memorylack: printf("ERROR : MEMORY IS NOT ENOUGH\n\n"); break;
	case EmptyStack: printf("ERROR : STACK IS  EMPTY\n\n"); break;
	case DeallocatedStack: printf("ERROR : STACK IS DEALLOCATED\n\n"); break;

	default: printf("ERROR : ERROR CODE EXCEPTION\n\n"); break;
	}

	exit(0);
}

// O(1)
static struct Node* Get_Node() {
	struct Node* new_node = malloc(sizeof(struct Node));
	if (new_node == NULL) {
		ErrorHandingFunction(Memorylack);
	}

	new_node->next = NULL;
	
	return new_node;
}