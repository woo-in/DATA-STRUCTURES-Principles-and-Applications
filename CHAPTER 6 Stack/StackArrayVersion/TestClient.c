#include <stdio.h>
#include "Stack.h"

int main() {


	Stack s1 = InitStack(); 

	//GetTopElementStack(s1);

	PushStack(s1, 1);
	PushStack(s1, 2);
	PushStack(s1, 3);
	PushStack(s1, 4);
	PushStack(s1, 5);
	PushStack(s1, 6);
	PushStack(s1, 7);
	PushStack(s1, 8);
	PushStack(s1, 9);
	PushStack(s1, 10);

	printf("%d\n", GetSizeStack(s1));
	printf("%d\n", GetTopElementStack(s1));
	printf("%d\n", PopStack(s1));
	
	printf("%d\n", GetSizeStack(s1));
	printf("%d\n", GetTopElementStack(s1));
	printf("%d\n", PopStack(s1));
	
	printf("%d\n", GetSizeStack(s1));
	printf("%d\n", GetTopElementStack(s1));
	printf("%d\n", PopStack(s1));



	RemoveStack(&s1);

	

	return 0; 
}