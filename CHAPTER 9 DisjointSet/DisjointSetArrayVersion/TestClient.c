#include "DisjointSet.h"
#include <stdio.h>

int main() {


	DisjointSet a = InitializeDisjointSet();

	AddElementInDisjointSet(a, 'A', 1);
	AddElementInDisjointSet(a, 'A', 4);
	AddElementInDisjointSet(a, 'A', 13);

	AddElementInDisjointSet(a, 'B', 2);
	AddElementInDisjointSet(a, 'B', 3);
	AddElementInDisjointSet(a, 'B', 6);
	AddElementInDisjointSet(a, 'B', 9);

	AddElementInDisjointSet(a, 'C', 0);
	AddElementInDisjointSet(a, 'C', 5);
	AddElementInDisjointSet(a, 'C', 8);
	AddElementInDisjointSet(a, 'C', 10);
	AddElementInDisjointSet(a, 'C', 11);


	printf("%c\n", GetSetNameOfElementInDisjointSet(a, 4));
	printf("%c\n", GetSetNameOfElementInDisjointSet(a, 6));
	printf("%c\n", GetSetNameOfElementInDisjointSet(a, 5));

	ChangeAllElementOfSetInDisjointSet(a, 'A', 'B');

	printf("%c\n", GetSetNameOfElementInDisjointSet(a, 4));
	printf("%c\n", GetSetNameOfElementInDisjointSet(a, 6));
	printf("%c\n", GetSetNameOfElementInDisjointSet(a, 5));

	ChangeAllElementOfSetInDisjointSet(a, 'C', 'B');

	printf("%c\n", GetSetNameOfElementInDisjointSet(a, 4));
	printf("%c\n", GetSetNameOfElementInDisjointSet(a, 6));
	printf("%c\n", GetSetNameOfElementInDisjointSet(a, 12));

	RemoveDisjointSet(&a);

	return 0; 
}

