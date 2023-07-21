#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Deque.h"


struct DequeType {
	ItemType deque_storage[MAX_DEQUE_LEN];
	int front; 
	int rear;   
};

enum ERROR_CODE { Memorylack, FullDeque, EmptyDeque, DeallocatedDeque };

static void ErrorHandingFunction(enum ERROR_CODE code);

// O(1) 
Deque InitDeque() {
	// allocate deque and init member and return it 
	Deque init_deque = malloc(sizeof(*init_deque));
	if (init_deque == NULL) {
		ErrorHandingFunction(Memorylack);
	}

	// init empty 
	init_deque->front = 1;
	init_deque->rear = 0;

	return init_deque; 
}

// O(1) 
int GetSizeDeque(Deque current_deque) {
	// error handling 
	if (current_deque == NULL) {
		ErrorHandingFunction(DeallocatedDeque);
	}

	// return size
	return (MAX_DEQUE_LEN + current_deque->rear - current_deque->front + 1) % MAX_DEQUE_LEN;
}

// O(1) 
bool IsEmptyDeque(Deque current_deque) {
	// error handling 
	if (current_deque == NULL) {
		ErrorHandingFunction(DeallocatedDeque);
	}

	// if ) r + 1 = f  ==> empty 
	return ((current_deque->rear + 1) % MAX_DEQUE_LEN == current_deque->front);
}

// O(1) 
void InsertRearDeque(Deque current_deque, const ItemType inserting_item) {
	// error handling ( full check )
	if (current_deque == NULL) {
		ErrorHandingFunction(DeallocatedDeque);
	}
	if ((current_deque->rear + 2) % MAX_DEQUE_LEN == current_deque->front) {
		ErrorHandingFunction(FullDeque);
	}

	// rear + 1 --> insert 
	current_deque->rear = (current_deque->rear + 1) % MAX_DEQUE_LEN;
	current_deque->deque_storage[current_deque->rear] = inserting_item;

	return;
}

// O(1) 
ItemType DeleteRearDeque(Deque current_deque) {
	// error handling ( empty check )
	if (current_deque == NULL) {
		ErrorHandingFunction(DeallocatedDeque);
	}
	if ((current_deque->rear + 1) % MAX_DEQUE_LEN == current_deque->front) {
		ErrorHandingFunction(EmptyDeque);
	}

	// extract item --> rear - 1 
	ItemType get_item = current_deque->deque_storage[current_deque->rear];
	current_deque->rear = (current_deque->rear - 1 < 0) ? (MAX_DEQUE_LEN - 1) : (current_deque->rear - 1);

	return get_item; 
}

// O(1) 
void InsertFrontDeque(Deque current_deque, const ItemType inserting_item) {
	// error handling ( full check )
	if (current_deque == NULL) {
		ErrorHandingFunction(DeallocatedDeque);
	}
	if ((current_deque->rear + 2) % MAX_DEQUE_LEN == current_deque->front) {
		ErrorHandingFunction(FullDeque);
	}

	// front - 1 --> insert 
	current_deque->front = (current_deque->front - 1 < 0) ? (MAX_DEQUE_LEN - 1) : (current_deque->front - 1);
	current_deque->deque_storage[current_deque->front] = inserting_item;
}

// O(1) 
ItemType DeleteFrontDeque(Deque current_deque) {
	// error handling ( empty check )
	if (current_deque == NULL) {
		ErrorHandingFunction(DeallocatedDeque);
	}
	if ((current_deque->rear + 1) % MAX_DEQUE_LEN == current_deque->front) {
		ErrorHandingFunction(EmptyDeque);
	}

	// extract item --> front + 1
	ItemType get_item = current_deque->deque_storage[current_deque->front];
	current_deque->front = (current_deque->front + 1) % MAX_DEQUE_LEN;

	return get_item;
}

// O(1) 
ItemType GetFrontItem(Deque current_deque) {
	// error handling ( empty deque )
	if (current_deque == NULL) {
		ErrorHandingFunction(DeallocatedDeque);
	}
	if ((current_deque->rear + 1) % MAX_DEQUE_LEN == current_deque->front) {
		ErrorHandingFunction(EmptyDeque);
	}

	// return item 
	return current_deque->deque_storage[current_deque->front];
}

// O(1) 
ItemType GetRearItem(Deque current_deque) {
	// error handling ( empty deque ) 
	// error handling ( empty deque )
	if (current_deque == NULL) {
		ErrorHandingFunction(DeallocatedDeque);
	}
	if ((current_deque->rear + 1) % MAX_DEQUE_LEN == current_deque->front) {
		ErrorHandingFunction(EmptyDeque);
	}

	// return item 
	return current_deque->deque_storage[current_deque->rear];
}

// O(1)
void RemoveDeque(Deque* removing_deque) {
	// error handling 
	if (*removing_deque == NULL) {
		ErrorHandingFunction(DeallocatedDeque);
	}

	// store NULL and deallocate for dangling pointer 
	Deque deallocating_deque = *removing_deque;
	*removing_deque = NULL;
	free(deallocating_deque);

	return;
}

// O(1) 
static void ErrorHandingFunction(enum ERROR_CODE code) {
	switch (code)
	{
	case Memorylack: printf("ERROR : MEMORY IS NOT ENOUGH\n\n"); break;
	case FullDeque: printf("ERROR : DEQUE IS FULL\n\n"); break;
	case EmptyDeque: printf("ERROR : DEQUE IS  EMPTY\n\n"); break;
	case DeallocatedDeque: printf("ERROR : DEQUE IS DEALLOCATED\n\n"); break;

	default: printf("ERROR : ERROR CODE EXCEPTION\n\n"); break;
	}

	exit(0);
}