#include "Tree.h"
#include <stdio.h>
#pragma warning(disable :4996)

int main() {

	Tree t = InitializeTree(300, 100);


	SetLeftChildNodeInTree(t, 1, 200);
	SetRightChildNodeInTree(t, 1, 300);

	SetLeftChildNodeInTree(t, 2, 400);
	SetRightChildNodeInTree(t, 2, 500);

	SetLeftChildNodeInTree(t, 4, 900);
	SetRightChildNodeInTree(t, 4, 1000);

	SetRightChildNodeInTree(t, 5, 600);

	SetRightChildNodeInTree(t, 3, 700);

	SetLeftChildNodeInTree(t, 7, 800);

	PostOrderTraverseAndPrintNodeInTree(t, 1);
	printf("\n");

	int node = 0; 
	while (1) {

		scanf("%d", &node);
		printf("%d\n", PostOrderSuccessor(t, node));

	}

	RemoveTree(&t);
	return 0;
}