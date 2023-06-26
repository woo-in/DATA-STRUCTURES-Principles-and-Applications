#include <stdio.h>
#include "List.h"

int main() {


	List a  = InitList();
	
	AddFirstElementList(a, 1);
	AddFirstElementList(a, 2);
	AddFirstElementList(a, 3);

	// 3 2 1 


	printf("%d", RemoveRankElementList(a, 1));
	printf("%d", RemoveRankElementList(a, 1));
	

	// 

	// 3 2 1 
	return 0; 
}