#include <stdlib.h>
#include <stdio.h>
#include "List.h"

// circular array base 
struct ListType {
	ItemType item[MAX_LIST_LENGTH];
	int front; 
	int rear; 
};

enum ERROR_CODE { Memorylack, InvalidRank, FullList, EmptyList, DeallocatedList };

// O(1)
List InitList() {
	// allocate init_list 
	List init_list = malloc(sizeof(*init_list));
	if (init_list == NULL) {
		ErrorHandingFunction(Memorylack);
	}

	// init_list member init 
	init_list->front = 0; 
	init_list->rear = 0; 

	// return 
	return init_list;
}

// O(1) 
int GetSizeList(const List q_list) {
	// error handling
	if (q_list == NULL) {
		ErrorHandingFunction(DeallocatedList);
	}

	// return size of circular array 
	return (MAX_LIST_LENGTH - q_list->front + q_list->rear) % MAX_LIST_LENGTH;
}

// O(1) 
ItemType GetRankElementList(const List q_list, const  int rank) {
	// error handling 
	if (q_list == NULL) {
		ErrorHandingFunction(DeallocatedList);
	}

	// error handing 
	if (rank <= 0 && GetSizeList(q_list) < rank) {
		ErrorHandingFunction(InvalidRank);
	}

	// return rank item of circular array
	return q_list->item[(q_list->front + rank - 1) % MAX_LIST_LENGTH];
}

// O(1) 
void ChangeRankElementList(List q_list, const int rank, const ItemType replace_item) {
	// error handling 
	if (q_list == NULL) {
		ErrorHandingFunction(DeallocatedList);
	}

	// error handling 
	if (rank <= 0 || GetSizeList(q_list) < rank) {
		ErrorHandingFunction(InvalidRank);
	}

	// replace rank item of circular array 
	q_list->item[(q_list->front + rank - 1) % MAX_LIST_LENGTH] = replace_item;
}

// O(N) , but maximum traverse : list_size / 2 
void AddRankElementList(List q_list, const int rank, const ItemType add_item) {

	int list_size = GetSizeList(q_list), i; 

	// error handling 
	if (q_list == NULL) {
		ErrorHandingFunction(DeallocatedList);
	}

	// error handling 
	if (list_size == MAX_LIST_LENGTH - 1) {
		ErrorHandingFunction(FullList);
	}

	// error handling
	if (rank <= 0 || list_size + 1 < rank) {
		ErrorHandingFunction(InvalidRank);
	}

	// conclusion of push left or right before adding new item 
	// push and add new item and modify front or rear 
	// use logic ==> ( if rank is valid ) rank k's element ==> q_list->item[(q_list->front + k - 1) % MAX_LIST_LENGTH]  
	if (rank <= list_size / 2) {
		// left 
		// different right for push index 0 element 
		int recieve_idx = 0; 
		for (i = 1; i <= rank; i++) {
			recieve_idx = ((q_list->front + i - 1) - 1) % MAX_LIST_LENGTH < 0 ? MAX_LIST_LENGTH - 1 : ((q_list->front + i - 1) - 1) % MAX_LIST_LENGTH;
			q_list->item[recieve_idx] = q_list->item[(q_list->front + i - 1) % MAX_LIST_LENGTH];
		} 
		q_list->front = q_list->front - 1 < 0 ? MAX_LIST_LENGTH - 1 : q_list->front - 1; 
	}
	else {
		// right 
		for (i = list_size; i >= rank; i--) {
			q_list->item[((q_list->front + i + 1) - 1) % MAX_LIST_LENGTH] = q_list->item[(q_list->front + i - 1) % MAX_LIST_LENGTH];
		}
		q_list->rear = (q_list->rear + 1) % MAX_LIST_LENGTH; 
	}
	q_list->item[(q_list->front + rank - 1) % MAX_LIST_LENGTH] = add_item;
	return; 
}

// O(N) , but maximum traverse : list_size / 2 
ItemType RemoveRankElementList(List q_list, const int rank) {

	int list_size = GetSizeList(q_list), i;

	// error handling 
	if (q_list == NULL) {
		ErrorHandingFunction(DeallocatedList);
	}
	// error handling 
	if (list_size == 0) {
		ErrorHandingFunction(EmptyList);
	}

	// error handling 
	if (rank <= 0 || list_size < rank) {
		ErrorHandingFunction(InvalidRank);
	}
	
	// get rank element 
	ItemType get_item = q_list->item[(q_list->front + rank - 1) % MAX_LIST_LENGTH];

	// conclusion of pull left or right and pull 
	if (rank <= list_size / 2) {
		// left 
		for (i = 1; i <= rank; i++) {
			q_list->item[(q_list->front + i - 2) % MAX_LIST_LENGTH] = q_list->item[(q_list->front + i - 1) % MAX_LIST_LENGTH];
		}
	}
	else {
		// right 
		for (i = list_size; i >= rank; i--) {
			q_list->item[(q_list->front + i) % MAX_LIST_LENGTH] = q_list->item[(q_list->front + i - 1) % MAX_LIST_LENGTH];
		}
	}
	
	// return item 
	return get_item; 
}


// O(1) 
void RemoveList(List* remove_list_address) {
	if (*remove_list_address == NULL) {
		ErrorHandingFunction(DeallocatedList);
	}

	List* deallocating_address = remove_list_address;

	(*remove_list_address) = NULL;

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

void PRINT(List q_list)
{
	int i; 
	for (i = 0; i < MAX_LIST_LENGTH; i++)
		printf(" %d", q_list->item[i]);
}