#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Queue.h"


struct QueueType {
	ItemType queue_storage[MAX_QUEUE_LEN];
	int front; // dequeue
	int rear;  // enqueue 
};

enum ERROR_CODE { Memorylack, FullQueue, EmptyQueue, DeallocatedQueue };

static void ErrorHandingFunction(enum ERROR_CODE code);

// O(1) 
Queue InitQueue() {
	// allocate queue and init member and return it 
	Queue init_queue = malloc(sizeof(*init_queue)); 
	if (init_queue == NULL) {
		ErrorHandingFunction(Memorylack);
	}

	// init empty 
	init_queue->front = 1; 
	init_queue->rear = 0;

	return init_queue; 
}

// O(1) 
int GetSizeQueue(Queue current_queue) {
	// error handling 
	if (current_queue == NULL) {
		ErrorHandingFunction(DeallocatedQueue);
	}

	// return size
	return (MAX_QUEUE_LEN + current_queue->rear - current_queue->front + 1) % MAX_QUEUE_LEN; 
}

// O(1) 
bool IsEmptyQueue(Queue current_queue) {
	// error handling 
	if (current_queue == NULL) {
		ErrorHandingFunction(DeallocatedQueue);
	}

	// if ) r + 1 = f  ==> empty 
	return ((current_queue->rear + 1) % MAX_QUEUE_LEN == current_queue->front);
}

// O(1) 
void EnQueue(Queue current_queue, const ItemType inserting_item) {
	// error handling ( full check )
	if (current_queue == NULL) {
		ErrorHandingFunction(DeallocatedQueue);
	}
	if ((current_queue->rear + 2) % MAX_QUEUE_LEN == current_queue->front) {
		ErrorHandingFunction(FullQueue);
	}

	// rear + 1 --> insert 
	current_queue->rear = (current_queue->rear + 1) % MAX_QUEUE_LEN; 
	current_queue->queue_storage[current_queue->rear] = inserting_item; 

	return; 
}

// O(1) 
ItemType DeQueue(Queue current_queue) {
	// error handling ( empty queue )
	if (current_queue == NULL) {
		ErrorHandingFunction(DeallocatedQueue);
	}
	if ((current_queue->rear + 1) % MAX_QUEUE_LEN == current_queue->front) {
		ErrorHandingFunction(EmptyQueue);
	}

	// extract item --> front + 1
	ItemType get_item = current_queue->queue_storage[current_queue->front];
	current_queue->front = (current_queue->front + 1) % MAX_QUEUE_LEN; 

	return get_item; 
}

// O(1) 
ItemType GetFrontItem(Queue current_queue) {
	// error handling ( empty queue )
	if (current_queue == NULL) {
		ErrorHandingFunction(DeallocatedQueue);
	}
	if ((current_queue->rear + 1) % MAX_QUEUE_LEN == current_queue->front) {
		ErrorHandingFunction(EmptyQueue);
	}

	// return item 
	return current_queue->queue_storage[current_queue->front];
}




// O(1)
void RemoveQueue(Queue* removing_queue) {
	// error handling 
	if (*removing_queue == NULL) {
		ErrorHandingFunction(DeallocatedQueue);
	}

	// store NULL and deallocate for dangling pointer 
	Queue deallocating_queue = *removing_queue; 
	*removing_queue = NULL; 
	free(deallocating_queue); 

	return; 
}

// O(1) 
static void ErrorHandingFunction(enum ERROR_CODE code) {
	switch (code)
	{
	case Memorylack: printf("ERROR : MEMORY IS NOT ENOUGH\n\n"); break;
	case FullQueue: printf("ERROR : QUEUE IS FULL\n\n"); break;
	case EmptyQueue: printf("ERROR : QUEUE IS  EMPTY\n\n"); break;
	case DeallocatedQueue: printf("ERROR : QUEUE IS DEALLOCATED\n\n"); break;

	default: printf("ERROR : ERROR CODE EXCEPTION\n\n"); break;
	}

	exit(0);
}