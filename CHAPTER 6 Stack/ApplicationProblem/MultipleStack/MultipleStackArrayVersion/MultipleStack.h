#ifndef MULTIPLE_STACK_H
#define MULTIPLE_STACK_H

#include <stdbool.h>

typedef int ItemType; 

typedef struct MultipleStackType* MultipleStack; // incompelete type of information hiding 

MultipleStack InitMultipleStack(const int total_stack_length, const int stack_count);

int GetSizeMultipleStack(const MultipleStack current_multiple_stack, const int current_multiple_stack_order);
bool IsEmptyMultipleStack(const MultipleStack current_multiple_stack, const int current_multiple_stack_order);
bool IsFullMultipleStack(const MultipleStack current_multiple_stack, const int current_multiple_stack_order);
ItemType GetTopElementMultipleStack(const MultipleStack current_multiple_stack, const int current_multiple_stack_order);

void PushMultipleStack(const MultipleStack current_multiple_stack, const int current_multiple_stack_order, const ItemType pushing_element);
ItemType PopMultipleStack(const MultipleStack current_multiple_stack, const int current_multiple_stack_order);

void RemoveMultipleStack(MultipleStack* remove_multiple_stack_address);

void STATUS(const MultipleStack a);

#endif 