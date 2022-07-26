#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100
struct customer
{
	char name[31];
	char birth[12]; /// mm-dd-yyyy
	char address[101];
	char tele[12];
	double balance;
	char open_date[12]; /// mm-dd-yyyy
	char id_card[21]; /// xxxx-xxxx-xxxx-xxxx	
};
void showInfor(struct customer client)
{
	printf("\n");
	printf("Name of customer : %s\n", client.name);
	printf("Date of birth    : %s\n", client.birth);
	printf("Address          : %s\n", client.address);
	printf("Telephone        : %s\n", client.tele);
	printf("Balance          : %14.2lf VND\n", client.balance);
	printf("Card opening date: %s\n", client.open_date);
	printf("ID card number   : %s\n\n", client.id_card);
}
void findInfor(int *num_customers, struct customer arr[])
{
	printf("\nFinding customer's information\n");
	printf("Choose searching method:\n");
	printf("1.By name\n");
	printf("2.By ID card number\n");
	char choice;
	scanf("%c", &choice); getchar();
	int i;
	if(choice == '2'){
		printf("ID card number: ");
		char id_card[20];
		scanf("%[^\n]s", id_card); getchar();
		int m = strlen(id_card);
		for(i = 0; i < *num_customers; ++i)
		{
			int len = strlen(arr[i].id_card);
			if(len != m)
				continue;
			int j, flag = 1;
			for(j = 0; j < len; ++j)
				if(arr[i].id_card[j] != id_card[j]) {
					flag = 0;
					break;
				}
			if(!flag) 
				continue;
			showInfor(arr[i]);
			return;
		}
	} else if(choice == '1'){
		printf("Name: ");
		char name[31];
		scanf("%[^\n]s", name); getchar();
		int m = strlen(name);
		for(i = 0; i < *num_customers; ++i)
		{
			int len = strlen(arr[i].name);
			if(len != m)
				continue;
			int j, flag = 1;
			for(j = 0; j < len; ++j)
				if(arr[i].name[j] != name[j]) {
					flag = 0;
					break;
				}
			if(!flag) 
				continue;
			showInfor(arr[i]);
			return;
		}
	}
	printf("\nCan't not find client's information!\n");
}
void findHighest_Lowest(int *num_customers, struct customer arr[])
{
	int i;
	for(i = 0; i < *num_customers; ++i)
	{
		int j;
		int pos = i;
		for(j = i+1; j < *num_customers; ++j)
			if(arr[pos].balance > arr[j].balance)
				pos = j;
		struct customer tmp = arr[i];
		arr[i] = arr[pos];
		arr[pos] = tmp;
	}
	
	printf("\nCustomer has highest balance:\n");
	printf("     ID card number  : %s\n", arr[*num_customers-1].id_card);
	printf("     Client's name   : %s\n", arr[*num_customers-1].name);
	printf("     Balance         : %14.2lf VND\n", arr[*num_customers-1].balance);
	printf("\n");
	
	printf("\nCustomer has lowest balance:\n");
	printf("     ID card number  : %s\n", arr[0].id_card);
	printf("     Client's name   : %s\n", arr[0].name);
	printf("     Balance         : %14.2lf VND\n", arr[0].balance);
	printf("\n");
}
void sort_dec(int *num_customers, struct customer arr[])
{
	int i;
	for(i = 0; i < *num_customers; ++i)
	{
		int j;
		int pos = i;
		for(j = i+1; j < *num_customers; ++j)
			if(arr[pos].balance < arr[j].balance)
				pos = j;
		struct customer tmp = arr[i];
		arr[i] = arr[pos];
		arr[pos] = tmp;
	}
	
	printf("Client's information decreasing by balance:\n");
	for(i = 0; i < *num_customers; ++i)
	{
		printf("\n");
		printf("%4d.\n", i+1);
		printf("     ID card number  : %s\n", arr[i].id_card);
		printf("     Client's name   : %s\n", arr[i].name);
		printf("     Balance         : %14.2lf VND\n", arr[i].balance);
		printf("\n");
	}
	
	FILE *pg = fopen("decrease.txt", "w");
	if(pg == NULL)
	{
		printf("\nFile not found!\n\n");
		return;
	}
	fprintf(pg, "Client's information decreasing by balance:\n");
	for(i = 0; i < *num_customers; ++i)
	{
		fprintf(pg, "\n");
		fprintf(pg, "%4d.\n", i+1);
		fprintf(pg, "     ID card number  : %s\n", arr[i].id_card);
		fprintf(pg, "     Client's name   : %s\n", arr[i].name);
		fprintf(pg, "     Balance         : %14.2lf VND\n", arr[i].balance);
		fprintf(pg, "\n");
	}
	printf("Exported to file decrease.txt successfully\n\n");
	fclose(pg);
}
void sort_inc(int *num_customers, struct customer arr[])
{
	int i;
	for(i = 0; i < *num_customers; ++i)
	{
		int j;
		int pos = i;
		for(j = i+1; j < *num_customers; ++j)
			if(arr[pos].balance > arr[j].balance)
				pos = j;
		struct customer tmp = arr[i];
		arr[i] = arr[pos];
		arr[pos] = tmp;
	}
	
	printf("Client's information increasing by balance:\n");
	for(i = 0; i < *num_customers; ++i)
	{
		printf("\n");
		printf("%4d.\n", i+1);
		printf("     ID card number  : %s\n", arr[i].id_card);
		printf("     Client's name   : %s\n", arr[i].name);
		printf("     Balance         : %14.2lf VND\n", arr[i].balance);
		printf("\n");
	}
	
	FILE *pg = fopen("increase.txt", "w");
	if(pg == NULL)
	{
		printf("\nFile not found!\n\n");
		return;
	}
	fprintf(pg, "Client's information increasing by balance:\n");
	for(i = 0; i < *num_customers; ++i)
	{
		fprintf(pg, "\n");
		fprintf(pg, "%4d.\n", i+1);
		fprintf(pg, "     ID card number  : %s\n", arr[i].id_card);
		fprintf(pg, "     Client's name   : %s\n", arr[i].name);
		fprintf(pg, "     Balance         : %14.2lf VND\n", arr[i].balance);
		fprintf(pg, "\n");
	}
	printf("Exported to file increase.txt successfully\n\n");
	fclose(pg);
}
void exportInforBat(int *num_customers, struct customer arr[])
{
	FILE *pg = fopen("customer.bat", "w");
	if(pg == NULL)
	{
		printf("Can't not find customer.bat file\n");
		return;
	}
	fprintf(pg, "CUSTOMERS INFORMATION\n");
	int i;
	for(i = 0; i < *num_customers; ++i)
	{
		fprintf(pg, "Client's name     : %s\n", arr[i].name);
		fprintf(pg, "Date of birth    : %s\n", arr[i].birth);
		fprintf(pg, "Address          : %s\n", arr[i].address);
		fprintf(pg, "Telephone        : %s\n", arr[i].tele);
		fprintf(pg, "Balance          : %14.2lf VND\n", arr[i].balance);
		fprintf(pg, "Opening date     : %s\n", arr[i].open_date);
		fprintf(pg, "ID card number   : %s\n\n", arr[i].id_card);	
		fprintf(pg, "\n");
	}
	fclose(pg);
	printf("Exported information of client to customer.bat file successfully\n");
}
void func_5()
{
	printf("==========\n");
	int *num_customers = (int*)malloc(sizeof(int));
	printf("Enter the number of customers: ");
	scanf("%d", num_customers); getchar();
	struct customer arr[SIZE];
	int i;
	double total = 0;
	for(i = 0; i < *num_customers; ++i)
	{
		printf("\n");
		printf("Client's name: ");
		scanf("%[^\n]s", &arr[i].name); getchar();
		printf("Date of birth(mm-dd-yyyy): ");
		scanf("%[^\n]s", &arr[i].birth); getchar();
		printf("Address: ");
		scanf("%[^\n]s", &arr[i].address); getchar();
		printf("Telephone: ");
		scanf("%[^\n]s", &arr[i].tele); getchar();
		printf("Balance: ");
		scanf("%lf", &arr[i].balance); getchar();
		printf("Card opening date(mm-dd-yyyy): ");
		scanf("%[^\n]s", &arr[i].open_date); getchar();
		printf("ID card number(xxxx-xxxx-xxxx-xxxx): ");
		scanf("%[^\n]s", &arr[i].id_card); getchar();
		
		printf("\nChecking information:\n");
		showInfor(arr[i]);
		total += arr[i].balance;
	}
	printf("\nTotal balance of all clients: %14.2lf VND\n", total);
	exportInforBat(num_customers, arr);
	
	findInfor(num_customers, arr);
	findHighest_Lowest(num_customers, arr);
	sort_dec(num_customers, arr);
	sort_inc(num_customers, arr);
	printf("==========\n\n");
	free(num_customers);
}
int main()
{
	func_5();
	return 0;
}
