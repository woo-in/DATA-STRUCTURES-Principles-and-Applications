#include "Calculator.h"
#include <stdio.h>
#include <string.h>
#pragma warning(disable: 4996)
int main() {

	char stringK[500];
	
	scanf("%[^\n]", stringK);
	printf("%d", Calculator(stringK));
		
	



	return 0; 
}