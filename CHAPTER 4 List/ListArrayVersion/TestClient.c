#include <stdio.h>
#include "ListArrayVersion.h"


int main() {
	List a = InitList();

	AddFirstElementList(a, 10);
	AddFirstElementList(a, 9);
	AddFirstElementList(a, 8);
	AddFirstElementList(a, 7);
	AddFirstElementList(a, 6);

	AddFirstElementList(a, 5);
	AddFirstElementList(a, 4);
	AddFirstElementList(a, 3);
	AddFirstElementList(a, 2);
	AddFirstElementList(a, 1);



	TemptPrint(a); 

	RemoveList(&a);

	


}