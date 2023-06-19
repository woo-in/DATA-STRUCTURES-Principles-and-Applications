#include "ListArrayVersion.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListType {
	ItemType item[MAX_LIST_LENGTH];
	int list_size;
};

enum ERROR_CODE { Memorylack, InvalidRank, FullList, EmptyList , DeallocatedList };


// O(1)
List InitList() {
	List init_list = malloc(sizeof(List *));
	if (init_list == NULL) {
		ErrorHandingFunction(Memorylack);
	}
	
	init_list->list_size = 0; 
	return init_list;
}

// O(1)
int GetSizeList(const List q_list) {
	if (q_list == NULL) {
		ErrorHandingFunction(DeallocatedList);
	}

	return q_list->list_size;
}

// O(1) 
bool IsEmptyList(const List q_list) {
	if (q_list == NULL) {
		ErrorHandingFunction(DeallocatedList);
	}

	return !(q_list->list_size);
}

// O(1) 
ItemType GetRankElementList(const List q_list ,const int rank) {
	if (q_list == NULL) {
		ErrorHandingFunction(DeallocatedList);
	}

	if (rank <= 0 || rank > q_list->list_size || rank > MAX_LIST_LENGTH) {
		ErrorHandingFunction(InvalidRank);
	}

	return q_list->item[rank - 1];
}

// O(1)
void ChangeRankElementList(List q_list, const int rank, const ItemType replace_item) {
	if (q_list == NULL) {
		ErrorHandingFunction(DeallocatedList);
	}

	if (rank <= 0 || rank > q_list->list_size || rank > MAX_LIST_LENGTH) {
		ErrorHandingFunction(InvalidRank);
	}

	q_list->item[rank - 1] = replace_item;

	return; 
}

// O(N) , N : element count  
void AddRankElementList(List q_list , const int rank ,const ItemType add_item) { 
	if (q_list == NULL) {
		ErrorHandingFunction(DeallocatedList);
	}

	if (rank <= 0 || (rank > q_list->list_size + 1) || rank > MAX_LIST_LENGTH) {
		ErrorHandingFunction(InvalidRank);
	}

	if (q_list->list_size + 1 > MAX_LIST_LENGTH) {
		ErrorHandingFunction(FullList);
	}

	// change location and add item 
	int end_index = q_list->list_size - 1;
	int add_index = rank - 1; 
	for (int i = end_index; i >= add_index; i--) {
		q_list->item[i+1] = q_list->item[i];
	}
	q_list->item[add_index] = add_item;

	q_list->list_size++; 

	return; 
}

// O(N) , N : element count 
void AddFirstElementList(List q_list, const ItemType add_item) {
	if (q_list == NULL) {
		ErrorHandingFunction(DeallocatedList);
	}

	if (q_list->list_size + 1 > MAX_LIST_LENGTH) {
		ErrorHandingFunction(FullList);
	}

	// change location and add item 
	int end_index = q_list->list_size - 1; 
	int add_index = 0; 
	for (int i = end_index; i >= add_index; i--) {
		q_list->item[i + 1] = q_list->item[i];
	}
	q_list->item[add_index] = add_item; 

	q_list->list_size++;

	return; 
}

// O(1) 
void AddLastElementList(List q_list,const ItemType add_item) {
	if (q_list == NULL) {
		ErrorHandingFunction(DeallocatedList);
	}

	if (q_list->list_size + 1 > MAX_LIST_LENGTH) {
		ErrorHandingFunction(FullList);
	}

	q_list->item[q_list->list_size] = add_item; // inserting index == before inserting size 

	q_list->list_size++;

	return; 
}

// O(N) , N : element count 
ItemType RemoveRankElementList(List q_list, const int rank) {
	if (q_list == NULL) {
		ErrorHandingFunction(DeallocatedList);
	}

	if (rank <= 0 || rank > q_list->list_size) {
		ErrorHandingFunction(InvalidRank);
	}

	if (q_list->list_size <= 0) {
		ErrorHandingFunction(EmptyList);
	}

	// change location and delete item 
	int end_index = q_list->list_size - 1;
	int delete_index_next = rank ;
	for (int i = delete_index_next ; i <= end_index; i++) {
		q_list->item[i - 1] = q_list->item[i];
	}
	
	q_list->list_size--;

	return; 
}

// O(N) , N : element count 
ItemType RemoveFirstElementList(List q_list) {
	if (q_list == NULL) {
		ErrorHandingFunction(DeallocatedList);
	}

	if (q_list->list_size <= 0) {
		ErrorHandingFunction(EmptyList);
	}

	// change location and delete item 
	int end_index = q_list->list_size - 1;
	int delete_index_next = 1;
	for (int i = delete_index_next; i <= end_index; i++) {
		q_list->item[i - 1] = q_list->item[i];
	}

	q_list->list_size--;

	return; 
}

// 0(1) 
ItemType RemoveLastElementList(List q_list) {
	if (q_list == NULL) {
		ErrorHandingFunction(DeallocatedList);
	}

	if (q_list->list_size <= 0) {
		ErrorHandingFunction(EmptyList);
	}

	q_list->list_size--;

	return; 
}

// O(1) 
void RemoveList(List* remove_list_address) {
	if (*remove_list_address == NULL) {
		ErrorHandingFunction(DeallocatedList);
	}

	(* remove_list_address) = NULL;

	free(*remove_list_address);

	return; 
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


