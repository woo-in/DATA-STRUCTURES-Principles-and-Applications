#include "Stack.h"
#include <stdio.h>


int main() {


	Stack s1 = InitStack();

	PushStack(s1, 3);

	RemoveStack(&s1);
	



	return 0; 
}