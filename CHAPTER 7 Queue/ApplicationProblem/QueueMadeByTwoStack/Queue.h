#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef int ItemType;
typedef struct QueueType* Queue; // incompelete type of information hiding

Queue InitializeQueue();

bool IsEmptyQueue(Queue current_queue);
ItemType GetFrontItem(Queue current_queue);

void EnQueue(Queue current_queue, const ItemType inserting_item);
ItemType DeQueue(Queue current_queue);

void RemoveQueue(Queue* removing_queue);


#endif 
