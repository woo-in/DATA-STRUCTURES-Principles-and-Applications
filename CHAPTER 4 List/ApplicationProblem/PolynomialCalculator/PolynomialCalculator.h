#ifndef _POLYNOMIAL_CALCULATOR_H 
#define _POLYNOMIAL_CALCULATOR_H 

typedef struct PolynomialType* Polynomial; // incompelete type of information hiding 

Polynomial InitPolynomial();
void AppendTerm(Polynomial existing_polynomial, const int coefficient, const  int exponent);
Polynomial AddPolynomial(const Polynomial p1, const Polynomial p2);
Polynomial SubPolynomial(const Polynomial p1, const Polynomial p2);
void ShowPolynomial(const Polynomial showing_polynomial); 
void RemovePolynomial(Polynomial* remove_polynomial_address);

#endif 
