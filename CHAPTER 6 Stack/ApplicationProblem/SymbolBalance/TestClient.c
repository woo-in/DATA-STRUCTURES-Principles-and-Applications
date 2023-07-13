#include <stdio.h>
#include "SymbolBalance.h"
#pragma warning(disable : 4996)

int main() {

	char arr[500];

	while (1) {
		scanf("%s", arr);

		if (IsBalanced(arr)) {
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
	}




	return 0; 
}