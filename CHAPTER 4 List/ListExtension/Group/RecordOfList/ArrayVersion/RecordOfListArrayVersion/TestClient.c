#include <stdio.h>
#include "RecordOfListArrayVersion.h"

int main() {

	GroupList a = InitGroupList();

	AddLastElementGroupList(a, 1, 'A');
	AddLastElementGroupList(a, 2, 'A');
	AddLastElementGroupList(a, 3, 'A');
	AddLastElementGroupList(a, 4, 'A');
	AddLastElementGroupList(a, 5, 'A');

	RemoveDesignatedElementGroupList(a, 'A');


	//PrintDesignatedElementGroupList(a, 'A'); // null - > 2 

	// 1 2 3 4 5 size = 5 
	// 2 3 4 5 5 size = 4 

	RemoveGroupList(&a);
}