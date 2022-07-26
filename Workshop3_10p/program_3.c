/*
 * program 3
 * program_3
 * Nguyen Tri Phuc - HE176442
 * 03-06-2022
 */
#include<stdio.h>
#include<math.h>

/* check if x is Prime number */
int isPrime(int x)
{
	int i;
	int square_root = sqrt(x);
	for(i=2; i<=square_root; ++i)
		if(x % i == 0) 
			return 0; /// find a divisor(not Prime) help program run faster 
	return 1;
}

int main() {
	/* Input */
	int n;
	printf("Enter number n: ");
	do
	{
		scanf("%d", &n);
		/* Wrong input format */
		if(n < 2)
			printf("Please enter positive interger greater than 2: ");
	}while(n < 2);
	/* End of Input */
	
	/* Implement */
	int i;
	int cnt = 0;
	printf("Series of prime number: ");
	for(i=2; i<=n; ++i)
		if(isPrime(i))
			cnt = 1, printf("%d ", i);	
	/* End of Implement */

    return 0;
}



