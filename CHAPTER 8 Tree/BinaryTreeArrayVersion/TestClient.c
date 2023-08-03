#include "Tree.h"
#include <stdio.h>
#pragma warning(disable :4996)

int main() {

	Tree t = InitializeTree(300, 100);


	SetLeftChildNodeInTree(t, 1, 200);
	

	SetLeftChildNodeInTree(t, 2, 400);
	SetRightChildNodeInTree(t, 2, 500);

	SetLeftChildNodeInTree(t, 4, 900);
	SetRightChildNodeInTree(t, 4, 1000);

	SetRightChildNodeInTree(t, 5, 600);

	

	







	printf("%d", RomanSize(t, 3));

	RemoveTree(&t);
	return 0;
}