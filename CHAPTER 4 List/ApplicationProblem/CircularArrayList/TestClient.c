#include <stdio.h>
#include "List.h"

int main() {

	List a = InitList();
	AddRankElementList(a, 1, 10);
	AddRankElementList(a, 2, 20);
	AddRankElementList(a, 3, 30);
	AddRankElementList(a, 1, 20);
	AddRankElementList(a, 2, 40);
	AddRankElementList(a, 5, 50);
	AddRankElementList(a, 6, 60);
	AddRankElementList(a, 7, 70);
	AddRankElementList(a, 8, 80);
	AddRankElementList(a, 9, 90);
	//AddRankElementList(a, 10, 100);
	//printf("%d\n", GetSizeList(a));
	//printf("%d %d %d\n", GetRankElementList(a, 1), GetRankElementList(a, 2), GetRankElementList(a, 3));
	PRINT(a);


	return 0; 
}