#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ListLinkedListVersion.h"

struct Node {
	ItemType item;
	struct Node* prev;
	struct Node* next;
};


struct ListType {
	struct Node* header;
	struct Node* trailer;
	int list_size; 
};

enum ERROR_CODE { Memorylack, InvalidRank, FullList, EmptyList, DeallocatedList };

// O(1)
List InitList() {
	List init_list = malloc(sizeof(List*));
	if (init_list == NULL) {
		ErrorHandingFunction(Memorylack);
	}

	// pointing each other
	init_list->header = Get_Node();
	init_list->trailer = Get_Node();
	init_list->header->next = init_list->trailer;
	init_list->trailer->prev = init_list->header;

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

// O(N) , N : list_size  
ItemType GetRankElementList(const List q_list, const int rank) {
	if (q_list == NULL) {
		ErrorHandingFunction(DeallocatedList);
	}

	if (rank <= 0 || rank > q_list->list_size) {
		ErrorHandingFunction(InvalidRank);
	}
 
	///////////////////////////////////////// searching code 
	int middle_index = (1 + q_list->list_size) / 2, i; 
	struct Node* tmp = NULL;
	if (rank <= middle_index) {
		// search from header 
		tmp = q_list->header;
		for (i = 0; i < rank; i++) {
			tmp = tmp->next;
		}
	}
	else {
		// search from trailer
		tmp = q_list->trailer; 
		for (i = 0; i < q_list->list_size - rank + 1; i++) {
			tmp = tmp->prev; 
		}
	}
	///////////////////////////////////////////////////////

	return tmp->item; 
	// 1 2 3 4 5 6 7  
	// 1 , 2 , 3 , 4 , 5 , ... , list_size
	// 1 ~ (1+list_size) / 2      
	// (1+list_size) / 2  + 1 ~ list_size 
}

// O(N) , N : list_size  
void ChangeRankElementList(List q_list, const int rank, const ItemType replace_item) {
	if (q_list == NULL) {
		ErrorHandingFunction(DeallocatedList);
	}

	if (rank <= 0 || rank > q_list->list_size ) {
		ErrorHandingFunction(InvalidRank);
	}

	///////////////////////////////////////// searching code 
	int middle_index = (1 + q_list->list_size) / 2, i;
	struct Node* tmp = NULL;
	if (rank <= middle_index) {
		// search from header 
		tmp = q_list->header;
		for (i = 0; i < rank; i++) {
			tmp = tmp->next;
		}
	}
	else {
		// search from trailer
		tmp = q_list->trailer;
		for (i = 0; i < q_list->list_size - rank + 1; i++) {
			tmp = tmp->prev;
		}
	}
	///////////////////////////////////////////////////////

	tmp->item = replace_item; 

	return;
}

// O(N) , N : list_size  
void AddRankElementList(List q_list, const int rank, const ItemType add_item) {
	if (q_list == NULL) {
		ErrorHandingFunction(DeallocatedList);
	}

	if (rank <= 0 || (rank > q_list->list_size + 1) ) {
		ErrorHandingFunction(InvalidRank);
	}

	///////////////////////////////////////// searching code 
	int middle_index = (1 + q_list->list_size) / 2, i;
	struct Node* tmp = NULL;
	if (rank <= middle_index) {
		// search from header 
		tmp = q_list->header;
		for (i = 0; i < rank; i++) {
			tmp = tmp->next;
		}
	}
	else {
		// search from trailer
		tmp = q_list->trailer;
		for (i = 0; i < q_list->list_size - rank + 1; i++) {
			tmp = tmp->prev;
		}
	}
	///////////////////////////////////////////////////////

	// make node and insert 
	struct Node* new_node = Get_Node();
	new_node->item = add_item;
	new_node->next = tmp;
	new_node->prev = tmp->prev;
	tmp->prev->next = new_node;
	tmp->prev = new_node;
	// test first , middle , end 

	q_list->list_size++;
}

// O(1) 
void AddFirstElementList(List q_list, const ItemType add_item) {
	if (q_list == NULL) {
		ErrorHandingFunction(DeallocatedList);
	}

	struct Node* tmp = q_list->header->next; 

	// make node and insert 
	struct Node* new_node = Get_Node();
	new_node->item = add_item;
	new_node->next = tmp;
	new_node->prev = tmp->prev;
	tmp->prev->next = new_node;
	tmp->prev = new_node;
	// test first , middle , end 

	q_list->list_size++;
}

// O(1) 
void AddLastElementList(List q_list, const ItemType add_item) {
	if (q_list == NULL) {
		ErrorHandingFunction(DeallocatedList);
	}

	struct Node* tmp = q_list->trailer; 

	// make node and insert 
	struct Node* new_node = Get_Node();
	new_node->item = add_item;
	new_node->next = tmp;
	new_node->prev = tmp->prev;
	tmp->prev->next = new_node;
	tmp->prev = new_node;
	// test first , middle , end 

	q_list->list_size++;
}

// O(N) , N : list size 
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

	///////////////////////////////////////// searching code 
	int middle_index = (1 + q_list->list_size) / 2, i;
	struct Node* tmp = NULL;
	if (rank <= middle_index) {
		// search from header 
		tmp = q_list->header;
		for (i = 0; i < rank; i++) {
			tmp = tmp->next;
		}
	}
	else {
		// search from trailer
		tmp = q_list->trailer;
		for (i = 0; i < q_list->list_size - rank + 1; i++) {
			tmp = tmp->prev;
		}
	}
	///////////////////////////////////////////////////////

	tmp->prev->next = tmp->next; 
	tmp->next->prev = tmp->prev; 
	ItemType get_item = tmp->item; 
	free(tmp);

	q_list->list_size--;

	return get_item;  
}

// O(1)
ItemType RemoveFirstElementList(List q_list) {
	if (q_list == NULL) {
		ErrorHandingFunction(DeallocatedList);
	}

	if (q_list->list_size <= 0) {
		ErrorHandingFunction(EmptyList);
	}

	struct Node* tmp = q_list->header->next; 

	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	ItemType get_item = tmp->item;
	free(tmp);

	q_list->list_size--;

	return get_item;


}

// O(1)
ItemType RemoveLastElementList(List q_list) {
	if (q_list == NULL) {
		ErrorHandingFunction(DeallocatedList);
	}

	if (q_list->list_size <= 0) {
		ErrorHandingFunction(EmptyList);
	}

	struct Node* tmp = q_list->trailer->prev; 

	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	ItemType get_item = tmp->item;
	free(tmp);

	q_list->list_size--;

	return get_item;
}
 
// O(N) , N : list_size 
void RemoveList(List* remove_list_address) {
	if (*remove_list_address == NULL) {
		ErrorHandingFunction(DeallocatedList);
	}

	// rotate for free 
	struct Node* tmp_deallocating = NULL; 
	struct Node* tmp = (*remove_list_address)->header->next; // 1st item node or trailer(size : 0) 
	while (tmp->next != NULL) {
		tmp_deallocating = tmp; 
		tmp = tmp->next;
		free(tmp_deallocating);
	}

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

// O(1)
static struct Node* Get_Node(){
	struct Node* new_node = malloc(sizeof(struct Node));
	if (new_node == NULL) {
		ErrorHandingFunction(Memorylack);
	}

	new_node->next = NULL; 
	new_node->prev = NULL;  

	return new_node;  
}