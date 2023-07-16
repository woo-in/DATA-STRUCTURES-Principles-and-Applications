#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Calculator.h"
#include "Stack.h"

enum OPERATOR { Plus = INT_MIN, Minus = INT_MIN + 1, Multiplication = INT_MAX, Division = INT_MAX - 1 };
enum RANKING_CODE { Rank_1, Rank_2, Rank_3 };
enum ERROR_CODE { InvalidExpression, InvalidOperator, InvalidRange };

static int ConvertOperatorToInteger(const char convert_operator);
static bool IsTopElementEqualOrHigherPrecedence(const Stack operator_stack, const char now_operator);
// tmp not static for test 
int ConvertInfixExpression(const char* infix_expression, int * postfix_expression, const int infix_expression_element_count);

//int EvaluationPostfixExpression(int* postfix_expression, const int postfix_expression_element_count);

static void ErrorHandingFunction(enum ERROR_CODE code); 

int ConvertInfixExpression(const char* infix_expression, int* postfix_expression, const int infix_expression_element_count) {

	// prepare algorithm 
	int postfix_expression_element_count = 0;
	Stack operator_stack = InitStack();
	int pop_element = 0;
	int top_element = 0; 
	long long int tmpt_value = 0; 
	char* tmpt_address = NULL; 
	int i = 0; 


	// algorithm ------------------------------------------------------------------------------------

	// check start with unary -

	while ((i < infix_expression_element_count) && (infix_expression[i] == ' ')) {
		i++;
	}

	if (infix_expression[i] == '-') {

		// unary - 

		// insert -1 
		postfix_expression[postfix_expression_element_count] = -1;
		postfix_expression_element_count++;

		// push stack  * 
		PushStack(operator_stack, '*');

		i++; // renew index of infix expression
	}
	else if (infix_expression[i] == '+') {
		i++; // renew index of infix expression
	}
	
	// traverse all element of infix expression
	while(i < infix_expression_element_count) {
		switch (infix_expression[i]) {


			// case '(' ==> push stack ( '(' is lowest ) 
		case '(':
			PushStack(operator_stack, '(');
			// renew index of infix expression
			i++;

			// check start with unary -

			while (i < infix_expression_element_count && infix_expression[i] == ' ')
				i++; // renew index of infix expression

			if (infix_expression[i] == '-') {
				// unary - 

				// insert -1 
				postfix_expression[postfix_expression_element_count] = -1;
				postfix_expression_element_count++;

				// push stack  * 
				PushStack(operator_stack, '*');

				// renew index of infix expression
				i++;
			}
			else if (infix_expression[i] == '+') {
				// renew index of infix expression
				i++;
			}

			break;



			// case ')' ==> pop stack and insert until reach stack element '('   , ** last pop element is '(' ** 
		case ')':
			// pop first element 
			pop_element = PopStack(operator_stack);
			while (pop_element != '(') {

				// insert popped element 
				postfix_expression[postfix_expression_element_count] = ConvertOperatorToInteger(pop_element);
				postfix_expression_element_count++;

				// pop 
				pop_element = PopStack(operator_stack);
			}
			// renew index of infix expression
			i++;
			break;



			// case operator ==> pop stack and insert until reach empty stack or low precedence , ** last pop element is not low precedence operator ** 
			// precedence  ----- high [ * , / ] [ + , - ] [ ( ] low ----- 
		case '+': case '-': case '*' : case '/':
			while (IsTopElementEqualOrHigherPrecedence(operator_stack, infix_expression[i])){

				// pop 
				pop_element = PopStack(operator_stack);

				// insert popped element 
				postfix_expression[postfix_expression_element_count] = ConvertOperatorToInteger(pop_element);
				postfix_expression_element_count++;

			}
			// push stack operator
			PushStack(operator_stack, infix_expression[i]);

			// renew index of infix expression
			i++;
			break;




			// case operand ==> just insert 
		case '0' : case '1' : case '2' : case '3' : case '4' : case '5' : case '6' : case '7' : case '8' : case '9':
			// insert current element 
			tmpt_value = _strtoi64(infix_expression + i, &tmpt_address, 10);
			if (tmpt_value >= (INT_MAX - 1) || (INT_MIN + 1) >= tmpt_value) { 
				RemoveStack(&operator_stack);
				ErrorHandingFunction(InvalidRange);
			}
			postfix_expression[postfix_expression_element_count] = tmpt_value; 
			postfix_expression_element_count++;

			// renew index of infix expression
			i += (tmpt_address - (infix_expression + i));
			break;

		case ' ' :
			// renew index of infix expression
			i++; 
			break;


		default:
			ErrorHandingFunction(InvalidExpression);
			break; 
		}
	}
	// last pop and insert all of remaining stack element  
	while (!IsEmptyStack(operator_stack)) {
		// pop 
		pop_element = PopStack(operator_stack);

		// insert popped element 
		postfix_expression[postfix_expression_element_count] = ConvertOperatorToInteger(pop_element);
		postfix_expression_element_count++;
	}

	RemoveStack(&operator_stack);

	return postfix_expression_element_count;
}

/*

static void EvaluationPostfixExpression(const char* postfix_expression, const int postfix_expression_element_count) {
	
	// prepare algorithm 
	Stack operand_stack = InitStack();
	int 

	// algorithm 
	for (int i = 0; i < postfix_expression_element_count; i++) {
		// traverse all postfix expression element 
		switch (postfix_expression[i]) {

			// if operator ==> pop operand twice --> evaluate --> push 
		case '+':

			


		default:
			break;
		}
	}
}
*/ 

static int ConvertOperatorToInteger(const char convert_operator) {
	// INT_MIN : + , INT_MIN + 1 : - , INT_MAX : * , INT_MAX - 1 : / 

	switch (convert_operator) {

	case '+':
		return Plus;
		break;
	case '-':
		return Minus;
		break;
	case '*':
		return Multiplication;
		break;
	case '/':
		return Division;
		break;

	default:
		ErrorHandingFunction(InvalidOperator);
		break;
		// check stack !! 
	}
}



static bool IsTopElementEqualOrHigherPrecedence(const Stack operator_stack, const char now_operator) {
	// empty stack ==> false 
	if (IsEmptyStack(operator_stack))
		return false; 

	// ( '*' , '/' ) > ( '+' , '-' ) > ( '(' ) ==> rank 3 > 2 > 1 

	// ranking
	int top_stack_operator_rank = 0; 
	int now_operator_rank = 0; 

	char top_stack_element = GetTopElementStack(operator_stack);

	if (top_stack_element == '*' || top_stack_element == '/')
		top_stack_operator_rank = Rank_3;
	else if (top_stack_element == '+' || top_stack_element == '-')
		top_stack_operator_rank = Rank_2;
	else // '(' 
		top_stack_operator_rank = Rank_1;

	if (now_operator == '*' || now_operator == '/')
		now_operator_rank = Rank_3;
	else if (now_operator == '+' || now_operator == '-')
		now_operator_rank = Rank_2;
	else // '(' 
		now_operator_rank = Rank_1;

	// is equal or higher 
	return (top_stack_operator_rank >= now_operator_rank);
}



// O(1) 
static void ErrorHandingFunction(enum ERROR_CODE code) {
	switch (code)
	{
	case InvalidExpression: printf("ERROR : EXPRESSION IS INVALID\n\n"); break;
	case InvalidOperator: printf("ERROR : OPERATOR IS INVALID\n\n"); break; 
	case InvalidRange: printf("ERROR : OUT OF RANGE NUMBER\n\n"); break;
	default: printf("ERROR : ERROR CODE EXCEPTION\n\n"); break;
	}

	exit(0);
}