#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Set.h"


struct Node {
	ItemType item;
	struct Node* prev;
	struct Node* next;
};
struct SetType {
	struct Node* header; 
	bool (*sort_criteria) (ItemType a, ItemType b);
};
enum ERROR_CODE { Memorylack, InvalidRank, FullList, EmptyList, DeallocatedList };

static struct Node* Get_Node();
static void ErrorHandingFunction(enum ERROR_CODE code);

Set InitSet(bool (*sort_criteria)(ItemType a, ItemType b)) {
	// allocate set 
	Set init_set = malloc(sizeof(*init_set));
	if (init_set == NULL) {
		ErrorHandingFunction(Memorylack);
	}

	// allocate header Node 
	init_set->header = Get_Node(); 

	// allocate sort_criteria 
	init_set->sort_criteria = sort_criteria; 

	return init_set; 
}

void RemoveSet(Set* remove_set_address) {
	// error handling 
	if (*remove_set_address == NULL) {
		ErrorHandingFunction(DeallocatedList);
	}

	// remove Nodes of set 
	struct Node* tmp_deallocating = NULL;
	struct Node* tmp = (*remove_set_address)->header->next; // 1st item node or trailer(siz
	while (tmp->next != NULL) {
		tmp_deallocating = tmp;
		tmp = tmp->next;
		free(tmp_deallocating);
	}

	// remove set and store NULL for dangling pointer problem 
	Set* deallocating_set_address = remove_set_address;
	(*remove_set_address) = NULL;
	free(*deallocating_set_address);

	return; 
}

// O(1)
static struct Node* Get_Node() {
	struct Node* new_node = malloc(sizeof(struct Node));
	if (new_node == NULL) {
		ErrorHandingFunction(Memorylack);
	}

	new_node->next = NULL;
	new_node->prev = NULL;

	return new_node;
}

// O(1) 
static void ErrorHandingFunction(enum ERROR_CODE code) {
	switch (code)
	{
	case Memorylack: printf("ERROR : MEMORY IS NOT ENOUGH\n\n"); break;
	case InvalidRank: printf("ERROR : RANK IS INVALID\n\n"); break;
	case FullList: printf("ERROR : LIST IS FULL\n\n"); break;
	case EmptyList: printf("ERROR : LIST IS  EMPTY\n\n"); break;
	case DeallocatedList: printf("ERROR : LIST IS DEALLOCATED\n\n"); break;

	default: printf("ERROR : ERROR CODE EXCEPTION\n\n"); break;
	}

	exit(0);
}
