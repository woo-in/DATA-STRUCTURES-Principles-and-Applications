#include "SymbolBalance.h"
#include "Stack.h"

bool IsBalanced(const char* string_to_judge) {
	// make new stack 
	Stack symbol_stack = InitStack();

	char c = 0;

	// judge all string element 
	for (int i = 0; string_to_judge[i] != '\0'; i++) {

		switch (string_to_judge[i])
		{
		case '(': case '{': case '[':
			// ( , { , [ 

			PushStack(symbol_stack, string_to_judge[i]);
			break;



		case ')': case '}': case ']':
			// ) , } , ] 

			// false case 1 
			if (IsEmptyStack(symbol_stack)) {
				// deacllocate stack and return 
				RemoveStack(&symbol_stack);
				return false;
			}

			c = PopStack(symbol_stack);
			// false case 2 
			if ((string_to_judge[i] == '(' && c != ')') || (string_to_judge[i] == '{' && c != '}') || (string_to_judge[i] == '[' && c != ']')) {
				// deacllocate stack and return 
				RemoveStack(&symbol_stack);
				return false;
			}
			break;


		default:
			break;
			// else symbol pass for statement 
		}
	}

	// judge by Stack(is empty)
	bool last_judge = false;
	last_judge = IsEmptyStack(symbol_stack);

	// deacllocate stack and return 
	RemoveStack(&symbol_stack);
	return last_judge;
}