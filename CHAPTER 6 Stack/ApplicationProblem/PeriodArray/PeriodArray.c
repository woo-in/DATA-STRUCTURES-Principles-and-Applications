#include "PeriodArray.h"
#include "Stack.h"
#include <stdio.h>

enum ERROR_CODE { NULLException , InvaildCount };

static void ErrorHandingFunction(enum ERROR_CODE code);

// O(N) , N : array_element_count 
void GetPeriodArray(const int* input_array, int* result_array, const int array_element_count) {
	// error handling 
	if (input_array == NULL || result_array == NULL) {
		ErrorHandingFunction(NULLException);
	}
	if (array_element_count < 0) {
		ErrorHandingFunction(InvaildCount);
	}

	// prepare algorithm 
	Stack calculator_stack = InitStack(); 
	int last_top_index = 0; 

	// algorithm
	for (int i = 0; i < array_element_count; i++) {
		// about all of input_array element

		while (!IsEmptyStack(calculator_stack) && input_array[GetTopElementStack(calculator_stack)] <= input_array[i]) {
			PopStack(calculator_stack);
		}
		// pop element while( stack is not empty and now index element value >= top index element value )

		// conclusion last top index 
		last_top_index = -1; 
		// -1 ==> empty stack 
		if (!IsEmptyStack(calculator_stack)) {
			last_top_index = GetTopElementStack(calculator_stack);
			// top index ==> not empty 
		}

		result_array[i] = i - last_top_index; 
		// result = now index - last top index 

		PushStack(calculator_stack, i);
		// push now index 
	}

	RemoveStack(&calculator_stack);

	return; 
}

// O(1) 
static void ErrorHandingFunction(enum ERROR_CODE code) {
	switch (code)
	{
	case NULLException: printf("ERROR : NULLEXCEPTION\n\n"); break;
	case InvaildCount: printf("ERROR : Invalid Array Count\n\n"); break;
	
	default: printf("ERROR : ERROR CODE EXCEPTION\n\n"); break;
	}

	exit(0);
}