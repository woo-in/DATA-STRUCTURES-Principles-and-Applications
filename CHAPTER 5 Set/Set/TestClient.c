#include <stdio.h>
#include <string.h>
#include "Set.h" 



int main() {

	Set s1 = InitSet(strcmp); 
	Set s2 = InitSet(strcmp);

	
	AddElement(s1, "a");
	AddElement(s1, "b");
	AddElement(s1, "c");
	AddElement(s1, "e");

	AddElement(s2, "d");
	
	Set s3 = GetUnionSet(s1, s2);
	PrintAllElement(s3);

	printf("%d", GetSizeSet(s3));

	RemoveSet(&s1);
	RemoveSet(&s2);
	RemoveSet(&s3);

	return 0; 
}