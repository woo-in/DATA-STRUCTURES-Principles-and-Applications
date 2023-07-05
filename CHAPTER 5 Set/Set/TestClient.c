#include <stdio.h>
#include <string.h>
#include "Set.h" 


int comp(int a, int b);
int main() {

	Set s1 = InitSet(comp); 
	Set s2 = InitSet(comp);

	
	AddElement(s1, 1);

	RemoveElement(s1, 1);

	AddElement(s1, 1);

	
	
	AddElement(s1, 2);
	AddElement(s1, 3);
	printf("\n%d\n", GetSizeSet(s1));

	RemoveSet(&s1);
	RemoveSet(&s2);
	

	return 0; 
}
int comp(int a, int b) {
	if (a > b)
		return 1;
	else if (a < b)
		return -1;
	else if (a == b)
		return 0; 
}