#include "Deque.h"


int main() {

	Deque k = InitDeque(); 

	
	InsertFrontDeque(k, 2);
	InsertFrontDeque(k, 3);
	InsertFrontDeque(k, 4);
	InsertFrontDeque(k, 5);
	InsertFrontDeque(k, 6);
	InsertFrontDeque(k, 7);
	
	printf("%d %d %d", GetSizeDeque(k), GetFrontItem(k), GetRearItem(k));

	// 7 6 5 4 3 2  






	return 0; 
}