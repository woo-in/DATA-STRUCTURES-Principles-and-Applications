#include "Tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeType {
	ItemType* tree_array_address; 
	int max_tree_len; // use ? 
};

enum ERROR_CODE { Memorylack, InvalidMaxTreeLength, InvalidIndex, EmptyNode, EmptyRootNode, RemoveRootNode, ParentOfRootNode, RemoveInternalNode, DeallocatedTree };

static int GetSizeOfSubTree(Tree current_tree, const int sub_tree_root_index); 
static void ErrorHandingFunction(enum ERROR_CODE code);


// O(N) , N : max_tree_len 
Tree InitializeTree(const int max_tree_len , const int root_node_item) {
	// error handling 
	if (max_tree_len <= 0) {
		ErrorHandingFunction(InvalidMaxTreeLength);
	}

	// allocate Tree
	Tree init_tree = malloc(sizeof(*init_tree));
	if (init_tree == NULL) {
		ErrorHandingFunction(Memorylack);
	}

	// allocate Tree Array [max_tree_len + 1] ( for use index 1 ~ max_tree_len )  
	ItemType* tree_array_address = malloc(sizeof(*tree_array_address) * (max_tree_len + 1)); 
	if (tree_array_address == NULL) {
		ErrorHandingFunction(Memorylack);
	}

	// store '#' for sign NULL ( index 1 ~ max_tree_len ) 
	for (int i = 1; i <= max_tree_len; i++) {
		tree_array_address[i] = '#';
	}

	// set root node item 
	tree_array_address[1] = root_node_item; 

	// connect 
	init_tree->tree_array_address = tree_array_address; 
	init_tree->max_tree_len = max_tree_len; 

	// return 
	return init_tree; 
}

// O(1) 
bool IsEmptyTree(Tree current_tree) {
	// error handling 
	if (current_tree == NULL) {
		ErrorHandingFunction(DeallocatedTree);
	}

	// check root node 
	return (current_tree->tree_array_address[1] == '#');
}

// O(N) , N : size of current_tree  3 * O(N) 
// It can be Euler Tour... ?  
int GetSizeOfTree(Tree current_tree) {
	// error handling 
	if (current_tree == NULL) {
		ErrorHandingFunction(DeallocatedTree);
	}
	return GetSizeOfSubTree(current_tree, 1);
}

static int GetSizeOfSubTree(Tree current_tree, const int sub_tree_root_index) {
	// error handling 
	if (current_tree == NULL) {
		ErrorHandingFunction(DeallocatedTree);
	}
	if (sub_tree_root_index < 1 || sub_tree_root_index > current_tree->max_tree_len) {
		ErrorHandingFunction(InvalidIndex);
	}
	if (current_tree->tree_array_address[sub_tree_root_index] == '#') {
		ErrorHandingFunction(EmptyNode);
	}


	// pre of traverse  
	int size_of_sub_tree = 1; 
	

	// traverse left_child (if exist) 
	int left_child_index = sub_tree_root_index * 2;
	if (left_child_index <= current_tree->max_tree_len && current_tree->tree_array_address[left_child_index] != '#') {
		// left child exist 
		size_of_sub_tree += GetSizeOfSubTree(current_tree, left_child_index);
	}

	// in of traverse 

	// traverse right_child (if exist)
	int right_child_index = sub_tree_root_index * 2 + 1;
	if (right_child_index <= current_tree->max_tree_len && current_tree->tree_array_address[right_child_index] != '#') {
		// right child exist 
		size_of_sub_tree += GetSizeOfSubTree(current_tree, right_child_index);
	}

	
	// post of traverse 
	// return size 
	return size_of_sub_tree; 
}

// O(1) 
ItemType GetRootNodeItemOfTree(Tree current_tree) {
	// error handling 
	if (current_tree == NULL) {
		ErrorHandingFunction(DeallocatedTree);
	}
	if (current_tree->tree_array_address[1] == '#') {
		ErrorHandingFunction(EmptyRootNode);
	}

	// return [1] 
	return current_tree->tree_array_address[1]; 
}

// O(1)
ItemType GetParentNodeItemInTree(Tree current_tree, const int node_index) {
	// error handling 
	if (current_tree == NULL) {
		ErrorHandingFunction(DeallocatedTree);
	}
	if (node_index < 1 || node_index > current_tree->max_tree_len) {
		ErrorHandingFunction(InvalidIndex);
	}
	if (current_tree->tree_array_address[node_index] == '#') {
		ErrorHandingFunction(EmptyRootNode);
	}
	if (node_index == 1) {
		ErrorHandingFunction(ParentOfRootNode);
	}
	int parent_index = node_index / 2;
	if (parent_index > current_tree->max_tree_len) {
		ErrorHandingFunction(InvalidIndex);
	}


	// return [parent_index] 
	return current_tree->tree_array_address[parent_index];
}

// O(1) 
ItemType GetLeftChildrenNodeItemInTree(Tree current_tree, const int node_index) {
	// error handling 
	if (current_tree == NULL) {
		ErrorHandingFunction(DeallocatedTree);
	}
	if (node_index < 1 || node_index > current_tree->max_tree_len) {
		ErrorHandingFunction(InvalidIndex);
	}
	if (current_tree->tree_array_address[node_index] == '#') {
		ErrorHandingFunction(EmptyRootNode);
	}
	int left_child_index = node_index * 2;
	if (left_child_index > current_tree->max_tree_len) {
		ErrorHandingFunction(InvalidIndex);
	}
	if (current_tree->tree_array_address[left_child_index] == '#') {
		ErrorHandingFunction(EmptyNode);
	}

	// return [left_child_index] 
	return current_tree->tree_array_address[left_child_index];
}

// O(1) 
ItemType GetRightChildrenNodeItemInTree(Tree current_tree, const int node_index) {
	// error handling 
	if (current_tree == NULL) {
		ErrorHandingFunction(DeallocatedTree);
	}
	if (node_index < 1 || node_index > current_tree->max_tree_len) {
		ErrorHandingFunction(InvalidIndex);
	}
	if (current_tree->tree_array_address[node_index] == '#') {
		ErrorHandingFunction(EmptyRootNode);
	}
	int right_child_index = node_index * 2 + 1; 
	if (right_child_index > current_tree->max_tree_len) {
		ErrorHandingFunction(InvalidIndex);
	}
	if (current_tree->tree_array_address[right_child_index] == '#') {
		ErrorHandingFunction(EmptyNode);
	}

	// return [right_child_index] 
	return current_tree->tree_array_address[right_child_index];
}

// O(1) 
ItemType GetNodeItemInTree(Tree current_tree, const int node_index) {
	// error handling 
	if (current_tree == NULL) {
		ErrorHandingFunction(DeallocatedTree);
	}
	if (node_index < 1 || node_index > current_tree->max_tree_len) {
		ErrorHandingFunction(InvalidIndex);
	}
	if (current_tree->tree_array_address[node_index] == '#') {
		ErrorHandingFunction(EmptyNode);
	}

	// return [node_index] 
	return current_tree->tree_array_address[node_index];
}

// O(1) 
bool IsInternalNodeInTree(Tree current_tree, const int node_index) {
	// error handling 
	if (current_tree == NULL) {
		ErrorHandingFunction(DeallocatedTree);
	}
	if (node_index < 1 || node_index > current_tree->max_tree_len) {
		ErrorHandingFunction(InvalidIndex);
	}
	if (current_tree->tree_array_address[node_index] == '#') {
		ErrorHandingFunction(EmptyNode);
	}

	// check having at least one child 
	int left_child_index = node_index * 2; 
	int right_child_index = node_index * 2 + 1; 
	return (left_child_index <= current_tree->max_tree_len && current_tree->tree_array_address[left_child_index] != '#') ||
		   (right_child_index <= current_tree->max_tree_len && current_tree->tree_array_address[right_child_index] != '#');
}

// O(1) 
bool IsExternalNodeInTree(Tree current_tree, const int node_index) {
	// error handling 
	if (current_tree == NULL) {
		ErrorHandingFunction(DeallocatedTree);
	}
	if (node_index < 1 || node_index > current_tree->max_tree_len) {
		ErrorHandingFunction(InvalidIndex);
	}
	if (current_tree->tree_array_address[node_index] == '#') {
		ErrorHandingFunction(EmptyNode);
	}

	// check having no child 
	int left_child_index = node_index * 2;
	int right_child_index = node_index * 2 + 1;
	return (left_child_index > current_tree->max_tree_len || current_tree->tree_array_address[left_child_index] == '#') &&
		   (right_child_index > current_tree->max_tree_len || current_tree->tree_array_address[right_child_index] == '#');
}

// O(1) 
void SetLeftChildNodeInTree(Tree current_tree, const int node_index, const ItemType left_child_item) {
	// error handling 
	if (current_tree == NULL) {
		ErrorHandingFunction(DeallocatedTree);
	}
	if (node_index < 1 || node_index > current_tree->max_tree_len) {
		ErrorHandingFunction(InvalidIndex);
	}
	if (current_tree->tree_array_address[node_index] == '#') {
		ErrorHandingFunction(EmptyNode);
	}
	int left_child_index = node_index * 2;
	if (left_child_index > current_tree->max_tree_len) {
		ErrorHandingFunction(InvalidIndex);
	}
	

	// set 
	current_tree->tree_array_address[left_child_index] = left_child_item; 

	return; 
}

// O(1) 
void SetRightChildNodeInTree(Tree current_tree, const int node_index, const ItemType right_child_item) {
	// error handling 
	if (current_tree == NULL) {
		ErrorHandingFunction(DeallocatedTree);
	}
	if (node_index < 1 || node_index > current_tree->max_tree_len) {
		ErrorHandingFunction(InvalidIndex);
	}
	if (current_tree->tree_array_address[node_index] == '#') {
		ErrorHandingFunction(EmptyNode);
	}
	int right_child_index = node_index * 2 + 1; 
	if (right_child_index > current_tree->max_tree_len) {
		ErrorHandingFunction(InvalidIndex);
	}
	
	// set 
	current_tree->tree_array_address[right_child_index] = right_child_item; 

	return;
}

// O(1) 
void SwapNodeItemInTree(Tree current_tree, const int node_index_swap1, const int node_index_swap2) {
	// error handling 
	if (current_tree == NULL) {
		ErrorHandingFunction(DeallocatedTree);
	}
	if ((node_index_swap1 < 1 || node_index_swap1 > current_tree->max_tree_len) || (node_index_swap2 < 1 || node_index_swap2 > current_tree->max_tree_len)) {
		ErrorHandingFunction(InvalidIndex);
	}
	if (current_tree->tree_array_address[node_index_swap1] == '#' || current_tree->tree_array_address[node_index_swap2] == '#') {
		ErrorHandingFunction(EmptyNode);
	}

	// swap 
	ItemType tmpt = current_tree->tree_array_address[node_index_swap1];
	current_tree->tree_array_address[node_index_swap1] = current_tree->tree_array_address[node_index_swap2]; 
	current_tree->tree_array_address[node_index_swap2] = tmpt; 

	return; 
}

// O(1) 
ItemType RemoveExternalNodeInTree(Tree current_tree, const int node_index) {
	// error handling 
	if (current_tree == NULL) {
		ErrorHandingFunction(DeallocatedTree);
	}
	if (node_index < 1 || node_index > current_tree->max_tree_len) {
		ErrorHandingFunction(InvalidIndex);
	}
	if (node_index == 1) {
		ErrorHandingFunction(RemoveRootNode);
	}
	if (current_tree->tree_array_address[node_index] == '#') {
		ErrorHandingFunction(EmptyNode);
	}
	// check internal node 
	int left_child_index = node_index * 2;
	int right_child_index = node_index * 2 + 1;
	if ((left_child_index <= current_tree->max_tree_len && current_tree->tree_array_address[left_child_index] != '#') ||
		(right_child_index <= current_tree->max_tree_len && current_tree->tree_array_address[right_child_index] != '#')) {
		ErrorHandingFunction(RemoveInternalNode); 
	}

	// store removing node item and remove(store item '#') and return
	ItemType get_item = current_tree->tree_array_address[node_index];
	current_tree->tree_array_address[node_index] = '#';
	return get_item; 
}

// O(N) , N : node count 
int GetDepthOfNodeInTree(Tree current_tree, const int node_index) {
	// error handling 
	if (current_tree == NULL) {
		ErrorHandingFunction(DeallocatedTree);
	}
	if (node_index < 1 || node_index > current_tree->max_tree_len) {
		ErrorHandingFunction(InvalidIndex);
	}
	if (current_tree->tree_array_address[node_index] == '#') {
		ErrorHandingFunction(EmptyNode);
	}

	// exit condition 
	if (node_index == 1) {
		// root node 
		return 0; 
	}
	// recursion 
	return GetDepthOfNodeInTree(current_tree, node_index / 2) + 1; 
}

// O(N) , N : node count 
int GetHeightOfNodeInTree(Tree current_tree, const int node_index) {
	// error handling 
	if (current_tree == NULL) {
		ErrorHandingFunction(DeallocatedTree);
	}
	if (node_index < 1 || node_index > current_tree->max_tree_len) {
		ErrorHandingFunction(InvalidIndex);
	}
	if (current_tree->tree_array_address[node_index] == '#') {
		ErrorHandingFunction(EmptyNode);
	}

	// recursion 
	int left_child_index = node_index * 2;
	int right_child_index = node_index * 2 + 1;
	bool is_external_node = true; 
	int left_child_height = 0; 
	if (left_child_index <= current_tree->max_tree_len && current_tree->tree_array_address[left_child_index] != '#') {
		// left child exist 
		left_child_height = GetHeightOfNodeInTree(current_tree, left_child_index);
		is_external_node = false; 
	}
	int right_child_height = 0; 
	if (right_child_index <= current_tree->max_tree_len && current_tree->tree_array_address[right_child_index] != '#') {
		// right child exist 
		right_child_height = GetHeightOfNodeInTree(current_tree, right_child_index);
		is_external_node = false; 
	}
	
	// exit condition 
	if (is_external_node)
		return 0; 

	return ((left_child_height > right_child_height) ? left_child_height : right_child_height) + 1; 
}

// O(N) , N : node count 
void PreOrderTraverseAndPrintNodeInTree(Tree current_tree, const int node_index) {
	// error handling 
	if (current_tree == NULL) {
		ErrorHandingFunction(DeallocatedTree);
	}
	if (node_index < 1 || node_index > current_tree->max_tree_len) {
		ErrorHandingFunction(InvalidIndex);
	}
	if (current_tree->tree_array_address[node_index] == '#') {
		ErrorHandingFunction(EmptyNode);
	}

	// print first node_index 
	printf("%d ", current_tree->tree_array_address[node_index]);

	// traverse left_child and right_child (if exist) 
	int left_child_index = node_index * 2;
	if (left_child_index <= current_tree->max_tree_len && current_tree->tree_array_address[left_child_index] != '#') {
		// left child exist 
		PreOrderTraverseAndPrintNodeInTree(current_tree, left_child_index); 
	}
	int right_child_index = node_index * 2 + 1;
	if (right_child_index <= current_tree->max_tree_len && current_tree->tree_array_address[right_child_index] != '#') {
		// right child exist 
		PreOrderTraverseAndPrintNodeInTree(current_tree, right_child_index);
	}

	return; 
}

// O(N) , N : node count 
void PostOrderTraverseAndPrintNodeInTree(Tree current_tree, const int node_index) {
	// error handling 
	if (current_tree == NULL) {
		ErrorHandingFunction(DeallocatedTree);
	}
	if (node_index < 1 || node_index > current_tree->max_tree_len) {
		ErrorHandingFunction(InvalidIndex);
	}
	if (current_tree->tree_array_address[node_index] == '#') {
		ErrorHandingFunction(EmptyNode);
	}

	// traverse first left_child and right_child (if exist) 
	int left_child_index = node_index * 2;
	if (left_child_index <= current_tree->max_tree_len && current_tree->tree_array_address[left_child_index] != '#') {
		// left child exist 
		PostOrderTraverseAndPrintNodeInTree(current_tree, left_child_index);
	}
	int right_child_index = node_index * 2 + 1;
	if (right_child_index <= current_tree->max_tree_len && current_tree->tree_array_address[right_child_index] != '#') {
		// right child exist 
		PostOrderTraverseAndPrintNodeInTree(current_tree, right_child_index);
	}

	// print node_index 
	printf("%d ", current_tree->tree_array_address[node_index]);

	return;
}

// O(N) , N : node count 
void InOrderTraverseAndPrintNodeInTree(Tree current_tree, const int node_index) {
	// error handling 
	if (current_tree == NULL) {
		ErrorHandingFunction(DeallocatedTree);
	}
	if (node_index < 1 || node_index > current_tree->max_tree_len) {
		ErrorHandingFunction(InvalidIndex);
	}
	if (current_tree->tree_array_address[node_index] == '#') {
		ErrorHandingFunction(EmptyNode);
	}

	// traverse left_child (if exist) 
	int left_child_index = node_index * 2;
	if (left_child_index <= current_tree->max_tree_len && current_tree->tree_array_address[left_child_index] != '#') {
		// left child exist 
		InOrderTraverseAndPrintNodeInTree(current_tree, left_child_index);
	}

	// print node_index 
	printf("%d ", current_tree->tree_array_address[node_index]);
	
	// traverse right_child (if exist)
	int right_child_index = node_index * 2 + 1;
	if (right_child_index <= current_tree->max_tree_len && current_tree->tree_array_address[right_child_index] != '#') {
		// right child exist 
		InOrderTraverseAndPrintNodeInTree(current_tree, right_child_index);
	}

	return;
}

// O(N) , N : node count 
void LevelOrderTraverseAndPrintNodeInTree(Tree current_tree, const int node_index) {
	// error handling 
	if (current_tree == NULL) {
		ErrorHandingFunction(DeallocatedTree);
	}
	if (node_index < 1 || node_index > current_tree->max_tree_len) {
		ErrorHandingFunction(InvalidIndex);
	}
	if (current_tree->tree_array_address[node_index] == '#') {
		ErrorHandingFunction(EmptyNode);
	}

	// level order traverse ( empty node : pass ) 
	ItemType print_item = 0; 
	for (int i = 1; i <= current_tree->max_tree_len; i++) {
		print_item = current_tree->tree_array_address[i]; 
		if (print_item != '#') {
			printf("%d ", print_item);
		}
	}

	return; 
}

void EulerOrderTraverseAndPrintNodeInTree(Tree current_tree, const int node_index) {
	// error handling 
	if (current_tree == NULL) {
		ErrorHandingFunction(DeallocatedTree);
	}
	if (node_index < 1 || node_index > current_tree->max_tree_len) {
		ErrorHandingFunction(InvalidIndex);
	}
	if (current_tree->tree_array_address[node_index] == '#') {
		ErrorHandingFunction(EmptyNode);
	}

	// print node_index 
	printf("%d ", current_tree->tree_array_address[node_index]);

	// traverse left_child (if exist) 
	int left_child_index = node_index * 2;
	if (left_child_index <= current_tree->max_tree_len && current_tree->tree_array_address[left_child_index] != '#') {
		// left child exist 
		EulerOrderTraverseAndPrintNodeInTree(current_tree, left_child_index);
	}

	// print node_index 
	printf("%d ", current_tree->tree_array_address[node_index]);

	// traverse right_child (if exist)
	int right_child_index = node_index * 2 + 1;
	if (right_child_index <= current_tree->max_tree_len && current_tree->tree_array_address[right_child_index] != '#') {
		// right child exist 
		EulerOrderTraverseAndPrintNodeInTree(current_tree, right_child_index);
	}

	// print node_index 
	printf("%d ", current_tree->tree_array_address[node_index]);
}

// O(1) 
void RemoveTree(Tree* removing_tree) {
	// error handling 
	if (*removing_tree == NULL) {
		ErrorHandingFunction(DeallocatedTree);
	}

	// remove tree_array 
	free((*removing_tree)->tree_array_address);

	// remove tree ( store NULL ) 
	Tree deallocating_address = (*removing_tree);
	(*removing_tree) = NULL; 
	free(deallocating_address);
}

// O(1) 
static void ErrorHandingFunction(enum ERROR_CODE code) {
	switch (code)
	{
	case Memorylack: printf("ERROR : MEMORY IS NOT ENOUGH\n\n"); break;
	case InvalidMaxTreeLength: printf("ERROR : MAX TREE LENGTH IS INVALID\n\n"); break;
	case InvalidIndex: printf("ERROR : INDEX IS INVALID\n\n"); break;
	case EmptyNode: printf("ERROR : EMPTY NODE\n\n"); break; 
	case EmptyRootNode: printf("ERROR : EMPTY ROOT NODE\n\n"); break; 
	case RemoveRootNode: printf("ERROR : CAN'T REMOVE ROOT NODE\n\n"); break; 
	case ParentOfRootNode: printf("ERROR : ROOT NODE DOES'T HAVE PARENT\n\n"); break; 
	case RemoveInternalNode: printf("ERROR : CAN'T REMOVE INTERNAL NODE\n\n"); break; 
	case DeallocatedTree: printf("ERROR : TREE IS DEALLOCATED\n\n"); break;

	default: printf("ERROR : ERROR CODE EXCEPTION\n\n"); break;
	}

	exit(0);
}
