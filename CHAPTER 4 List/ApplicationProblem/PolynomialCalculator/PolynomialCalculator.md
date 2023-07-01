# Data :   
   
Polynomial ( terms < coefficient , exponent > ) 

   

# Methods :   

**Polynomial InitPolynomial()**   
Return new Polynomial. 

**void AppendTerm(Polynomial existing_polynomial, const int coefficient, const  int exponent)**   
Add new term < coefficient , exponent > to existing_polynomial.   


**Polynomial AddPolynomial(const Polynomial p1, const Polynomial p2)**   
Return p1 + p2. 

**Polynomial SubPolynomial(const Polynomial p1, const Polynomial p2)**   
Return p1 - p2. 

**void ShowPolynomial(const Polynomial showing_polynomial)**   
Show Polynomial. 

**void RemovePolynomial(Polynomial * remove_polynomial_address)**   
Remove Polynomial.


# Exceptions :

**Memory Lack**   
InitList

**Deallocated Polynomial**   
AppendTerm , AddPolynomial , SubPolynomial , ShowPolynomial , RemovePolynomial 
