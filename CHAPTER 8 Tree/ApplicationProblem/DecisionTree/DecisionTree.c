#include "DecisionTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#pragma warning(disable: 4996)

struct TreeType {
	ItemType* tree_array_address;
	int max_tree_len; 
};

enum ERROR_CODE { Memorylack, InvalidMaxTreeLength, ExceedMaximumLetterCount, InvalidIndex, EmptyNode, InputError, DeallocatedTree };


static Tree InitializeTree(const int max_tree_len); 
static bool IsInternalNodeInTree(Tree current_tree, const int node_index);
static void MakeInternalNode(Tree current_tree, const int node_index);
static void MakeExternalNode(Tree current_tree, const int node_index);
static void ErrorHandingFunction(enum ERROR_CODE code);


// O(N) , N : max_tree_len 
static Tree InitializeTree(const int max_tree_len) {
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

	// store start with '#' character array for sign NULL ( index 1 ~ max_tree_len ) 
	for (int i = 1; i <= max_tree_len; i++) {
		tree_array_address[i][0] = '#'; 
	}

	// connect 
	init_tree->tree_array_address = tree_array_address;
	init_tree->max_tree_len = max_tree_len;

	// return 
	return init_tree;
}


// O(1) 
static bool IsInternalNodeInTree(Tree current_tree, const int node_index) {
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


static void MakeInternalNode(Tree current_tree, const int node_index) {
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

	// Input Question and record 

	int letter_count = 0; 
	char input_character = 0; 

	printf("Enter question : ");

	while ((input_character = getchar()) != '\n') {
		if (letter_count < MAX_LENGTH - 1) {
			current_tree->tree_array_address[node_index][letter_count] = input_character; 
			letter_count++; 
		}
	}

	if (letter_count >= MAX_LENGTH - 1) {
		ErrorHandingFunction(ExceedMaximumLetterCount); 
	}

	current_tree->tree_array_address[node_index][letter_count] = '\0'; 
	
	// new Question or Answer according to reply 

	int admin_answer = 0; 
	int yes_node_index = node_index * 2; 
	int no_node_index = node_index * 2 + 1; 

	// if Question YES , make new Question or Answer ? 
	
	printf("If reply YES in Question : %s\n", current_tree->tree_array_address[node_index]);
	printf("<1> Make new question\n");
	printf("<2> Just give answer\n");
	printf("<1> or <2> : ");
	scanf("%d", &admin_answer);
	getchar();

	if (admin_answer == 1) {
		// make new question 
		MakeInternalNode(current_tree, yes_node_index);
	}
	else if(admin_answer == 2){
		// just give answer 
		MakeExternalNode(current_tree, yes_node_index);
	}
	else {
		ErrorHandingFunction(InputError); 
	}

	// if Question NO , make new Question or Answer ? 

	printf("If reply NO in Question : %s\n", current_tree->tree_array_address[node_index]);
	printf("<1> Make new question\n");
	printf("<2> Just give answer\n");
	printf("<1> or <2> : ");
	scanf("%d", &admin_answer);
	getchar();

	if (admin_answer == 1) {
		// make new question 
		MakeInternalNode(current_tree, no_node_index); 
	}
	else if(admin_answer == 2){
		// just give answer 
		MakeExternalNode(current_tree, no_node_index);
	}
	else {
		ErrorHandingFunction(InputError); 
	}

	return; 
}


static void MakeExternalNode(Tree current_tree, const int node_index) {
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


	// Input Answer and reply 

	int letter_count = 0;
	char input_character = 0;

	printf("Enter answer : ");

	while ((input_character = getchar()) != '\n') {
		if (letter_count < MAX_LENGTH - 1) {
			current_tree->tree_array_address[node_index][letter_count] = input_character;
			letter_count++;
		}
	}

	if (letter_count >= MAX_LENGTH - 1) {
		ErrorHandingFunction(ExceedMaximumLetterCount);
	}

	current_tree->tree_array_address[node_index][letter_count] = '\0';

}

Tree BuildDecisionTree() {
	// allocate new tree 
	Tree decision_tree = InitializeTree(1000); // null character , maximum :1000 

	// build new decision tree 
	MakeInternalNode(decision_tree, 1);

	return decision_tree; 
}

void RemoveDecisionTree(Tree* removing_tree) {
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

void RunDecisionTree(Tree decision_tree) {
	// error handling 
	if (decision_tree == NULL) {
		ErrorHandingFunction(DeallocatedTree); 
	}

	// run start with 1 
	int current_node_index = 1; 
	int client_answer = 0; 
	
	while (IsInternalNodeInTree(decision_tree, current_node_index)) {
		printf("Q : %s\n", decision_tree->tree_array_address[current_node_index]);
		printf("<1> YES\n");
		printf("<2> NO\n");
		printf("<1> or <2> : ");
		scanf("%d", &client_answer);
		getchar(); 

		if (client_answer == 1) {
			current_node_index *= 2;
		}
		else if (client_answer == 2) {
			current_node_index *= 2;
			current_node_index += 1;
		}
		else {
			ErrorHandingFunction(InputError);
		}
	}

	// print result 
	printf("Result : %s\n", decision_tree->tree_array_address[current_node_index]); 
	
}

// O(1) 
static void ErrorHandingFunction(enum ERROR_CODE code) {
	switch (code)
	{
	case Memorylack: printf("ERROR : MEMORY IS NOT ENOUGH\n\n"); break;
	case InvalidMaxTreeLength: printf("ERROR : MAX TREE LENGTH IS INVALID\n\n"); break;
	case ExceedMaximumLetterCount: printf("ERROR : EXCEED MAXIMUM LETTER COUNT\n\n"); break; 
	case InvalidIndex: printf("ERROR : INDEX IS INVALID\n\n"); break;
	case EmptyNode: printf("ERROR : EMPTY NODE\n\n"); break;
	case InputError: printf("ERROR : INPUT ERROR\n\n"); break; 
	case DeallocatedTree: printf("ERROR : TREE IS DEALLOCATED\n\n"); break;

	default: printf("ERROR : ERROR CODE EXCEPTION\n\n"); break;
	}

	exit(0);
}
