#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Queue.h"

struct Node {
	ItemType item;
	struct Node* next;
};

struct QueueType {
	struct Node* front;  
	struct Node* rear; 
};

enum ERROR_CODE { Memorylack, EmptyQueue, DeallocatedQueue };

static void ErrorHandingFunction(enum ERROR_CODE code);
static struct Node* Get_Node();

// O(1) 
Queue InitQueue() {
	// allocate queue and init member and return it 
	Queue init_queue = malloc(sizeof(*init_queue));
	if (init_queue == NULL) {
		ErrorHandingFunction(Memorylack);
	}

	// init NULL 
	init_queue->front = NULL;  
	init_queue->rear = NULL; 

	// return 
	return init_queue;
}

// O(1) 
bool IsEmptyQueue(Queue current_queue) {
	// error handling 
	if (current_queue == NULL) {
		ErrorHandingFunction(DeallocatedQueue);
	}

	// if ) r == NULL or f == NULL ==> empty 
	return (current_queue->front == NULL);
}

// O(1) 
void EnQueue(Queue current_queue, const ItemType inserting_item) {
	// error handling ( full check )
	if (current_queue == NULL) {
		ErrorHandingFunction(DeallocatedQueue);
	}

	// make node 
	struct Node* insert_node = Get_Node();
	insert_node->item = inserting_item; 

	if (current_queue->rear == NULL) {
		// case 1) first enqueue 
		current_queue->front = insert_node;
		current_queue->rear = insert_node;
	}
	else {
		// case 2) not first enqueue 
		current_queue->rear->next = insert_node; 
		current_queue->rear = insert_node; 

	}
	return; 
}

// O(1) 
ItemType DeQueue(Queue current_queue) {
	// error handling ( empty queue )
	if (current_queue == NULL) {
		ErrorHandingFunction(DeallocatedQueue);
	}
	if (current_queue->front == NULL) {
		ErrorHandingFunction(EmptyQueue);
	}

	// ready 
	ItemType get_item = current_queue->front->item; 
	struct Node* tmp = NULL; 

	if (current_queue->front->next == NULL) {
		// case 1) after dequeue ==> NULL
		free(current_queue->front); 
		current_queue->front = NULL; 
		current_queue->rear = NULL; 
	}
	else {
		// case 2) after dequeue ==> not NULL 
		tmp = current_queue->front->next; 
		free(current_queue->front); 
		current_queue->front = tmp; 
	}

	return get_item; 
}

// O(1) 
ItemType GetFrontItem(Queue current_queue) {
	// error handling ( empty queue )
	if (current_queue == NULL) {
		ErrorHandingFunction(DeallocatedQueue);
	}
	if (current_queue->rear == NULL) {
		ErrorHandingFunction(EmptyQueue);
	}

	// return item 
	return current_queue->front->item; 
}

// O(N) , N : stored element
void RemoveQueue(Queue* removing_queue) {
	// error handling 
	if (*removing_queue == NULL) {
		ErrorHandingFunction(DeallocatedQueue);
	}

	// deallocate stored element 
	if ((*removing_queue)->front != NULL) {
		struct Node* tmp = (*removing_queue)->front; 
		struct Node* tmp_next = tmp->next;
		while (tmp_next != NULL) {
			free(tmp);
			tmp = tmp_next;
			tmp_next = tmp_next->next;
		}
		free(tmp);
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
	case EmptyQueue: printf("ERROR : QUEUE IS  EMPTY\n\n"); break;
	case DeallocatedQueue: printf("ERROR : QUEUE IS DEALLOCATED\n\n"); break;

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

	// init next 
	new_node->next = NULL;

	return new_node;
}