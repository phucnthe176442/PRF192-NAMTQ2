#include<stdio.h>
#include<stdlib.h>

#define lv1 10000000
#define lv2 50000000
#define r1  0.2
#define r2  0.3
#define r3  0.4

void func_2()
{
	system("cls");
	printf("==========\n");
	printf("Enter the balance of account: ");
	double balance;
	scanf("%lf", &balance); getchar();
	printf("Enter the number of days    : ");
	int days;
	scanf("%d", &days); getchar();
	
	double rate;
	if(balance < lv1)
		rate = r1;
	if(balance >= lv1 & balance <= lv2)
		rate = r2;
	if(balance > lv2)
		rate = r3;
	double interest = 0;
	int i;
	for(i = 1; i * 365 <= days; ++i)
	{
		double interest1year = balance * rate / 100;
		interest += interest1year;
		balance += interest1year;
	}
	
	printf("\nThe interest rate: %.1lf%c per year\n", rate, '%');
	printf("The interest received after %d days: %14.2lf VND\n", days, interest);
	printf("The total balance after %d days    : %14.2lf VND\n", days, balance);
	printf("==========\n\n");
}
int main()
{
	func_2();
	return 0;
}
