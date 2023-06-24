#include <stdio.h>
#include "ListArrayVersion.h"


int main() {
	List a = InitList();

	AddLastElementList(a, 1);
	AddLastElementList(a, 2);
	AddLastElementList(a, 3);
	AddFirstElementList(a, 0);

	// 0 1 2 3 

	printf("%d\n", RemoveRankElementList(a, 1));
	printf("%d\n", RemoveRankElementList(a, 1));
	printf("%d\n", RemoveRankElementList(a, 1));
	printf("%d\n", RemoveRankElementList(a, 1));

	


	RemoveList(&a);

	
	return 0; 
}