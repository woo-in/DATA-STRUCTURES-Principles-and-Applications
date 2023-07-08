#ifndef SET_H_
#define SET_H_

#include <stdbool.h>

typedef struct SetType* Set;

Set InitSet(const int max_set_size);

int GetSizeSet(const Set existing_set);
bool IsEmptySet(const Set existing_set);
void PrintAllElementSet(const Set existing_set);

void AddElementSet(Set existing_set, const int item_to_add);
void RemoveElementSet(Set existing_set, const int item_to_remove);

bool IsElementSet(const Set existing_set, const int item_to_check);
bool IsSubSet(const Set compare_set, const Set checked_set);

Set GetUnionSet(const Set A, const Set B);
Set GetIntersectSet(const Set A, const Set B);
Set GetSubtractSet(const Set A, const Set B);

void RemoveSet(Set* remove_set_address);

#endif
