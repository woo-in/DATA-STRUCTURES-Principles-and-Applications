#include <stdio.h>
#include <stdlib.h>
#include "DisjointSet.h"

struct DisjointSetType {
	char SetNameArray[MAX_ELEMENT_COUNT]; 
};

enum ERROR_CODE { Memorylack, InvalidElement, DeallocatedDisjointSet };

static void ErrorHandingFunction(enum ERROR_CODE code); 

// O(N) 
DisjointSet InitializeDisjointSet() {
	// allocate disjointset 
	DisjointSet init_disjoint_set = malloc(sizeof(*init_disjoint_set)); 
	if (init_disjoint_set == NULL) {
		ErrorHandingFunction(Memorylack);
	}

	// # ==> not setted 
	for (int i = 0; i < MAX_ELEMENT_COUNT; i++) {
		init_disjoint_set->SetNameArray[i] = '#'; 
	}

	// return 
	return init_disjoint_set; 
}

// O(1) 
void AddElementInDisjointSet(DisjointSet current_disjoint_set, const char current_set_name, const int current_element) {
	// error handling 
	if (current_disjoint_set == NULL) {
		ErrorHandingFunction(DeallocatedDisjointSet);
	}
	if ((0 > current_element) || (current_element >= MAX_ELEMENT_COUNT)) {
		ErrorHandingFunction(InvalidElement);
	}

	// add
	current_disjoint_set->SetNameArray[current_element] = current_set_name; 

	return; 
}

// O(1) 
char GetSetNameOfElementInDisjointSet(DisjointSet current_disjoint_set, const int current_element) {
	// error handling 
	if (current_disjoint_set == NULL) {
		ErrorHandingFunction(DeallocatedDisjointSet); 
	}
	if((0 > current_element) || (current_element >= MAX_ELEMENT_COUNT)) {
		ErrorHandingFunction(InvalidElement);
	}

	// return 
	return current_disjoint_set->SetNameArray[current_element];
}

// O(N)
void ChangeAllElementOfSetInDisjointSet(DisjointSet current_disjoint_set, const char before_change_set, const char after_change_set) {
	// error handling 
	if (current_disjoint_set == NULL) {
		ErrorHandingFunction(DeallocatedDisjointSet);
	}

	// change 
	for (int i = 0; i < MAX_ELEMENT_COUNT; i++) {
		if (current_disjoint_set->SetNameArray[i] == before_change_set) {
			current_disjoint_set->SetNameArray[i] = after_change_set;
		}
	}

	return; 
}

// O(1) 
void RemoveDisjointSet(DisjointSet* removing_disjoint_set_address) {
	if (*removing_disjoint_set_address == NULL) {
		ErrorHandingFunction(DeallocatedDisjointSet);
	}

	// remove disjoint set

	DisjointSet deallocating_address = *removing_disjoint_set_address; 

	(*removing_disjoint_set_address) = NULL;

	free(deallocating_address);

	return;
}


// O(1) 
static void ErrorHandingFunction(enum ERROR_CODE code) {
	switch (code)
	{
	case Memorylack: printf("ERROR : MEMORY IS NOT ENOUGH\n\n"); break;
	case InvalidElement: printf("ERROR : ELEMENT IS INVALID\n\n"); break;
	case DeallocatedDisjointSet: printf("ERROR : DISJOINTSET IS DEALLOCATED\n\n"); break;

	default: printf("ERROR : ERROR CODE EXCEPTION\n\n"); break;
	}

	exit(0);
}