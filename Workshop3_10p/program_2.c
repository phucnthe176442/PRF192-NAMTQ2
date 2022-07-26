/*
 * program 2
 * program_2.c
 * Nguyen Tri Phuc - HE176442
 * 03-06-2022
 */
#include<stdio.h>

int main() {
	/* Input */
	int n;
	do {
		scanf("%d", &n);
	} while(n < 1 || n >= 1000000);
	/* End of Input */

	/* Implement */
	int sum = 0;
	while(n)
	{
		sum = (sum + n%10) % 10; /// calculate remainder sum of digits by 10
		n /= 10; /// remove unit digit
	}
	/* End of Implement */

	/* Output */
	if(!sum) printf("YES"); /// sum digits divisible by 10 
	else printf("NO");
	/* End of Output */

    return 0;
}



