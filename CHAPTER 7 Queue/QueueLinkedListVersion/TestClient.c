#include "Queue.h"

int main() {

	Queue k = InitQueue(); 

	

	EnQueue(k, 1);
	printf("%d\n", DeQueue(k)); 

	EnQueue(k, 2);
	EnQueue(k, 3);
	EnQueue(k, 4);
	printf("%d\n", DeQueue(k));
	
	EnQueue(k, 5);

	printf("%d\n", DeQueue(k));
	printf("%d\n", DeQueue(k));
	printf("%d\n", GetFrontItem(k));
	printf("%d\n", DeQueue(k));

	EnQueue(k, 100);
	printf("%d", DeQueue(k));

	RemoveQueue(&k);

	EnQueue(k, 1);
	return 0;
}