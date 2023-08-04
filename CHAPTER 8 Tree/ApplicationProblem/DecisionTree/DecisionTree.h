#ifndef _DECISION_TREE_H
#define _DECISION_TREE_H

#include <stdbool.h>

#define MAX_LENGTH 1000 

typedef char ItemType[MAX_LENGTH]; 

typedef struct TreeType* Tree;

Tree BuildDecisionTree();
void RemoveDecisionTree(Tree* removing_tree);
void RunDecisionTree(Tree decision_tree);


#endif