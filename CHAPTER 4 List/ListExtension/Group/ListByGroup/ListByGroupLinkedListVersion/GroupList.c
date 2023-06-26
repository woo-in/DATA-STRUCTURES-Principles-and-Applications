/* Group List List By Group Linked List Version */
#include <stdio.h>
#include <stdlib.h>
#include "GroupList.h"
#include "List.h" 

struct GroupListType {
	List group[MAX_GROUP_LENGTH];
};

enum ERROR_CODE { Memorylack, DeallocatedList, InvalidGroup };

// O(N) , N : setted MAX_GROUP_LENGTH 
GroupList InitGroupList() {
	GroupList init_list = malloc(sizeof(GroupList*));
	if (init_list == NULL) {
		ErrorHandingFunction(Memorylack);
	}

	for (int i = 0; i < MAX_GROUP_LENGTH; i++) {
		init_list->group[i] = InitList();
	}

	return init_list;
}


// O(1) 
void AddLastElementGroupList(GroupList q_list, const ItemType add_item, const int designated_group) {
	if (q_list == NULL) {
		ErrorHandingFunction(DeallocatedList);
	}

	if (!(1 <= designated_group && designated_group <= MAX_GROUP_LENGTH))
		ErrorHandingFunction(InvalidGroup);

	int group_idx = designated_group - 1;
	AddLastElementList(q_list->group[group_idx], add_item);

	return;
}


// O(N^2) , N : designated_group_size
// for optimization ---> should customize
// if ListLinkedListVersion have traverse function ---> O(N) 
void PrintDesignatedElementGroupList(const GroupList q_list, const int designated_group) {
	if (q_list == NULL) {
		ErrorHandingFunction(DeallocatedList);
	}

	if (!(1 <= designated_group && designated_group <= MAX_GROUP_LENGTH))
		ErrorHandingFunction(InvalidGroup);

	printf("GROUP %d :", designated_group);

	// traverse and print designated_group 
	int group_idx = designated_group - 1;
	for (int i = 1; i <= GetSizeList(q_list->group[group_idx]); i++) {
		printf(" %d", GetRankElementList(q_list->group[group_idx], i));
		// printf conversion specification can modify , if type of item modified  < check !!!! >    
	}

	printf("\n");

	return;
}

// O(N) , N : designated_group_size  
void RemoveAllElementDesignatedGroupList(GroupList q_list, const int designated_group) {
	if (q_list == NULL) {
		ErrorHandingFunction(DeallocatedList);
	}

	if (!(1 <= designated_group && designated_group <= MAX_GROUP_LENGTH))
		ErrorHandingFunction(InvalidGroup);

	int group_idx = designated_group - 1;
	while (!IsEmptyList(q_list->group[group_idx]))
		RemoveLastElementList(q_list->group[group_idx]);

	return;
}

// O(N) , N : setted MAX_GROUP_LENGTH 
void RemoveGroupList(GroupList* remove_group_list_address) {
	if (*remove_group_list_address == NULL) {
		ErrorHandingFunction(DeallocatedList);
	}

	for (int i = 0; i < MAX_GROUP_LENGTH; i++) {
		RemoveList(&(*remove_group_list_address)->group[i]);
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
	case InvalidGroup: printf("ERROR : GROUP IS INVALID\n\n"); break;
	case DeallocatedList: printf("ERROR : LIST IS DEALLOCATED\n\n"); break;

	default: printf("ERROR : ERROR CODE EXCEPTION\n\n"); break;
	}

	exit(0);
}
