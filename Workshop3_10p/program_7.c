/*
 * program 7
 * program_7.c
 * Nguyen Tri Phuc - HE176442
 * 03-06-2022
 */
#include<stdio.h>

/* Find greatest common divisor of 2 numbers */
int gcd(int a, int b)
{
	if(!b)
		return a; 
	return gcd(b, a%b); // recall funtion based on algorithm
}

int main() {
	/* Implement */
	int a, b;
	do
	{
		printf("Enter two interger a and b: ");
		scanf("%d%d", &a, &b);
		if(a || b) 
		{
			printf("The GCD is %d.\n\n", gcd(a, b));
		}
	}while(a || b);
	/* End of Implement */

    return 0;
}



