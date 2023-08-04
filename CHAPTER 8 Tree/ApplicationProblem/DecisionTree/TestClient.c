#include "DecisionTree.h"
#include <stdio.h>

int main() {

	Tree k = BuildDecisionTree();
	RunDecisionTree(k);
	RemoveDecisionTree(&k);

	return 0; 
}
