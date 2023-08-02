#ifndef TREE_H
#define TREE_H

#include <stdbool.h>
 
typedef int ItemType;

typedef struct TreeType* Tree;

Tree InitializeTree(const int max_tree_len, const int root_node_item);
void RemoveTree(Tree* removing_tree);

bool IsEmptyTree(Tree current_tree);
int GetSizeOfTree(Tree current_tree);

ItemType GetRootNodeItemOfTree(Tree current_tree);
ItemType GetParentNodeItemInTree(Tree current_tree, const int node_index);
ItemType GetLeftChildrenNodeItemInTree(Tree current_tree, const int node_index);
ItemType GetRightChildrenNodeItemInTree(Tree current_tree, const int node_index);
ItemType GetNodeItemInTree(Tree current_tree, const int node_index);

bool IsInternalNodeInTree(Tree current_tree, const int node_index);
bool IsExternalNodeInTree(Tree current_tree, const int node_index);


void SetLeftChildNodeInTree(Tree current_tree, const int node_index, const ItemType left_child_item);
void SetRightChildNodeInTree(Tree current_tree, const int node_index, const ItemType right_child_item);
void SwapNodeItemInTree(Tree current_tree, const int node_index_swap1, const int node_index_swap2);
ItemType RemoveExternalNodeInTree(Tree current_tree, const int node_index);

int GetDepthOfNodeInTree(Tree current_tree, const int node_index); 
int GetHeightOfNodeInTree(Tree current_tree, const int node_index); 

void PreOrderTraverseAndPrintNodeInTree(Tree current_tree, const int node_index); 
void PostOrderTraverseAndPrintNodeInTree(Tree current_tree, const int node_index); 
void InOrderTraverseAndPrintNodeInTree(Tree current_tree, const int node_index); 
void LevelOrderTraverseAndPrintNodeInTree(Tree current_tree, const int node_index);
void EulerOrderTraverseAndPrintNodeInTree(Tree current_tree, const int node_index);




////////////////////////////////////////////////////////      ApplicationProblem       //////////////////////////////////////////////////////////////

// 1. Successor 

int PreOrderSuccessor(Tree current_tree, const int node_index); 
int InOrderSuccessor(Tree current_tree, const int node_index); 
int PostOrderSuccessor(Tree current_tree, const int node_index); 

#endif