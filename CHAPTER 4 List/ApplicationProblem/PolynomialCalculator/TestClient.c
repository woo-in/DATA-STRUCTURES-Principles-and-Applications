#include <stdio.h>
#include "PolynomialCalculator.h"

int main() {
	
	Polynomial p1 = InitPolynomial();
	AppendTerm(p1, 1, 7);
	AppendTerm(p1, 1, 4);
	AppendTerm(p1, 1, 1);

	Polynomial p2 = InitPolynomial();
	AppendTerm(p2, 1, 3);
	AppendTerm(p2, 1, 7);
	AppendTerm(p2, 1, 4);
	AppendTerm(p2, 1, 1);



	ShowPolynomial(SubPolynomial(p1, p2));

	RemovePolynomial(&p1);
	

	AppendTerm(p1, 1, 1);
	




	return 0; 
}