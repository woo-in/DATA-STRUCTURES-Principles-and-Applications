#include "Tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeType {
	ItemType* tree_array_address; 
	int max_tree_len; // use ? 
};

enum ERROR_CODE { Memorylack, InvalidMaxTreeLength, EmptyDeque, DeallocatedDeque };

static void ErrorHandingFunction(enum ERROR_CODE code);

Tree InitializeTree(const int max_tree_len) {
	// error handling 
	if (max_tree_len <= 0) {
		ErrorHandingFunction(InvalidMaxTreeLength);
	}

	// allocate Tree
	Tree init_tree = malloc(sizeof(*init_tree));
	if (init_tree == NULL) {
		ErrorHandingFunction(Memorylack);
	}

	// allocatre 

	// connect 
	init_tree->tree_array_address = tree_array_address; 
	init_tree->max_tree_len = max_tree_len; 

	// return 
	return init_tree; 
}

void RemoveTree












// O(1) 
static void ErrorHandingFunction(enum ERROR_CODE code) {
	switch (code)
	{
	case Memorylack: printf("ERROR : MEMORY IS NOT ENOUGH\n\n"); break;
	case InvalidMaxTreeLength: printf("ERROR : DEQUE IS FULL\n\n"); break;
	case EmptyDeque: printf("ERROR : DEQUE IS  EMPTY\n\n"); break;
	case DeallocatedDeque: printf("ERROR : DEQUE IS DEALLOCATED\n\n"); break;

	default: printf("ERROR : ERROR CODE EXCEPTION\n\n"); break;
	}

	exit(0);
}