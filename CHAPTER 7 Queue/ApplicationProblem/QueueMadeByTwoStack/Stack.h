#ifndef STACK_H
#define STACK_H



#include <stdbool.h>

/////////////////////////////////////////////////////////////////////////    
typedef int ItemType;// user can modify type of item                   // 
///////////////////////////////////////////////////////////////////////// 


typedef struct StackType* Stack; // incompelete type of information hiding 

Stack InitStack();

void PushStack(Stack current_stack, ItemType pushing_element);
ItemType PopStack(Stack current_stack);

ItemType GetTopElementStack(const Stack current_stack);
int GetSizeStack(const Stack current_stack);
bool IsEmptyStack(const Stack current_stack);

void RemoveStack(Stack* remove_stack_address);

static void ErrorHandingFunction(enum ERROR_CODE code);

#endif 