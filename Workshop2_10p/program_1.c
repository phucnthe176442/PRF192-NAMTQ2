/*
 * program 1
 * program_1.c
 * Nguyen Tri Phuc - HE176442
 * 28-5-2022
 */
#include<stdio.h>

int main() 
{
	/* Input */
	printf("Enter the interger NUM: ");
	int num;
	scanf("%d", &num);
	/* End of Input */
	
	/* Implement */	
	int even = !(num % 2); /// check if num divisibled by 2
	int remainder = !(num % 3); /// check if num divisibled by 3
	/* End of Implement */
		
	/* Output */
	if(even && remainder) 
		printf("The interger NUM is YES");
	else printf("THe interger NUM is NO");
	/* End of Output */
	
    return 0;
}


