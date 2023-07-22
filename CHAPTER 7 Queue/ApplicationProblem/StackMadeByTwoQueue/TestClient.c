#include "Stack.h"

int main() {



	Stack s = InitializeStack(); 

	
	PushStack(s, 1);
	PushStack(s, 2);
	PopStack(s);
	PushStack(s, 3);
	PushStack(s, 4);
	PushStack(s, 5);
	PushStack(s, 6);
	PopStack(s);
	PopStack(s);




	printf("%d", GetTopElementStack(s));




	RemoveStack(&s);

	



	return 0; 
}