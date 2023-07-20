#include <stdio.h>
#include <stdlib.h>
#include "MultipleStack.h"

struct Node {
	ItemType item;
	struct Node* next;
};

struct MultipleStackType {
	struct Node** stack_pointer_array; 
	int stack_count; 
};

enum ERROR_CODE { Memorylack, InvalidStackCount, InvalidMultipleStackOrder, EmptyMultipleStack, DeallocatedMultipleStack };

static void ErrorHandingFunction(enum ERROR_CODE code);
static struct Node* Get_Node();

// O(N) , N : stack_count 
MultipleStack InitMultipleStack(const int stack_count) {
	// error handling 
	if (stack_count <= 0) {
		ErrorHandingFunction(InvalidStackCount);
	}

	// array of stack pointer allocate 
	struct Node** init_stack_pointer_array = malloc(sizeof(*init_stack_pointer_array) * stack_count);
	if (init_stack_pointer_array == NULL) {
		ErrorHandingFunction(Memorylack);
	}

	// NULL init array element 
	for (int i = 0; i < stack_count; i++) {
		init_stack_pointer_array[i] = NULL; 
	}

	// MultipleStack allocate and connect and return 
	MultipleStack init_multiple_stack = malloc(sizeof(*init_multiple_stack));
	if (init_multiple_stack == NULL) {
		ErrorHandingFunction(Memorylack);
	}

	init_multiple_stack->stack_pointer_array = init_stack_pointer_array; 
	init_multiple_stack->stack_count = stack_count; 

	return init_multiple_stack; 
}
 
// O(1) 
bool IsEmptyMultipleStack(MultipleStack current_multiple_stack, const int current_multiple_stack_order) {
	// error handling 
	if (current_multiple_stack == NULL) {
		ErrorHandingFunction(DeallocatedMultipleStack);
	}
	if (!((1 <= current_multiple_stack_order) && (current_multiple_stack_order <= current_multiple_stack->stack_count))) {
		ErrorHandingFunction(InvalidMultipleStackOrder);
	}

	// judge empty 
	int current_multiple_stack_index = current_multiple_stack_order - 1; 
	return (current_multiple_stack->stack_pointer_array[current_multiple_stack_index] == NULL);
}

// O(1) 
ItemType GetTopElementMultipleStack(MultipleStack current_multiple_stack, const int current_multiple_stack_order) {
	// error handling 
	if (current_multiple_stack == NULL) {
		ErrorHandingFunction(DeallocatedMultipleStack);
	}
	if (!((1 <= current_multiple_stack_order) && (current_multiple_stack_order <= current_multiple_stack->stack_count))) {
		ErrorHandingFunction(InvalidMultipleStackOrder);
	}
	
	// judge empty error 
	int current_multiple_stack_index = current_multiple_stack_order - 1;
	if (current_multiple_stack->stack_pointer_array[current_multiple_stack_index] == NULL) {
		ErrorHandingFunction(EmptyMultipleStack);
	}

	// return top element 
	return current_multiple_stack->stack_pointer_array[current_multiple_stack_index]->item; 
}

// O(1) 
void PushMultipleStack(MultipleStack current_multiple_stack, const int current_multiple_stack_order, const ItemType pushing_element) {
	// error handling 
	if (current_multiple_stack == NULL) {
		ErrorHandingFunction(DeallocatedMultipleStack);
	}
	if (!((1 <= current_multiple_stack_order) && (current_multiple_stack_order <= current_multiple_stack->stack_count))) {
		ErrorHandingFunction(InvalidMultipleStackOrder);
	}

	int current_multiple_stack_index = current_multiple_stack_order - 1;

	// get node , insert item , connect 
	
	struct Node* insert_node = Get_Node();

	insert_node->item = pushing_element; 

	if (current_multiple_stack->stack_pointer_array[current_multiple_stack_index] != NULL) {
		insert_node->next = current_multiple_stack->stack_pointer_array[current_multiple_stack_index];
	}
	current_multiple_stack->stack_pointer_array[current_multiple_stack_index] = insert_node; 

	return; 
}

// O(1) 
ItemType PopMultipleStack(MultipleStack current_multiple_stack, const int current_multiple_stack_order) {
	// error handling 
	if (current_multiple_stack == NULL) {
		ErrorHandingFunction(DeallocatedMultipleStack);
	}
	if (!((1 <= current_multiple_stack_order) && (current_multiple_stack_order <= current_multiple_stack->stack_count))) {
		ErrorHandingFunction(InvalidMultipleStackOrder);
	}

	int current_multiple_stack_index = current_multiple_stack_order - 1;

	// specify , modify , deallocate , return 

	struct Node* deallocating_node = current_multiple_stack->stack_pointer_array[current_multiple_stack_index]; 
	if (deallocating_node == NULL) {
		ErrorHandingFunction(EmptyMultipleStack);
	}

	ItemType get_item = deallocating_node->item; 

	current_multiple_stack->stack_pointer_array[current_multiple_stack_index] = deallocating_node->next; 

	free(deallocating_node);

	return get_item; 
}

// O(N) , N : total_element_count 
void RemoveMultipleStack(MultipleStack* remove_multiple_stack_address) {
	// error handling 
	if (*remove_multiple_stack_address == NULL) {
		ErrorHandingFunction(DeallocatedMultipleStack);
	}

	// free array connected node
	for (int i = 0; i < (*remove_multiple_stack_address)->stack_count; i++) {
		if ((*remove_multiple_stack_address)->stack_pointer_array[i] != NULL) {
			struct Node* tmp = (*remove_multiple_stack_address)->stack_pointer_array[i];
			struct Node* tmp_next = tmp->next;
			while (tmp_next != NULL) {
				free(tmp);
				tmp = tmp_next;
				tmp_next = tmp_next->next;
			}
			free(tmp);
		}
	}

	// free array 
	free((*remove_multiple_stack_address)->stack_pointer_array);

	// allocate NULL for dangling pointer problem 
	MultipleStack deallocating_address = *remove_multiple_stack_address;
	(*remove_multiple_stack_address) = NULL;

	// free MultipleStack 
	free(deallocating_address);

	return;
}

// O(1) 
static void ErrorHandingFunction(enum ERROR_CODE code) {
	switch (code)
	{
	case Memorylack: printf("ERROR : MEMORY IS NOT ENOUGH\n\n"); break;
	case InvalidStackCount: printf("ERROR : INVALID STACK COUNT\n\n"); break;
	case InvalidMultipleStackOrder: printf("ERROR : INVALID MULTIPLE STACK ORDER\n\n"); break;
	case EmptyMultipleStack: printf("ERROR : EMPTY MULTIPLE STACK\n\n"); break;	
	case DeallocatedMultipleStack: printf("ERROR : MULTIPLE STACK IS DEALLOCATED\n\n"); break;

	default: printf("ERROR : ERROR CODE EXCEPTION\n\n"); break;
	}

	// memory deallocate ? 

	exit(0);
}

// O(1)
static struct Node* Get_Node() {
	struct Node* new_node = malloc(sizeof(struct Node));
	if (new_node == NULL) {
		ErrorHandingFunction(Memorylack);
	}

	// init next 
	new_node->next = NULL;

	return new_node;
}