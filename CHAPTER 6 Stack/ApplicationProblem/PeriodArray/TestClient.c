#include "PeriodArray.h" 
#include <stdio.h>
#define SIZE (sizeof(a))/(sizeof(int))

int main() {


	int a[] = { 60,30,40,10,20,30,50,40 };
	int result[SIZE] = {0};

	GetPeriodArray(a, result, SIZE);

	for (int i = 0; i < SIZE; i++) {
		printf("%d ", result[i]);
	}




	return 0; 
}
