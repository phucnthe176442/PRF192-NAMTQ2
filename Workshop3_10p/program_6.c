/*
 * program 6
 * program_6.c
 * Nguyen Tri Phuc - HE176442
 * 06-06-2022
 */
#include<stdio.h>
#include<math.h>

/* Check if x is perfect number */
int isPerfect(int x)
{
	int div, sum = 0;
	for(div=1; div<=sqrt(x); ++div)
	{
		if(x % div == 0)
		{
			sum += div;
			sum += x / div;
		}	
	}	
	
	/* check special condition */
	sum -= x; /// remove its self
	int y = sqrt(x); /// x is square then square root be counted 2 times
	if(y*y == x)
		sum -= y;
		
	return sum == x;
}

int main() {
	/* Input */
	printf("Enter number n: ");
	int n;
	do
	{
		scanf("%d", &n);
		/* Wrong input format*/
		if(n < 1 || n >= 1000000)
			printf("n must be positive interger and have no more than 6 digits: ");
	}while(n < 1 || n >= 1000000);
	/* End of Input */

	/* Implement */
	int i;
	int flag = 0;
	for(i=1; i<n; ++i)
		if(isPerfect(i))
			flag = 1, printf("%d ", i);
	if(!flag)
		printf("There aren't any perfect number!");
	/* End of Implement */
	
    return 0;
}



