#include <stdio.h>
#include "ListByGroupArrayVersion.h"

int main() {

	GroupList a = InitGroupList();


	
	AddLastElementGroupList(a, 1, 1);
	AddLastElementGroupList(a, 2, 1);

	AddLastElementGroupList(a, 3, 2);
	AddLastElementGroupList(a, 4, 2);

	AddLastElementGroupList(a, 5, 3);
	
	//PrintDesignatedElementGroupList(a, 1);
	//PrintDesignatedElementGroupList(a, 2);
	//PrintDesignatedElementGroupList(a, 5);

	//RemoveAllElementDesignatedGroupList(a, 1);
	//PrintDesignatedElementGroupList(a, 1);
	
	
	RemoveGroupList(&a);
	

	return 0; 
}