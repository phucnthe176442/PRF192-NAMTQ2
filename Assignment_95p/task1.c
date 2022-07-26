#include<stdio.h>
void func_1()
{
	system("cls");
	printf("==========\n");
	printf("Enter the name owner of bank account: ");
	char name[31];
	scanf("%[^\n]s", name); getchar();
	printf("Enter the balance of account        : ");
	double balance;
	scanf("%lf", &balance); getchar();
	
	printf("\nThe name owner of bank account      : %s\n", name);
	printf("The balance of account              : %14.2lf VND\n", balance);
	printf("==========\n\n");
}
int main()
{
	func_1();
	return 0;
}
