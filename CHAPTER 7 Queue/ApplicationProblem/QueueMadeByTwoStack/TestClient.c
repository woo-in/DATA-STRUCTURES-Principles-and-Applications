#include "Queue.h"

int main() {
	
	
	Queue k = InitializeQueue();

	

	EnQueue(k, 5);
	DeQueue(k);

	EnQueue(k, 5);
	DeQueue(k);

	EnQueue(k, 5);
	DeQueue(k);

	EnQueue(k, 5);
	DeQueue(k);

	EnQueue(k, 5);
	DeQueue(k);

	EnQueue(k, 1);
	printf("%d", GetFrontItem(k));


	if (IsEmptyQueue(k))
		printf("tes");
	
	RemoveQueue(&k);





	return 0; 
}