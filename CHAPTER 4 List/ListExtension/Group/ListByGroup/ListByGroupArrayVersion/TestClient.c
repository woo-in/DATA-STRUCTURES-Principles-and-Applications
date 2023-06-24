#include <stdio.h>
#include "ListByGroupArrayVersion.h"

int main() {

	GroupList a = InitGroupList();


	
	AddLastElementGroupList(a, 1, 1);
	AddLastElementGroupList(a, 1, 1);
	//PrintDesignatedElementGroupList(a, 1);
	//PrintDesignatedElementGroupList(a, 2);
	//PrintDesignatedElementGroupList(a, 5);

	//RemoveAllElementDesignatedGroupList(a, 1);
	//PrintDesignatedElementGroupList(a, 1);
	
	
	RemoveGroupList(&a);
	

	return 0; 
}