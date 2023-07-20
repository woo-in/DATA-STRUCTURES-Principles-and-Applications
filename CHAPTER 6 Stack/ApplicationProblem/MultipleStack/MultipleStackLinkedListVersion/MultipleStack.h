#ifndef MULTIPLE_STACK_H
#define MULTIPLE_STACK_H

#include <stdbool.h>

typedef int ItemType;

typedef struct MultipleStackType* MultipleStack; // incompelete type of information hiding 

MultipleStack InitMultipleStack(const int stack_count);

bool IsEmptyMultipleStack(MultipleStack current_multiple_stack, const int current_multiple_stack_order);
ItemType GetTopElementMultipleStack(MultipleStack current_multiple_stack, const int current_multiple_stack_order);

void PushMultipleStack(MultipleStack current_multiple_stack, const int current_multiple_stack_order, const ItemType pushing_element);
ItemType PopMultipleStack(MultipleStack current_multiple_stack, const int current_multiple_stack_order);

void RemoveMultipleStack(MultipleStack* remove_multiple_stack_address);

#endif 