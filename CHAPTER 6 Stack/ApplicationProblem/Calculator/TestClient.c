#include "Calculator.h"
#include <stdio.h>
#include <string.h>
#pragma warning(disable: 4996)
int main() {

	char stringK[500];
	int after_convert[500];

	
		scanf("%[^\n]", stringK);
		int k = ConvertInfixExpression(stringK, after_convert, strlen(stringK));
		for (int i = 0; i < k; i++) {
			printf("%d\n", after_convert[i]);
		}
		
	



	return 0; 
}