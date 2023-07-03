#include <stdio.h>
#include "List.h"

int main() {


	List a  = InitList();
	
	AddFirstElementList(a, 1);
	printf("%d\n", RemoveFirstElementList(a, 1));
	AddFirstElementList(a, 2);
	printf("%d\n", RemoveFirstElementList(a, 1));
	AddFirstElementList(a, 3);
	printf("%d\n", RemoveFirstElementList(a, 1));

	// 3 2 1 


	
	

	// 
	RemoveList(&a);

	AddLastElementList(a, 11);

	// 3 2 1 
	return 0; 
}