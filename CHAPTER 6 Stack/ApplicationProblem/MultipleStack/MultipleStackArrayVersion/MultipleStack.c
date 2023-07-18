#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MultipleStack.h"

struct MultipleStackType {
	int* base_index_array; // array[total_length / one_length] 
	int* top_index_array; // array[total_length / one_length + 1]  

	ItemType* item_array; 
	int total_stack_length;
	int stack_count; 
};

enum ERROR_CODE { Memorylack, InvalidLength, InvalidMultipleStackOrder, EmptyMultipleStack, FullMultipleStack, DeallocatedMultipleStack };

static void ErrorHandingFunction(enum ERROR_CODE code); 

// O(N) 
MultipleStack InitMultipleStack(const int total_stack_length, const int stack_count) {

	// error handling 
	if (!((total_stack_length >= stack_count) && (total_stack_length % stack_count == 0)))
		ErrorHandingFunction(InvalidLength);

	// allocate MultipleStack 
	MultipleStack init_multiple_stack = malloc(sizeof(*init_multiple_stack));
	if (init_multiple_stack == NULL) {
		ErrorHandingFunction(Memorylack);
	}

	// allocate item array
	ItemType* init_item_array = malloc(sizeof((*init_item_array) * total_stack_length));
	if (init_item_array == NULL) {
		ErrorHandingFunction(Memorylack);
	}

	// allocate base index array 
	int* base_index_array = malloc(sizeof(*base_index_array) * (stack_count + 1));
	if (base_index_array == NULL) {
		ErrorHandingFunction(Memorylack);
	}

	// allocate top index array 
	int* top_index_array = malloc(sizeof(*top_index_array) * stack_count);
	if (top_index_array == NULL) {
		ErrorHandingFunction(Memorylack);
	}

	// init base , top index array 
	int one_stack_length = total_stack_length / stack_count; 
	for (int i = 0; i < stack_count; i++) {
		base_index_array[i] = one_stack_length * i - 1; 
		top_index_array[i] = base_index_array[i];  
	}
	base_index_array[stack_count] = one_stack_length * stack_count - 1; // last element of base_index_array 

	// connect allocated and return 
	init_multiple_stack->item_array = init_item_array; 
	init_multiple_stack->base_index_array = base_index_array; 
	init_multiple_stack->top_index_array = top_index_array; 
	init_multiple_stack->total_stack_length = total_stack_length; 
	init_multiple_stack->stack_count = stack_count; 

	return init_multiple_stack; 
}

// O(1) 
int GetSizeMultipleStack(const MultipleStack current_multiple_stack, const int current_multiple_stack_order) {
	// error handling 
	if (current_multiple_stack == NULL) {
		ErrorHandingFunction(DeallocatedMultipleStack);
	}
	if (!((1 <= current_multiple_stack_order) && (current_multiple_stack_order <= current_multiple_stack->stack_count))) {
		ErrorHandingFunction(InvalidMultipleStackOrder);
	}

	// get index 
	int current_multiple_stack_index = current_multiple_stack_order - 1; 

	// top[index] - base[index]  
	return current_multiple_stack->top_index_array[current_multiple_stack_index] - current_multiple_stack->base_index_array[current_multiple_stack_index];
}

// O(1) 
bool IsEmptyMultipleStack(const MultipleStack current_multiple_stack, const int current_multiple_stack_order) {
	// error handling 
	if (current_multiple_stack == NULL) {
		ErrorHandingFunction(DeallocatedMultipleStack);
	}
	if (!((1 <= current_multiple_stack_order) && (current_multiple_stack_order <= current_multiple_stack->stack_count))) {
		ErrorHandingFunction(InvalidMultipleStackOrder);
	}

	// get index 
	int current_multiple_stack_index = current_multiple_stack_order - 1;

	// top[index] == base[index] == > true , else == > false   
	return (current_multiple_stack->top_index_array[current_multiple_stack_index] == current_multiple_stack->base_index_array[current_multiple_stack_index]);
}

// O(1) 
bool IsFullMultipleStack(const MultipleStack current_multiple_stack, const int current_multiple_stack_order) {
	// error handling 
	if (current_multiple_stack == NULL) {
		ErrorHandingFunction(DeallocatedMultipleStack);
	}
	if (!((1 <= current_multiple_stack_order) && (current_multiple_stack_order <= current_multiple_stack->stack_count))) {
		ErrorHandingFunction(InvalidMultipleStackOrder);
	}

	// get index 
	int current_multiple_stack_index = current_multiple_stack_order - 1;

	// top[index] == base[index+1] == > true , else == > false   
	return (current_multiple_stack->top_index_array[current_multiple_stack_index] == current_multiple_stack->base_index_array[current_multiple_stack_index + 1]);
}

// O(1) 
ItemType GetTopElementMultipleStack(const MultipleStack current_multiple_stack, const int current_multiple_stack_order) {
	// error handling 
	if (current_multiple_stack == NULL) {
		ErrorHandingFunction(DeallocatedMultipleStack);
	}
	if (!((1 <= current_multiple_stack_order) && (current_multiple_stack_order <= current_multiple_stack->stack_count))) {
		ErrorHandingFunction(InvalidMultipleStackOrder);
	}

	// get index 
	int current_multiple_stack_index = current_multiple_stack_order - 1;

	// empty stack ==> error
	if (current_multiple_stack->top_index_array[current_multiple_stack_index] == current_multiple_stack->base_index_array[current_multiple_stack_index]) {
		ErrorHandingFunction(EmptyMultipleStack);
	}

	// return item_array value of index of top
	return current_multiple_stack->item_array[current_multiple_stack->top_index_array[current_multiple_stack_index]];
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

	// get index 
	int current_multiple_stack_index = current_multiple_stack_order - 1;

	// full stack ==> error
	if (current_multiple_stack->top_index_array[current_multiple_stack_index] == current_multiple_stack->base_index_array[current_multiple_stack_index + 1]){
		ErrorHandingFunction(FullMultipleStack);
	}

	// top index increment 
	current_multiple_stack->top_index_array[current_multiple_stack_index]++; 

	// pushing item 
	current_multiple_stack->item_array[current_multiple_stack->top_index_array[current_multiple_stack_index]] = pushing_element;

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

	// get index 
	int current_multiple_stack_index = current_multiple_stack_order - 1;

	// empty stack ==> error
	if (current_multiple_stack->top_index_array[current_multiple_stack_index] == current_multiple_stack->base_index_array[current_multiple_stack_index]) {
		ErrorHandingFunction(EmptyMultipleStack);
	}

	// get item_array value of index of top
	ItemType get_item = current_multiple_stack->item_array[current_multiple_stack->top_index_array[current_multiple_stack_index]];

	// top index decrement
	current_multiple_stack->top_index_array[current_multiple_stack_index]--;

	// return 
	return get_item; 
}

// O(1) 
void RemoveMultipleStack(MultipleStack* remove_multiple_stack_address) {
	// error handling 
	if (*remove_multiple_stack_address == NULL) {
		ErrorHandingFunction(DeallocatedMultipleStack);
	}

	
	// free connected 
	free((*remove_multiple_stack_address)->base_index_array);
	free((*remove_multiple_stack_address)->top_index_array); 
	free((*remove_multiple_stack_address)->item_array); 
	

	// free MultipleStack 
	MultipleStack deallocating_address = *remove_multiple_stack_address;

	// NULL for dangling pointer problem 
	(*remove_multiple_stack_address) = NULL;

	// deallocate 
	free(deallocating_address);

	return;
}

// O(1) 
static void ErrorHandingFunction(enum ERROR_CODE code) {
	switch (code)
	{
	case Memorylack: printf("ERROR : MEMORY IS NOT ENOUGH\n\n"); break;
	case InvalidLength : printf("ERROR : INVALID LENGTH\n\n"); break;
	case InvalidMultipleStackOrder: printf("ERROR : INVALID MULTIPLE STACK ORDER\n\n"); break; 
	case EmptyMultipleStack: printf("ERROR : EMPTY MULTIPLE STACK\n\n"); break; 
	case FullMultipleStack: printf("ERROR : FULL MULTIPLE STACK\n\n"); break; 
	case DeallocatedMultipleStack: printf("ERROR : MULTIPLE STACK IS DEALLOCATED\n\n"); break;

	default: printf("ERROR : ERROR CODE EXCEPTION\n\n"); break;
	}

	exit(0);
}