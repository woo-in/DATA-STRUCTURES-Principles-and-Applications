#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <string.h>
#pragma warning(disable : 4996)

#include "Set.h"


struct Node {
	ItemType item;
	struct Node* prev;
	struct Node* next;
};

struct SetType {
	struct Node* header; 
	int (*sort_criteria) (ItemType a, ItemType b);
	int set_size;
};

enum ERROR_CODE { Memorylack, DifferentKindSet, EmptySet, DeallocatedSet };

static struct Node* Get_Node();
static void ErrorHandingFunction(enum ERROR_CODE code);

// O(1) 
Set InitSet(const int (*sort_criteria)(ItemType a, ItemType b)) {
	// allocate set 
	Set init_set = malloc(sizeof(*init_set));
	if (init_set == NULL) {
		ErrorHandingFunction(Memorylack);
	}

	// allocate header Node 
	init_set->header = Get_Node(); 

	// allocate sort_criteria 
	init_set->sort_criteria = sort_criteria; 

	// init count var 
	init_set->set_size = 0; 

	return init_set; 
}

// O(1)
int GetSizeSet(const Set existing_set) {
	return existing_set->set_size; 
}

// O(1) 
bool IsEmpty(const Set existing_set) {
	return !existing_set->set_size;
}

// O(N) 
void PrintAllElement(const Set existing_set) {
	struct Node* tmpt = existing_set->header->next;

	while (tmpt != NULL) {

		// conversion specification can modify 
		printf("%s ", tmpt->item);

		// traverse 
		tmpt = tmpt->next;
	}

	return;
}

// O(N) , N : element count of set 
void AddElement(Set existing_set, const ItemType item_to_add) {
	// error handling 
	if (existing_set == NULL) {
		ErrorHandingFunction(DeallocatedSet);
	}

	// 1 traverse and select between add new item or not 
	int judge_number = 0; 
	struct Node* prev_node = existing_set->header;
	while (prev_node->next != NULL) {
		//****** sort ascending order ******
		judge_number = existing_set->sort_criteria(prev_node->next->item, item_to_add);
		if (judge_number < 0) {
			// traverse more 
			prev_node = prev_node->next;
		}
		else if (judge_number == 0) {
			// already exist 
			printf("CAN'T ADD : ALREADY EXIST\n");

			return; 
		}
		else {
			// make and connet 
			struct Node* new_node = Get_Node();
			new_node->item = item_to_add; 
			new_node->next = prev_node->next; 
			new_node->prev = prev_node; 

			// modify other section 
			prev_node->next->prev = new_node; 
			prev_node->next = new_node; 

			// set element plus 1 
			existing_set->set_size++; 

			return; 
		}
	}
	// add last of node 
	// make and connet 
	struct Node* new_node = Get_Node();
	new_node->item = item_to_add;
	new_node->next = prev_node->next;
	new_node->prev = prev_node;

	// modify other section 
	prev_node->next = new_node;

	// set element plus 1 
	existing_set->set_size++;

	return; 
}

// O(N) , N : element count of set 
void RemoveElement(Set existing_set, const ItemType item_to_remove) {
	// error handling 
	if (existing_set == NULL) {
		ErrorHandingFunction(DeallocatedSet);
	}

	if (existing_set->set_size == 0) {
		ErrorHandingFunction(EmptySet);
	}

	// 1 traverse and select between remove new item or not 
	int judge_number = 0;
	struct Node* prev_node = existing_set->header;
	while (prev_node->next != NULL) {
		//****** sorted ascending order ******
		judge_number = existing_set->sort_criteria(prev_node->next->item, item_to_remove);
		if (judge_number < 0) {
			// traverse more 
			prev_node = prev_node->next;
		}
		else if (judge_number == 0) {
			// connect other section and remove element 
			struct Node* remove_node = prev_node->next; 
			remove_node->prev->next = remove_node->next; 
			if(remove_node->next != NULL) // except remove node is last element 
				remove_node->next->prev = remove_node->prev; 
			free(remove_node);

			// set element minus 1 
			existing_set->set_size--;

			return;
		}
		else {
			// can't find 
			printf("CAN'T REOMVE : NOT FOUND\n");

			return;
		}
	}

	// can't find 
	printf("CAN'T FIND\n");

	return;
}

// O(N) , N : element count of set 
bool IsElement(const Set existing_set, const ItemType item_to_check) {
	struct Node* tmpt = existing_set->header->next; 
	
	while (tmpt != NULL ) {
		// check same 
		if (existing_set->sort_criteria(tmpt->item, item_to_check) == 0) {
			return true; 
		}
  
		tmpt = tmpt->next;
	}

	return false; 
}

// O( A + B ) , A : element count of compare_set , B : element count of checked_set  
bool IsSubset(const Set compare_set, const Set checked_set) {
	// error check 
	if (compare_set->sort_criteria != checked_set->sort_criteria) {
		ErrorHandingFunction(DifferentKindSet); 
	}

	// checking check_set element one by one 
	struct Node* compare_set_element = compare_set->header->next; 
	struct Node* checked_set_element = checked_set->header->next; 
	int judge_number = 0;
	// while reaching NULL either of them 
	while (checked_set_element != NULL && compare_set_element != NULL) {
		judge_number = compare_set->sort_criteria(compare_set_element->item, checked_set_element->item);

		if (judge_number < 0) { 
			// checked_set element is bigger 
			compare_set_element = compare_set_element->next; 
		}
		else if (judge_number == 0) { 
			// checked_set element is same
			compare_set_element = compare_set_element->next; 
			checked_set_element = checked_set_element->next; 
		}
		else {
			// checked_set element is smaller 
			return false; 
		}
	}

	// all of the element is checked 
	if (checked_set_element == NULL)
		return true;
	else
		return false; 
}

// O( A + B ) , A : element count Set A , B : element count of Set B 
Set GetUnionSet(const Set A, const Set B){

	// error handling 
	if (A == NULL || B == NULL) {
		ErrorHandingFunction(DeallocatedSet);
	}

	// make new set 
	Set get_set = InitSet(A->sort_criteria); 

	// direct add element to set ascending order  
	struct Node* a_set_element = A->header->next;
	struct Node* b_set_element = B->header->next;
	int judge_number = 0;
	struct Node* add_front_point = get_set->header; 
	// while reaching NULL either of them 
	while (a_set_element != NULL && b_set_element != NULL) {
		judge_number = A->sort_criteria(a_set_element->item, b_set_element->item);

		// add smaller element to get_set 
		if (judge_number < 0) {
			// add A  -------------------------
			// make and connet 
			struct Node* new_node = Get_Node();
			new_node->item = a_set_element->item; 
			new_node->next = NULL; 
			new_node->prev = add_front_point; 

			// modify other section 
			add_front_point->next = new_node;

			// set element plus 1 
			get_set->set_size++;

			// renew add_front_point 
			add_front_point = new_node; 
			// --------------------------------

			a_set_element = a_set_element->next; 
		}
		else if (judge_number > 0) {
			// add B  -------------------------
			// make and connet 
			struct Node* new_node = Get_Node();
			new_node->item = b_set_element->item;
			new_node->next = NULL;
			new_node->prev = add_front_point;

			// modify other section 
			add_front_point->next = new_node;

			// set element plus 1 
			get_set->set_size++;

			// renew add_front_point 
			add_front_point = new_node;
			// --------------------------------

			b_set_element = b_set_element->next; 
		}
		else {
			// if same add one of them , both of them go to next node 
			
			// add A or B  -------------------------
			// make and connet 
			struct Node* new_node = Get_Node();
			new_node->item = b_set_element->item;
			new_node->next = NULL;
			new_node->prev = add_front_point;

			// modify other section 
			add_front_point->next = new_node;

			// set element plus 1 
			get_set->set_size++;

			// renew add_front_point 
			add_front_point = new_node;
			// --------------------------------

			a_set_element = a_set_element->next; 
			b_set_element = b_set_element->next;
		}
	}

	// add last of element rear of get_set  
	
	while (a_set_element != NULL) {
		// add A  -------------------------
			// make and connet 
		struct Node* new_node = Get_Node();
		new_node->item = a_set_element->item;
		new_node->next = NULL;
		new_node->prev = add_front_point;

		// modify other section 
		add_front_point->next = new_node;

		// set element plus 1 
		get_set->set_size++;

		// renew add_front_point 
		add_front_point = new_node;
		// --------------------------------

		a_set_element = a_set_element->next;
	}

	while (b_set_element != NULL) {
		// add B  -------------------------
		// make and connet 
		struct Node* new_node = Get_Node();
		new_node->item = b_set_element->item;
		new_node->next = NULL;
		new_node->prev = add_front_point;

		// modify other section 
		add_front_point->next = new_node;

		// set element plus 1 
		get_set->set_size++;

		// renew add_front_point 
		add_front_point = new_node;
		// --------------------------------

		b_set_element = b_set_element->next;
	}
	
	return get_set; 
}

// O( A + B ) , A : element count Set A , B : element count of Set B 
Set GetIntersectSet(const Set A, const Set B) {
	// error handling 
	if (A == NULL || B == NULL) {
		ErrorHandingFunction(DeallocatedSet);
	}

	// make new set 
	Set get_set = InitSet(A->sort_criteria);

	// direct add element to set ascending order  
	struct Node* a_set_element = A->header->next;
	struct Node* b_set_element = B->header->next;
	int judge_number = 0;
	struct Node* add_front_point = get_set->header;
	// while reaching NULL either of them 
	while (a_set_element != NULL && b_set_element != NULL) {
		judge_number = A->sort_criteria(a_set_element->item, b_set_element->item);

		// smaller goes to next node 
		if (judge_number < 0) {
			a_set_element = a_set_element->next;
		}
		else if (judge_number > 0) {
			b_set_element = b_set_element->next;
		}
		else {
			// if same add one of them , both of them go to next node 

			// add A or B  -------------------------
			// make and connet 
			struct Node* new_node = Get_Node();
			new_node->item = b_set_element->item;
			new_node->next = NULL;
			new_node->prev = add_front_point;

			// modify other section 
			add_front_point->next = new_node;

			// set element plus 1 
			get_set->set_size++;

			// renew add_front_point 
			add_front_point = new_node;
			// --------------------------------
			a_set_element = a_set_element->next;
			b_set_element = b_set_element->next;
		}
	}

	return get_set;
}

// O( A + B ) , A : element count Set A , B : element count of Set B 
Set GetSubtractSet(const Set A, const Set B) {
	// error handling 
	if (A == NULL || B == NULL) {
		ErrorHandingFunction(DeallocatedSet);
	}

	// make new set 
	Set get_set = InitSet(A->sort_criteria);

	// direct add element to set ascending order  
	struct Node* a_set_element = A->header->next;
	struct Node* b_set_element = B->header->next;
	int judge_number = 0;
	struct Node* add_front_point = get_set->header;
	// while reaching NULL either of them 
	while (a_set_element != NULL && b_set_element != NULL) {
		judge_number = A->sort_criteria(a_set_element->item, b_set_element->item);

		
		if (judge_number < 0) {
			// A < B 
			// add A  -------------------------
			// make and connet 
			struct Node* new_node = Get_Node();
			new_node->item = a_set_element->item;
			new_node->next = NULL;
			new_node->prev = add_front_point;

			// modify other section 
			add_front_point->next = new_node;

			// set element plus 1 
			get_set->set_size++;

			// renew add_front_point 
			add_front_point = new_node;
			// --------------------------------
			a_set_element = a_set_element->next;
		}
		else if (judge_number > 0) {
			// A > B 
			b_set_element = b_set_element->next;
		}
		else {
			// if same add one of them 
			a_set_element = a_set_element->next;
			b_set_element = b_set_element->next;
		}
	}

	// add last of element rear of get_set
	while (a_set_element != NULL) {
		// add A  -------------------------
			// make and connet 
		struct Node* new_node = Get_Node();
		new_node->item = a_set_element->item;
		new_node->next = NULL;
		new_node->prev = add_front_point;

		// modify other section 
		add_front_point->next = new_node;

		// set element plus 1 
		get_set->set_size++;

		// renew add_front_point 
		add_front_point = new_node;
		// --------------------------------

		a_set_element = a_set_element->next;
	}

	return get_set;
}





// O(N) , N : element count of set 
void RemoveSet(Set* remove_set_address) {
	// error handling 
	if (*remove_set_address == NULL) {
		ErrorHandingFunction(DeallocatedSet);
	}

	// remove Nodes of set 
	struct Node* tmp = (*remove_set_address)->header;
	struct Node* tmp_next = tmp->next;
	while (tmp_next != NULL) {
		free(tmp);
		tmp = tmp_next;
		tmp_next = tmp_next->next;
	}
	free(tmp);

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
	case DifferentKindSet: printf("ERROR : SETS ARE DIFFERENT KIND\n\n"); break;
	case EmptySet: printf("ERROR : SET IS  EMPTY\n\n"); break;
	case DeallocatedSet: printf("ERROR : SET IS DEALLOCATED\n\n"); break;

	default: printf("ERROR : ERROR CODE EXCEPTION\n\n"); break;
	}

	exit(0);
}


