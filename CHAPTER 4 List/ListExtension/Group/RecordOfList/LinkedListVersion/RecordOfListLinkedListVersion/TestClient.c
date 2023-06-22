#include "RecordOfListLinkedListVersion.h"

int main() {

	GroupList a = InitGroupList();

	AddLastElementGroupList(a, 1, 'a');
	AddLastElementGroupList(a, 2, 'a');
	AddLastElementGroupList(a, 10, 'b');
	AddLastElementGroupList(a, 20, 'b');
	AddLastElementGroupList(a, 300, 'c');
	AddLastElementGroupList(a, 400, 'c');

	PrintDesignatedElementGroupList(a, 'a');
	RemoveDesignatedElementGroupList(a, 'a');
	PrintDesignatedElementGroupList(a, 'a');
	RemoveDesignatedElementGroupList(a, 'c');
	PrintDesignatedElementGroupList(a, 'd');


	RemoveGroupList(&a); 

	

	return 0; 
}