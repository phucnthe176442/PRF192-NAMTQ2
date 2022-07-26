/*
 * program 5
 * program_5.c
 * Nguyen Tri Phuc - HE176442
 * 03-06-2022
 */
#include<stdio.h>

/* Calculate n-factorial */
long long factorial(int n)
{
	int i;
	long long fact = 1;
	for(i=1; i<=n; ++i)
		fact *= i;
	return fact;
}

int main() {
	/* Input */
	printf("Enter the number n: ");
	int n;
	do
	{
		scanf("%d", &n);
		/* Wrong input format */
		if(n < 0)
			printf("n must be non-negative interger: ");
	}while(n < 0);
	/* End of Input */

	/* Output */
	printf("n-factorial: %lld", factorial(n));
	/* End of Output */

    return 0;
}



