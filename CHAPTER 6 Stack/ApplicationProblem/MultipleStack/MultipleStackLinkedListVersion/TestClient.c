#include <stdio.h>
#include "MultipleStack.h"


int main() {

	MultipleStack k = InitMultipleStack(5);
	// 1 ~ 5 valid 

	PushMultipleStack(k, 1, 10);
	printf("%d\n", PopMultipleStack(k, 1));

	PushMultipleStack(k, 1, 20);
	printf("%d\n", PopMultipleStack(k, 1));
	





	return 0; 
}