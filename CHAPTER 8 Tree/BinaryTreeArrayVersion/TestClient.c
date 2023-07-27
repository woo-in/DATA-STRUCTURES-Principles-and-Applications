#include "Tree.h"
#include <stdio.h>

int main() {

	Tree t = InitializeTree(300, 100);


	SetLeftChildNodeInTree(t, 1, 200);
	SetRightChildNodeInTree(t, 1, 300);

	SetLeftChildNodeInTree(t, 2, 100000);

	SetLeftChildNodeInTree(t, 3, 600);
	SetRightChildNodeInTree(t, 3, 700);

	SetLeftChildNodeInTree(t, 4, 800);


	RemoveTree(&t);
	return 0;
}