#ifndef STACK_H
#define STACK_H

#include <stdbool.h>


typedef int ItemType;
typedef struct StackType* Stack; // incompelete type of information hiding 

Stack InitializeStack();

void PushStack(Stack current_stack, const ItemType pushing_element);
ItemType PopStack(Stack current_stack);

ItemType GetTopElementStack(Stack current_stack);
bool IsEmptyStack(const Stack current_stack);

void RemoveStack(Stack* remove_stack_address);


#endif 