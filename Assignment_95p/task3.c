#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
void selection_sort(int n, double arr[])
{
	int i;
	for(i = 0; i < n; ++i)
	{
		int j, pos = i;
		for(j = i + 1; j < n; ++j)
			if(arr[j] < arr[pos])
				pos = j;
		double tmp = arr[i];
		arr[i] = arr[pos];
		arr[pos] = tmp;
	}
}
void func_3()
{
	system("cls");
	printf("==========\n");
	printf("Enter the number of customers: ");
	int num_customers;
	scanf("%d", &num_customers); getchar();
	double arr[SIZE];
	int i;
	printf("Enter the balance of each customer:\n");
	for(i = 0; i < num_customers; ++i)
	{
		printf("Customers %d: ", i+1);
		scanf("%lf", &arr[i]); getchar();
	}
	
	selection_sort(num_customers, arr);
	
	if(num_customers == 1)
	{
		printf("\nThere is only one customers with balance: %14.2lf VND\n", arr[0]);
	} else 
	{
		printf("\nThe highest balance among all account balances       : %14.2lf VND\n", arr[num_customers-1]);
		printf("The second highest balance among all account balances: %14.2lf VND\n", arr[num_customers-2]);
		
		printf("\nThe lowest balance among all account balances        : %14.2lf VND\n", arr[0]);
		printf("The second lowest balance among all account balances : %14.2lf VND\n", arr[1]);
		
		printf("\nList of balances in increasing order:\n");
		for(i = 0; i < num_customers; ++i)
			printf("%.2lf ", arr[i]);
	    
	    printf("\n\nList of balances in decreasing order:\n");
	    for(i = 0; i < num_customers; ++i)
	    	printf("%.2lf ", arr[num_customers-i-1]);
	    printf("\n");
	}
	printf("==========\n\n");
}
int main()
{
	func_3();
	return 0;
}
