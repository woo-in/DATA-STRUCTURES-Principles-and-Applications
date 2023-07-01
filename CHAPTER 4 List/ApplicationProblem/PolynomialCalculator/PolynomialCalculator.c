#include "PolynomialCalculator.h"
#include <stdio.h>
#include <stdlib.h>

struct Term {
	int coefficient;
	int exponent; 
	struct Term* next; 
};

struct PolynomialType {
	struct Term* header; 
};

enum ERROR_CODE { Memorylack, DeallocatedPolynomial };

static struct Term* GetZeroTerm(); 
static void ErrorHandingFunction(enum ERROR_CODE code); 

// O(1) 
Polynomial InitPolynomial() {
	// allocate init_polynomial
	Polynomial init_polynomial = malloc(sizeof(*init_polynomial));
	if (init_polynomial == NULL) {
		ErrorHandingFunction(Memorylack);
	}

	// store header_term to init_polynomial's member
	init_polynomial->header = GetZeroTerm();

	// return 
	return init_polynomial; 
}

// O(N) , N : existing_polynomial's term count  
void AppendTerm(Polynomial existing_polynomial, const int coefficient, const  int exponent) {
	// error handling 
	if (existing_polynomial == NULL) {
		ErrorHandingFunction(DeallocatedPolynomial);
	}

	// 1 traverse and selete between making new term or adding existing term 
	struct Term* now_term = existing_polynomial->header; 
	while(now_term->next != NULL){
		if (now_term->next->exponent > exponent) {
			// traverse more 
			now_term = now_term->next; 
		}
		else if (now_term->next->exponent == exponent) {
			// add new term to existing term 
			now_term->next->coefficient += coefficient;

			// if sum is 0 , deallocate 
			if (now_term->next->coefficient == 0) {
				struct Term* temp_term = now_term->next; 
				now_term->next = now_term->next->next;
				free(temp_term);
			}
			return; 
		}
		else {
			// make 
			struct Term* new_term = GetZeroTerm();
			new_term->coefficient = coefficient;
			new_term->exponent = exponent;

			// add 
			new_term->next = now_term->next;
			now_term->next = new_term; 

			return; 
		}
	}
	// add last of polynomial 
	struct Term* new_term = GetZeroTerm();
	new_term->coefficient = coefficient; 
	new_term->exponent = exponent; 
	now_term->next = new_term; 

	return; 
}

// O( M + N ) , M , N : p1 , p2 's term count 
Polynomial AddPolynomial(const Polynomial p1, const Polynomial p2) {
	// error handling 
	if (p1 == NULL || p2 == NULL) {
		ErrorHandingFunction(DeallocatedPolynomial);
	}

	// allocate new 
	Polynomial new_polynomial = InitPolynomial();

	struct Term* now_term = NULL;  
	// add p1 to new_polynomial
	now_term = p1->header->next; 
	while (now_term != NULL) {
		AppendTerm(new_polynomial, now_term->coefficient, now_term->exponent);
		now_term = now_term->next;
	}
	
	// add p2 to new_polynomial 
	now_term = p2->header->next;
	while (now_term != NULL) {
		AppendTerm(new_polynomial, now_term->coefficient, now_term->exponent);
		now_term = now_term->next;
	}

	return new_polynomial;
}

// O( M + N ) , M , N : p1 , p2 's term count 
Polynomial SubPolynomial(const Polynomial p1, const Polynomial p2) {
	// error handling 
	if (p1 == NULL || p2 == NULL) {
		ErrorHandingFunction(DeallocatedPolynomial);
	}

	// allocate new 
	Polynomial new_polynomial = InitPolynomial();

	struct Term* now_term = NULL;
	// add p1 to new_polynomial
	now_term = p1->header->next;
	while (now_term != NULL) {
		AppendTerm(new_polynomial, now_term->coefficient, now_term->exponent);
		now_term = now_term->next;
	}

	// add -p2 to new_polynomial 
	now_term = p2->header->next;
	while (now_term != NULL) {
		AppendTerm(new_polynomial, (-1) * now_term->coefficient, now_term->exponent);
		now_term = now_term->next; 
	}

	return new_polynomial;
}

// O(N) , N : existing_polynomial's term count 
void ShowPolynomial(const Polynomial showing_polynomial) {

	// traverse and show 
	struct Term* now_term = showing_polynomial->header->next; 
	while (now_term != NULL) {
		printf("coeffient : %d , exponent : %d\n", now_term->coefficient, now_term->exponent);
		now_term = now_term->next; 
	}

	return; 
}

// O(N) , N : existing_polynomial's term count 
void RemovePolynomial(Polynomial* remove_polynomial_address) {
	// error handling 
	if (*remove_polynomial_address == NULL) {
		ErrorHandingFunction(DeallocatedPolynomial);
	}

	// traverse and free 
	struct Term* pre_term = (*remove_polynomial_address)->header;
	struct Term* now_term = pre_term->next; 
	while (pre_term != NULL) {
		free(pre_term);

		pre_term = now_term; 
		if (now_term != NULL) {
			now_term = now_term->next; 
		}
	}

	// for dangling pointer problem 
	Polynomial remove_polynomial = (*remove_polynomial_address);
	(*remove_polynomial_address) = NULL;  
	free(remove_polynomial);

	return; 

}




// O(1)
static struct Term* GetZeroTerm() {
	// make new_term 
	struct Term* new_term = malloc(sizeof(*new_term));
	if (new_term == NULL) {
		ErrorHandingFunction(Memorylack);
	}

	// init 
	new_term->coefficient = 0; 
	new_term->exponent = 0;
	new_term->next = NULL; 

	return; 
}


// O(1) 
static void ErrorHandingFunction(enum ERROR_CODE code) {
	switch (code)
	{
	case Memorylack: printf("ERROR : MEMORY IS NOT ENOUGH\n\n"); break;
	case DeallocatedPolynomial: printf("ERROR : POLYNOMIAL IS DEALLOCATED\n\n"); break;
		// error message change !! 

	default: printf("ERROR : ERROR CODE EXCEPTION\n\n"); break;
	}

	exit(0);
}