#include "Tree.h"
#include <stdio.h>

int main() {

	Tree t = InitializeTree(7, 100);


	SetLeftChildNodeInTree(t, 1, 200);
	SetRightChildNodeInTree(t, 1, 300);

	SetLeftChildNodeInTree(t, 2, 400);

	SetLeftChildNodeInTree(t, 3, 600);
	SetRightChildNodeInTree(t, 3, 700);


	RemoveExternalNodeInTree(t, 6);
	RemoveExternalNodeInTree(t, 7);
	RemoveExternalNodeInTree(t, 3);

	RemoveExternalNodeInTree(t, 4);
	//RemoveExternalNodeInTree(t, 2);


	if (IsInternalNodeInTree(t, 1))
		printf("yes\n");


	RemoveTree(&t);	
	return 0;
}