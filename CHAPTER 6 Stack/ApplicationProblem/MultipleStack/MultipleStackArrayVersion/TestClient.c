#include "MultipleStack.h"

int main() {

	MultipleStack k = InitMultipleStack(10, 10); // 1 2 3 4 5


	
	PushMultipleStack(k, 2, 6);
	PushMultipleStack(k, 1, 10);

	PushMultipleStack(k, 1, 101);
	PopMultipleStack(k, 1);
	PopMultipleStack(k, 1);

	PushMultipleStack(k, 5, 10);
	PushMultipleStack(k, 5, 11);
	PushMultipleStack(k, 6, 1);
	PushMultipleStack(k, 6, 2);
	PushMultipleStack(k, 6, 3);
	PushMultipleStack(k, 9, 10);
	PushMultipleStack(k, 9, 11);

	STATUS(k);

	
	



	return 0; 
}