#include "Queue.h"

int main() {

	Queue k = InitQueue(); 

	EnQueue(k, 1);
	EnQueue(k, 2);
	EnQueue(k, 3);
	EnQueue(k, 4);
	EnQueue(k, 5);
	EnQueue(k, 6);
	EnQueue(k, 7);
	EnQueue(k, 8);
	EnQueue(k, 9);

	for (int i = 0; i < 9; i++) {
		printf("%d\n", DeQueue(k));
	}


	return 0; 
}