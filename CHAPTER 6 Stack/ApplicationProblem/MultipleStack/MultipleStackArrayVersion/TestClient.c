#include "MultipleStack.h"

int main() {

	MultipleStack k = InitMultipleStack(10, 5); // 1 2 3 4 5


	
	PushMultipleStack(k, 1, 1);
	PopMultipleStack(k, 1);
	PushMultipleStack(k, 2, 2);
	PushMultipleStack(k, 2, 2);

	printf("%d\n", PopMultipleStack(k, 1));
	



	
	



	return 0; 
}