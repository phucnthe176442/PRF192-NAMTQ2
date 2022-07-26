/*
 * program 3
 * program_3.c
 * Nguyen Tri Phuc - HE176442
 * 13-06-2022
 */
#include<stdio.h>
/*
 * 	Header function: calculateValue
 *  Purpose: calculate future value or present value depend 
 *           on variable flag
 *  Description: - principal: user principal (double)
 *               - rate: annual rate (double)
 *               - period: calculate value before or after this time (int)
 *               - flag: 0/1 - 0 future value | 1 present value (int)
 *  Return variable: - Value: value calculated (double)
*/
double calculateValue(double principal, double rate, int period, int flag)
{
	double Value = principal;
	double power = 1;
	int i;
	for(i = 1; i <= period; ++i)
		power *= (1.0+rate);

	/* Present value condition */
	if(flag) 
		power = 1.0/power;
		
	Value = Value * power;
	return Value;
}

int main() {
	/* Implement */
	double principal, rate;
	int period;
	char choice;
	printf("Investment Calculator\n");
	printf("=====================\n");
	printf("Principal  :  ");
	scanf("%lf", &principal);
	printf("Annual Rate:  ");
	scanf("%lf", &rate);
	printf("No of Years:  ");
	scanf("%d", &period);
	printf("Future value (f) or present value (p): ");
	getchar();
	scanf("%c", &choice);	
	switch(choice)
	{
		case 'f':
			printf("The present amount : $  %12.2lf\n", principal);
			printf("The future value   : $  %12.2lf\n", calculateValue(principal, rate, period, 0));
		break;
		case 'p':
			printf("The future amount : $  %12.2lf\n", principal);
			printf("The present value : $  %12.2lf\n", calculateValue(principal, rate, period, 1));
		break;
	}
	/* End of Implement */

    return 0;
}



