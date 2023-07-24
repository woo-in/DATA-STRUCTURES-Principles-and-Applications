#ifndef TREE_H
#define TREE_H

#include <stdbool.h>
 
typedef int ItemType;

typedef struct TreeType* Tree;

//

Tree InitDeque();

int GetSizeDeque(Deque current_deque);
bool IsEmptyDeque(Deque current_deque);

ItemType GetFrontItem(Deque current_deque);
ItemType GetRearItem(Deque current_deque);

void InsertRearDeque(Deque current_deque, const ItemType inserting_item);
ItemType DeleteRearDeque(Deque current_deque);
void InsertFrontDeque(Deque current_deque, const ItemType inserting_item);
ItemType DeleteFrontDeque(Deque current_deque);

void RemoveDeque(Deque* removing_deque);

//

#endif