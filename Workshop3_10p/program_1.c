/*
 * program 1
 * program_1.c
 * Nguyen Tri Phuc - HE176442
 * 03-06-2022
 */
#include<stdio.h>

int main() {
	/* Input */
	printf("Enter a number n: ");
	int n;
	scanf("%d", &n);
	/* End of Input */

	/* Implement */
	int i;
	for(i = 1; i <= n; ++i)
	{
		int j;
		for(j = 1; j <= n-i; ++j) 
			printf("~");
		for(j = 1; j <= n; ++j) 
			printf("*");
		printf("\n");
	}
	/* End of Implement */

    return 0;
}



