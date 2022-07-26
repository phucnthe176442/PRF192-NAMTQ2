/*
 * program 2
 * program_2.c
 * Nguyen Tri Phuc - HE176442
 * 07-06-2022
 */
#include<stdio.h>
#include<math.h>

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

int isPrime(int n)
{
	if(n <= 1)
		return 0;
	int i;
	for(i=2; i<=sqrt(n); ++i)
		if(n % i == 0)
			return 0;
	return 1;
}
int main() {
	/* Implement */
	do
	{
		printf("[1].Process primes\n");
		printf("[2].Process strong\n");
		printf("[3].Quit\n");
		printf("Selec an operation: ");
		int choice;
		scanf("%d", &choice);
		if(choice == 3)
			return 0;
		if(choice != 1 && choice != 2)
			printf("wrong input format!");
		else 
		{
			int n;
			do
			{
				scanf("%d", &n);
			}while(n < 0);
			switch(choice)
			{
				case 1:
				if(isPrime(n)) printf("It's a prime number!");
				else printf("It's not a prime number!");
				break;
				case 2:
				if(isStrong(n)) printf("It's a strong number!");
				else printf("It's not a strong number!");
				break;
			}
		}
		printf("\n===================\n");
	}while(1);
	/* End of Implement */

    return 0;
}


