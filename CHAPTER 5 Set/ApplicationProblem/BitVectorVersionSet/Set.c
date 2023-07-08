#include <stdio.h>
#include <stdlib.h>
#include "Set.h"

struct SetType {
	bool* bit_vector; 
	int max_set_size; 
	int set_size; 
};

enum ERROR_CODE { Memorylack, InvalidRank, FullList, EmptyList, DeallocatedList };

// O(N) (calloc) 
Set InitSet(const int max_set_size) {
	// error handling 
	if (max_set_size <= 0) {
		// ERROR_CODE INVALID INTEGER  
	}

	// malloc set structure 
	Set init_set = malloc(sizeof(*init_set));
	if (init_set == NULL) {
		ErrorHandingFunction(Memorylack);
	}

	// calloc bit_vector array 
	bool* storage_array = calloc(sizeof(bool), max_set_size);
	if (storage_array == NULL) {
		ErrorHandingFunction(Memorylack);
	}

	// connect and init 
	init_set->bit_vector = storage_array;
	init_set->max_set_size = max_set_size; 
	init_set->set_size = 0; 

	return init_set; 
}

// O(1) 
int GetSizeSet(const Set existing_set) {
	// error handling 
	if (existing_set == NULL) {
		// ErrorHandingFunction(DeallocatedSet);
	}
	return existing_set->set_size; 
}

// O(1) 
bool IsEmptySet(const Set existing_set) {
	// error handling 
	if (existing_set == NULL) {
		// ErrorHandingFunction(DeallocatedSet);
	}
	return (!existing_set->set_size);
}

// O(N) , N : max_set_size 
void PrintAllElementSet(const Set existing_set) {
	// error handling 
	if (existing_set == NULL) {
		// ErrorHandingFunction(DeallocatedSet);
	}

	// (traverse and print bit_vector index ==> set_element ) if (bit_vector value : true ==> set element ) while ( checked_element < set_size )   
	int checked_elment = 0; 
	for (int i = 0; i < existing_set->max_set_size && checked_elment < existing_set->set_size; i++) {
		if (existing_set->bit_vector[i]) {
			printf("%d ", i); // set_element 
			checked_elment++; 
		}
	}

	return; 
}

// O(1) 
void AddElementSet(Set existing_set, const int item_to_add) {
	// error handling 
	if (existing_set == NULL) {
		// ErrorHandingFunction(DeallocatedSet);
	}

	// error handling 
	if (item_to_add < 0 || item_to_add >= existing_set->set_size) {
		// error : out of range can't mapping integer number ?  
	}

	// error handling 
	if (existing_set->bit_vector[item_to_add]) {
		// error : duplicate add 
	}

	// false --> true 
	existing_set->bit_vector[item_to_add] = true; 
	
	// set_size ++
	existing_set->set_size++; 

	return; 
}

// O(1) 
void RemoveElementSet(Set existing_set, const int item_to_remove) {
	// error handling 
	if (existing_set == NULL) {
		// ErrorHandingFunction(DeallocatedSet);
	}

	// error handling 
	if (item_to_remove < 0 || item_to_remove >= existing_set->set_size) {
		// error : out of range can't mapping integer number ?  
	}

	// error handling 
	if (!existing_set->bit_vector[item_to_remove]) {
		// error : not in set  
	}

	// true --> false  
	existing_set->bit_vector[item_to_remove] = false; 

	// set_size --
	existing_set->set_size--; 

	return; 
}

// O(1) 
bool IsElementSet(const Set existing_set, const int item_to_check) {
	// error handling 
	if (existing_set == NULL) {
		// ErrorHandingFunction(DeallocatedSet);
	}

	// error handling 
	if (item_to_check < 0 || item_to_check >= existing_set->set_size) {
		// error : out of range can't mapping integer number ?  
	}

	// return true or false ( is element of set ? ) 
	return existing_set->bit_vector[item_to_check];

}

// O(N) , N : max_set_size 
bool IsSubSet(const Set compare_set, const Set checked_set) {
	// error check 
	if (compare_set == NULL || checked_set == NULL) {
		// ErrorHandingFunction(DeallocatedSet);
	}
	if (compare_set->max_set_size != checked_set->max_set_size) {
		// ErrorHandingFunction(DifferentKindSet); specify max_set_size 
	}

	// traverse and check checked_set element is in compare_set while ( checked_element < set_size )   
	int checked_elment = 0;
	for (int i = 0; i < checked_set->max_set_size && checked_elment < checked_set->set_size; i++) {
		if (checked_set->bit_vector[i]) {
			if (!compare_set->bit_vector[i]) {
				// checked_set == > true , compare_set ==>false means not subset 
				return false;
			}
			checked_elment++;
		}
	}

	// all of the element is checked  
	return true; 
}

// O(N) , N : max_set_size 
Set GetUnionSet(const Set A, const Set B) {
	// error check 
	if (A == NULL || B == NULL) {
		// ErrorHandingFunction(DeallocatedSet);
	}
	if (A->max_set_size != B->max_set_size) {
		// ErrorHandingFunction(DifferentKindSet); specify max_set_size 
	}

	// make new set
	Set get_set = InitSet(A->max_set_size);

	// traverse and push to new set if( A or B is on ) while all of the bitvector element is checked     
	for (int i = 0; i < A->max_set_size; i++) {
		if (A->bit_vector[i] || B->bit_vector[i]) {
			get_set->bit_vector[i] = true; 
			get_set->set_size++; 
		}
	}
}

// O(N) , N : max_set_size 
Set GetIntersectSet(const Set A, const Set B) {
	// error check 
	if (A == NULL || B == NULL) {
		// ErrorHandingFunction(DeallocatedSet);
	}
	if (A->max_set_size != B->max_set_size) {
		// ErrorHandingFunction(DifferentKindSet); specify max_set_size 
	}

	// make new set
	Set get_set = InitSet(A->max_set_size);

	// traverse and push to new set if( A and B is on ) while all of the bitvector element is checked     
	for (int i = 0; i < A->max_set_size; i++) {
		if (A->bit_vector[i] && B->bit_vector[i]) {
			get_set->bit_vector[i] = true;
			get_set->set_size++;
		}
	}
}

// O(N) , N : max_set_size 
Set GetSubtractSet(const Set A, const Set B) {
	// error check 
	if (A == NULL || B == NULL) {
		// ErrorHandingFunction(DeallocatedSet);
	}
	if (A->max_set_size != B->max_set_size) {
		// ErrorHandingFunction(DifferentKindSet); specify max_set_size 
	}

	// make new set
	Set get_set = InitSet(A->max_set_size);

	// traverse and push to new set if( A and B is on ) while all of the bitvector element is checked     
	for (int i = 0; i < A->max_set_size; i++) {
		if (A->bit_vector[i] && (!B->bit_vector[i])) {
			get_set->bit_vector[i] = true;
			get_set->set_size++;
		}
	}
}

// O(N) , N : max_set_size 
void RemoveSet(Set* remove_set_address) {
	//error handling 
	if (*remove_set_address == NULL) {
		// ErrorHandingFunction(DeallocatedSet);
	}

	// remove BitVector storage array 
	bool* remove_address = (*remove_set_address)->bit_vector;
	bool* remove_address_next = remove_address + 1;
	for (int i = 0; i < (*remove_set_address)->max_set_size - 2; i++) {
		free(remove_address);
		remove_address = remove_address_next; // reuse ( not dangling pointer )
		remove_address_next++;
	}
	free(remove_address); // can't use remove_address ( dangling pointer problem ) 

	// remove BitVector and store NULL for dangling pointer problem 
	Set* deallocating_set_address = remove_set_address;
	(*remove_set_address) = NULL;
	free(*deallocating_set_address);

	return;
}
