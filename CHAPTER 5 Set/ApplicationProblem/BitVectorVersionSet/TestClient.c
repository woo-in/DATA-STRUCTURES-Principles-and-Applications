#include <stdio.h>
#include "Set.h"

int main(){


	Set a = InitSet(30); // 0 ~ 29 
	
	AddElementSet(a, 0);
	AddElementSet(a, 25);
	AddElementSet(a, 23);
	AddElementSet(a, 24);
	AddElementSet(a, 22);
	
	
	
	Set b = InitSet(30);
	AddElementSet(b, 22);
	AddElementSet(b, 29);
	AddElementSet(b, 23);
	AddElementSet(b, 24);
	AddElementSet(b, 0);
	

	Set c = GetUnionSet(a, b);
	PrintAllElementSet(c);

	Set d = GetIntersectSet(a, b);
	PrintAllElementSet(d);

	Set e = GetSubtractSet(a, b);
	PrintAllElementSet(e);


	RemoveSet(&a);
	RemoveSet(&b);
	RemoveSet(&c);
	RemoveSet(&d);
	RemoveSet(&e);


	return 0; 
}