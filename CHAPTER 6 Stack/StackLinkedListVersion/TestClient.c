#include "Stack.h"
#include <stdio.h>


int main() {


	Stack s1 = InitStack();

	PushStack(s1, 1);
	PushStack(s1, 2);
	PushStack(s1, 3);


	RemoveStack(&s1);
	PopStack(s1);
	



	return 0; 
}