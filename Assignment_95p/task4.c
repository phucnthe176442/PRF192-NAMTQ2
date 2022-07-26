#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
void showTable_line()
{
	int i;
	for(i = 0; i < 15*7+1; ++i)
	{
		if(i%15 == 0)
			printf("+");
		else printf("-");
	}
	printf("\n");
}
void find_High_2Highest(int *num_customers, double arr[][12], double Highest[], double Highest_2[])
{
	double mask[SIZE];
	int i;
	for(i = 0; i < 12; ++i)
	{
		int j;
		for(j = 0; j < *num_customers; ++j)
			mask[j] = arr[j][i];
		selection_sort(*num_customers, mask);
		Highest[i] = mask[*num_customers-1];
		Highest_2[i] = mask[*num_customers-2];
	}
}
void find_Low_2Lowest_Total(int *num_customers, double arr[][12], double Lowest[], double Lowest_2[], double Total[])
{
	double mask[SIZE];
	int i;
	for(i = 0; i < 12; ++i)
	{
		int j;
		Total[i] = 0;
		for(j = 0; j < *num_customers; ++j)
			mask[j] = arr[j][i], Total[i] += mask[j];
		selection_sort(*num_customers, mask);
		Lowest[i] = mask[0];
		Lowest_2[i] = mask[1];
	}
}
void find_Total_customer(int *num_customers, double arr[][12])  
{
	int i;
	printf("\nTotal amount of each customer by all month:\n");
	for(i = 0; i < *num_customers; ++i) 
	{
		double total = 0;
		int j;
		for(j = 0; j < 12; ++j)
			total += arr[i][j];
		printf("Customer %d: %14.2lf VND\n", i+1, total);
	}
}
void func_4()
{
	system("cls");
	printf("==========\n");
	printf("Enter the number of customers: ");
	int *num_customers = (int*)malloc(sizeof(int));
	scanf("%d", num_customers); getchar();
	double arr[SIZE][12];
	printf("Enter the balance of each month of each customer respectively:\n");
	int i;
	for(i = 0; i < *num_customers; ++i)
	{
		printf("Customer %d: ", i+1);
		int j;
		for(j = 0; j < 12; ++j)
			scanf("%lf", &arr[i][j]), getchar();
	}
	
	if(*num_customers == 1)
	{
		printf("\nThere is only one customer with information:\n");
		printf(" Month|           Balance\n");
		double total = 0;
		for(i = 0; i < 12; ++i)
			printf(" %5d|%14.2lf VND\n", i+1, arr[0][i]), total += arr[0][i];
		printf("Total: %14.2lf VND\n", total);
	} else 
	{
		char month[12][10] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
		double Highest[12], Highest_2[12];
		double Lowest[12], Lowest_2[12];
		double Total[12];
		find_High_2Highest(num_customers, arr, Highest, Highest_2);
		find_Low_2Lowest_Total(num_customers, arr, Lowest, Lowest_2, Total);
		
		printf("\n                               CUSTOMERS BALANCES INFORMATION IN EACH MONTH\n");  
		showTable_line();
		printf("|              ");
		for(i = 0; i < 6; ++i)
			printf("|%14s", month[i]);
		printf("|\n");
		showTable_line();
		printf("|Highest       ");
		for(i = 0; i < 6; ++i)
			printf("|%14.2lf", Highest[i]);
		printf("|\n");
		showTable_line();
		printf("|Second Highest");
		for(i = 0; i < 6; ++i)
			printf("|%14.2lf", Highest_2[i]);
		printf("|\n");
		showTable_line();
		printf("|Highest       ");
		for(i = 0; i < 6; ++i)
			printf("|%14.2lf", Lowest[i]);
		printf("|\n");
		showTable_line();
		printf("|Second Lowest ");
		for(i = 0; i < 6; ++i)
			printf("|%14.2lf", Lowest_2[i]);
		printf("|\n");
		showTable_line();
		printf("|Total         ");
		for(i = 0; i < 6; ++i)
			printf("|%14.2lf", Total[i]);
		printf("|\n");
		showTable_line();
		
		printf("\n\n");
		showTable_line();
		printf("|              ");
		for(i = 6; i < 12; ++i)
			printf("|%14s", month[i]);
		printf("|\n");
		showTable_line();
		printf("|Highest       ");
		for(i = 6; i < 12; ++i)
			printf("|%14.2lf", Highest[i]);
		printf("|\n");
		showTable_line();
		printf("|Second Highest");
		for(i = 6; i < 12; ++i)
			printf("|%14.2lf", Highest_2[i]);
		printf("|\n");
		showTable_line();
		printf("|Lowest        ");
		for(i = 6; i < 12; ++i)
			printf("|%14.2lf", Lowest[i]);
		printf("|\n");
		showTable_line();
		printf("|Second Lowest ");
		for(i = 6; i < 12; ++i)
			printf("|%14.2lf", Lowest_2[i]);
		printf("|\n");
		showTable_line();
		printf("|Total         ");
		for(i = 6; i < 12; ++i)
			printf("|%14.2lf", Total[i]);
		printf("|\n");
		showTable_line();
		
		find_Total_customer(num_customers, arr);
		
		int id_month;
		double highest;
		for(i = 0; i < 12; ++i)
		{
			double total = 0;
			int j;
			for(j = 0; j < *num_customers; ++j)
				total += arr[j][i];
			if(i == 0)
				id_month = 0, highest = total;
			if(total > highest)
				highest = total, id_month = i;
		}
		printf("\n%s is the month which captured the highest amount of all customers: %14.2lf VND\n", month[id_month], highest);
	}
	printf("==========\n\n");
	free(num_customers);
}
int main()
{
	func_4();
	return 0;
}
