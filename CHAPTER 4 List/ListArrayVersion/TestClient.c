#include <stdio.h>
#include "ListArrayVersion.h"


int main() {
	List a = InitList();

	AddLastElementList(a, 1);
	AddLastElementList(a, 2);
	AddLastElementList(a, 3);
	AddLastElementList(a, 4);
	AddLastElementList(a, 5);
	AddLastElementList(a, 6);

	printf("%d", RemoveLastElementList(a));



	//RemoveFirstElementList(a);	
	RemoveList(&a);

	
	return 0; 
}