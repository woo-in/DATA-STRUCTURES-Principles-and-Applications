#include "ListArrayVersion.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListType {
	ItemType item[MAX_LIST_LENGTH];
	int list_size;
};

// O(1)
List InitList() {
	List init_list = malloc(sizeof(struct ListType));
	if (init_list == NULL) {
		printf("ERROR : MEMORY IS NOT ENOUGH !!\n\n"); 
		exit(1); 
	}
	
	init_list->list_size = 0; 
	return init_list;
}

// O(1)
int GetSizeList(List q_list) {
	return q_list->list_size;
}

// O(1) 
bool IsEmptyList(List q_list) {
	return q_list;
}

// O(1) 
ItemType GetRankElementList(List q_list , int rank) {
	if (rank <= 0 || rank > q_list->list_size || rank > MAX_LIST_LENGTH) {
		printf("ERROR : RANK IS INVALID !!\n\n");
		exit(1);
	}

	return q_list->item[rank - 1];
}

// O(1)
void ChangeRankElementList(List q_list, int rank, ItemType replace_item) {
	if (rank <= 0 || rank > q_list->list_size || rank > MAX_LIST_LENGTH) {
		printf("ERROR : RANK IS INVALID !!\n\n");
		exit(1);
	}

	q_list->item[rank - 1] = replace_item;

	return; 
}

void AddRankElementList(List q_list , int rank , ItemType add_item) { 
	if (rank <= 0 || (rank >= q_list->list_size + 1) || rank > MAX_LIST_LENGTH) {
		printf("ERROR : RANK IS INVALID !!\n\n");
		exit(1);
	}

	if (q_list->list_size + 1 > MAX_LIST_LENGTH) {
		printf("ERROR : LIST IS FULL !!\n\n");
		exit(1);
	}

	// change location and add item 
	int end_index = q_list->list_size - 1;
	int add_index = rank - 1; 
	for (int i = end_index; i >= add_index; i--) {
		q_list->item[i+1] = q_list->item[i];
	}
	q_list->item[add_index] = add_item;

	return; 
}





// O(1) 
void RemoveList(List remove_list) {
	free(remove_list);
	printf("REMOVE LIST SUCCESS , DON'T USE IT !!\n\n");
	return; 
}






