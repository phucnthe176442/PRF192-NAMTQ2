/*
 * program 2
 * program_2.c
 * Nguyen Tri Phuc - HE176442
 * 28-5-2022
 */
#include<stdio.h>

int main() 
{
	/* Input */
	printf("Enter the simple expression (+-*/): ");
	char op;
	double num1, num2;
	scanf("%lf%c%lf", &num1, &op, &num2);
	/* End of Input */
	
	/* Implement */
	double ans;
	switch(op)
	{
		case '+': /// plus
			ans = num1 + num2;
		break;
		
		case '-': /// minus
			ans = num1 - num2;
		break;
		
		case '*': /// multiple
			ans = num1 * num2;
		break;
		
		case '/': /// divide
			if(!num2)
			{
				printf("Can\'t divide by 0!");
				return 0;
			}
			ans = num1 / num2;
		break;
		
		default: /// wrong input format
			printf("Op character is not supported!");
			return 0;
	}
	/* End of Implement */
	
	/* Output */
	printf("Result of this expression is: %lf", ans);
	/* End of Output */
	
    return 0;
}


