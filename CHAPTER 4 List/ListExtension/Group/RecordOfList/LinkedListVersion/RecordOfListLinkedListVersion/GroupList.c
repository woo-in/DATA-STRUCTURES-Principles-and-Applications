/* Group List Record Of List Linked List Version */
#include <stdio.h>
#include <stdlib.h>
#include "GroupList.h"

struct Node {
	ItemType item;
	GroupType group;
	struct Node* prev;
	struct Node* next;
};

struct GroupListType {
	struct Node* header;
	struct Node* trailer;
	//int list_size;
};

enum ERROR_CODE { Memorylack, DeallocatedList };


// O(1) 
GroupList InitGroupList() {
	GroupList init_list = malloc(sizeof(*init_list));
	if (init_list == NULL) {
		ErrorHandingFunction(Memorylack);
	}

	// pointing each other
	init_list->header = Get_Node();
	init_list->trailer = Get_Node();
	init_list->header->next = init_list->trailer;
	init_list->trailer->prev = init_list->header;

	// init_list->list_size = 0;

	return init_list;
}

// O(1) 
void AddLastElementGroupList(GroupList q_list, const ItemType add_item, const GroupType add_group) {
	if (q_list == NULL) {
		ErrorHandingFunction(DeallocatedList);
	}

	struct Node* tmp = q_list->trailer;

	// make node and insert 
	struct Node* new_node = Get_Node();
	new_node->item = add_item;
	new_node->group = add_group;
	new_node->next = tmp;
	new_node->prev = tmp->prev;
	tmp->prev->next = new_node;
	tmp->prev = new_node;

	// q_list->list_size++;
}

// O(N) , N : group_list_size 
void PrintDesignatedElementGroupList(const GroupList q_list, const GroupType designated_group) {
	if (q_list == NULL) {
		ErrorHandingFunction(DeallocatedList);
	}

	printf("GROUP %c :", designated_group);
	// printf conversion specification can modify , if type of group modified  < check !!!! >

	// traverse and print designated_group 
	struct Node* tmp = q_list->header->next; 
	while (tmp != NULL) {
		if (tmp->group == designated_group) {
			printf(" %d", tmp->item);
			// printf conversion specification can modify , if type of item modified  < check !!!! >    
		}
		tmp = tmp->next; 
	}

	printf("\n");

	return;
}

// O(N) , N : group_list_size
void RemoveDesignatedElementGroupList(GroupList q_list, const GroupType designated_group) {
	if (q_list == NULL) {
		ErrorHandingFunction(DeallocatedList);
	}

	// traverse and remove designated_group 
	struct Node* tmp = q_list->header->next;
	struct Node* tmp_next = NULL; 
	while (tmp != NULL) {
		if (tmp->group == designated_group) {

			tmp_next = tmp->next; // for next traverse  

			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			free(tmp);

			tmp = tmp_next; 
		}
		else {
			tmp = tmp->next;
		}
	}

	return; 
}

// O(N) , N : list_size
void RemoveGroupList(GroupList* remove_group_list_address) {
	if (*remove_group_list_address == NULL) {
		ErrorHandingFunction(DeallocatedList);
	}

	// rotate for free 
	struct Node* tmp_deallocating = NULL;
	struct Node* tmp = (*remove_group_list_address)->header->next; // 1st item node or trailer(size : 0) 
	while (tmp->next != NULL) {
		tmp_deallocating = tmp;
		tmp = tmp->next;
		free(tmp_deallocating);
	}

	GroupList* deallocating_list_address = remove_group_list_address;

	(*remove_group_list_address) = NULL;

	free(*deallocating_list_address);

	return;
}

// O(1) 
static void ErrorHandingFunction(enum ERROR_CODE code) {
	switch (code)
	{
	case Memorylack: printf("ERROR : MEMORY IS NOT ENOUGH\n\n"); break;
	case DeallocatedList: printf("ERROR : LIST IS DEALLOCATED\n\n"); break;

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
	new_node->prev = NULL;

	return new_node;
}