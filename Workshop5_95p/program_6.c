/*
 * program 6
 * program_6.c
 * Nguyen Tri Phuc - HE176442
 * 20-06-2022
 */
#include<stdlib.h>
#include<stdio.h>

int main() {
	/* Input */
	int *x = (int*)malloc(sizeof(int));
	int *y = (int*)malloc(sizeof(int));
	scanf("%d%d", x, y);
	/* End of Input */

	/* Implement */
	int a = *x;
	int b = *y;
	free(x);
	free(y);
	int sum = a+b;
	int diff = a-b;
	if(diff < 0)
		diff = -diff;
	int mul = a * b;
	double div;
	if(b) 
		div = (double) a / b;
	/* End of Implement */

	/* Output */
	printf("Sum: %d\n", sum);
	printf("Difference: %d\n", diff);
	printf("Multiply: %d\n", mul);
	if(b)
		printf("Division: %lf", div);
	else printf("Division: can not divide zero");
	/* End of Output */

    return 0;
}



