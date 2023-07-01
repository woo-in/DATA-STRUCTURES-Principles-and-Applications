#include <stdio.h>
#include "List.h"

int main() {
	List a = InitList();
	AddRankElementList(a, 1, 10);
	AddRankElementList(a, 2, 20);
	AddRankElementList(a, 3, 30);
	ChangeRankElementList(a, 1, 1);
	ChangeRankElementList(a, 2, 2);
	ChangeRankElementList(a, 3, 3);

	printf("%d\n", RemoveRankElementList(a, 3));
	printf("%d\n", RemoveRankElementList(a, 2));
	printf("%d\n", RemoveRankElementList(a, 1));
	
	AddRankElementList(a, 1, 100);
	AddRankElementList(a, 1, 100);
	AddRankElementList(a, 1, 200);

	printf("%d\n", RemoveRankElementList(a, 3));
	printf("%d\n", RemoveRankElementList(a, 2));
	printf("%d\n", RemoveRankElementList(a, 1));

	AddRankElementList(a, 1, 500000);
	printf("%d\n", RemoveRankElementList(a, 1));

	RemoveList(&a);

	AddRankElementList(a, 1, 1);

	


	return 0; 
}