#ifndef SET_H
#define SET_H

#include <stdbool.h>

/////////////////////////////////////////////////////////////////////////       
typedef char* ItemType;// user can modify type of data                  // 
///////////////////////////////////////////////////////////////////////// 

typedef struct SetType* Set;

Set InitSet(const int (*sort_criteria)(ItemType a, ItemType b));

int GetSizeSet(const Set existing_set);
bool IsEmpty(const Set existing_set);
void PrintAllElement(const Set existing_set);

void AddElement(Set existing_set, const ItemType item_to_add); 
void RemoveElement(Set existing_set, const ItemType item_to_remove);

bool IsElement(const Set existing_set, const ItemType item_to_check);
bool IsSubset(const Set big_set, const Set checked_set);

Set GetUnionSet(const Set A, const Set B);

void RemoveSet(Set* remove_set_address);

#endif 