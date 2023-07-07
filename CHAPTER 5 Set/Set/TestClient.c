#include <stdio.h>
#include <string.h>
#include "Set.h" 

// 숫자에서도 다 잘되는지 체크 필요함. 
int comp(int b, int a);
int main() {

	Set s1 = InitSet(comp);
	AddElementSet(s1, 1);
	AddElementSet(s1, 2);
	AddElementSet(s1, 4);
	AddElementSet(s1, 3);
	AddElementSet(s1, 7);



	Set s2 = InitSet(comp);
	AddElementSet(s2, 4);
	AddElementSet(s2, 3);
	AddElementSet(s2, 5);
	AddElementSet(s2, 6);

	Set s3 = GetIntersectSet(s1, s2);
	PrintAllElementSet(s3);
	printf("\n");

	Set s4 = GetSubtractSet(s1, s2);
	PrintAllElementSet(s4);
	printf("\n");

	Set s5 = GetUnionSet(s1, s2);
	PrintAllElementSet(s5);
	printf("\n");



	RemoveSet(&s1);
	RemoveSet(&s2);
	RemoveSet(&s3);
	RemoveSet(&s4);
	RemoveSet(&s5);

	return 0; 
}
int comp(int b, int a) {
	if (a > b)
		return 1;
	else if (a < b)
		return -1;
	else if (a == b)
		return 0; 
}