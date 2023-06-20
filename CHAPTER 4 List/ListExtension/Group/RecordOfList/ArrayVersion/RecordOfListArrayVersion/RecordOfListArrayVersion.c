#include "RecordOfListArrayVersion.h"
#include <stdio.h>
#include <stdlib.h>

struct GroupListType {
	ItemType item[MAX_GROUP_LIST_LENGTH];
	GroupType group[MAX_GROUP_LIST_LENGTH]; 
	int group_list_size;
};

enum ERROR_CODE { Memorylack, FullList, EmptyList, DeallocatedList };


// O(1) 
GroupList InitGroupList() {
	GroupList init_Group = malloc(sizeof(GroupList *));
	if (init_Group == NULL) {
		ErrorHandingFunction(Memorylack);
	}

	init_Group->group_list_size = 0;

	return init_Group; 
}

// O(1) 
void AddLastElementGroupList(GroupList q_list, const ItemType add_item , const GroupType add_group) {
	if (q_list == NULL) {
		ErrorHandingFunction(DeallocatedList);
	}

	if (q_list->group_list_size + 1 > MAX_GROUP_LIST_LENGTH) {
		ErrorHandingFunction(FullList);
	}

	q_list->item[q_list->group_list_size] = add_item; // inserting index == before inserting size
	q_list->group[q_list->group_list_size] = add_group; 

	q_list->group_list_size++;

	return;
}

// O(N) , N : group_list_size 
void PrintDesignatedElementGroupList(const GroupList q_list, const GroupType designated_group) {
	if (q_list == NULL) {
		ErrorHandingFunction(DeallocatedList);
	}

	// traverse and print designated_group 
	for (int i = 0; i < q_list->group_list_size; i++) {
		if (q_list->group[i] == designated_group) {
			printf(" %d", q_list->item[i]); 
			// printf conversion specification can modify , when type of item modifies  < check !!!! >    
		}
	}

	printf("\n");

	return; 
}

// O(N^2) , N : group_list_size 
void RemoveDesignatedElementGroupList(GroupList q_list, const GroupType designated_group) {
	if (q_list == NULL) {
		ErrorHandingFunction(DeallocatedList);
	}

	// traverse and delete designated_group 
	for (int i = 0; i < q_list->group_list_size; i++) {
		if (q_list->group[i] == designated_group) {
			for (int j = i + 1; j <= q_list->group_list_size - 1; j++) {
				q_list->group[j - 1] = q_list->group[j];
				q_list->item[j - 1] = q_list->item[j];
			}

			q_list->group_list_size--; // remove element

			i--; // next check point's idx changes to (i - 1)  
		}
	}

	return; 
}

// O(1) 
void RemoveGroupList(GroupList* remove_group_list_address) {
	if (*remove_group_list_address == NULL) {
		ErrorHandingFunction(DeallocatedList);
	}

	GroupList* deallocting_list_address = remove_group_list_address; 

	(*remove_group_list_address) = NULL;

	free(*deallocting_list_address);

	return;
}

// O(1)
static void ErrorHandingFunction(enum ERROR_CODE code) {
	switch (code)
	{
	case Memorylack: printf("ERROR : MEMORY IS NOT ENOUGH\n\n"); break;
	case FullList: printf("ERROR : LIST IS FULL\n\n"); break;
	case EmptyList: printf("ERROR : LIST IS  EMPTY\n\n"); break;
	case DeallocatedList: printf("ERROR : LIST IS DEALLOCATED\n\n"); break;
	default: printf("ERROR : ERROR CODE EXCEPTION\n\n"); break;
	}

	exit(0);
}