/*
 * program 5
 * program_5.c
 * Nguyen Tri Phuc - HE176442
 * 20-06-2022
 */
#include<stdlib.h>
#include<stdio.h>

/* Find max between 2 real numbers */
double max(double a, double b)
{
	return ((a >= b) ? a : b);
}

int main() {
	/* Input */
	printf("Enter three number a, b, c respectively: ");
	double *arr = malloc(3*sizeof(double));
	int i;
	for(i = 0; i < 3; ++i)
		scanf("%lf", &arr[i]);
	/* End of Input */

	/* Implement */
	double Biggest = arr[0];
	Biggest = max(Biggest, arr[1]);
	Biggest = max(Biggest, arr[2]);
	/* End of Implement */

	/* Output */
	printf("Maximum of them is: %lf", Biggest);
	free(arr);
	/* End of Output */

    return 0;
}



