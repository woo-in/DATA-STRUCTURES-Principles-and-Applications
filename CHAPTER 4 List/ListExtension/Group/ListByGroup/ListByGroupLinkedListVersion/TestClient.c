#include "ListByGroupLinkedListVersion.h"

int main() {

	GroupList a = InitGroupList();



	AddLastElementGroupList(a, 1, 1);
	AddLastElementGroupList(a, 1, 1);
	AddLastElementGroupList(a, 2, 2);
	AddLastElementGroupList(a, 2, 2);
	AddLastElementGroupList(a, 3, 3);
	AddLastElementGroupList(a, 3, 3);

	PrintDesignatedElementGroupList(a, 1);
	PrintDesignatedElementGroupList(a, 2);
	PrintDesignatedElementGroupList(a, 3);

	RemoveAllElementDesignatedGroupList(a, 1);
	PrintDesignatedElementGroupList(a, 1);


	RemoveGroupList(&a);
	//PrintDesignatedElementGroupList(a, 1);

	return 0;
}