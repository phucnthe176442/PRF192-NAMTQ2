/*
 * program 4
 * program_4.c
 * Nguyen Tri Phuc - HE176442
 * 28-5-2022
 */
#include<stdio.h>

int main() {
	/* Implement */
	int sum = 0;
	int x;
	do
	{
		scanf("%d", &x);
		if(x) sum += x;
	} while(x != 0);
	/* End of Implement */

	/* Output */
	printf("%d", sum);
	/* End of Output */

    return 0;
}



