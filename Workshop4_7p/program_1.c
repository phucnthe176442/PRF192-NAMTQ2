/*
 * program 1
 * program_1.c
 * Nguyen Tri Phuc - HE176442
 * 07-06-2022
 */
#include<stdio.h>

int factorial(int n)
{
	int res = 1, i;
	for(i=1; i<=n; ++i)
		res *= i;
	return res;
}

int isStrong(int n)
{
	int sum = 0, mask = n;
	for(; n>0; n/=10)
	{
		int digit = n%10;
		sum += factorial(digit);
	}
	return sum == mask;
}

int main() {
	/* Input */
	int n;
	do
	{
		scanf("%d", &n);
	}while(1 > n || n > 999999);
	/* End of Input */

	/* Implement */
	int i;
	for(i=1; i<=n; ++i)
		if(isStrong(i))
			printf("%d ", i);
	/* End of Implement */

    return 0;
}



