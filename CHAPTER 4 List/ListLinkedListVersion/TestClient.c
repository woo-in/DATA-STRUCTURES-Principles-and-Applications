#include <stdio.h>
#include "ListLinkedListVersion.h"

int main() {


	List a  = InitList();
	
	AddFirstElementList(a, 1);
	AddFirstElementList(a, 2);
	AddFirstElementList(a, 3);

	// 3 2 1 


	RemoveLastElementList(a);
	RemoveLastElementList(a);
	RemoveLastElementList(a);

	// 

	AddFirstElementList(a, 1);
	AddFirstElementList(a, 2);
	AddFirstElementList(a, 3);

	// 3 2 1 
	return 0; 
}