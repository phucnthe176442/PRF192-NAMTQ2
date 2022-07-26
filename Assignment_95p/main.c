/* Assignment
*/
/* Course:        PRF192
 */
/* Student Names: Nguyen Hoang Minh - HE168177
*                 Vu Duc Trung      - HE161769
/*                Truong Hoang Hiep - HE161790
*                 Nguyen Minh Cuong - HE161873
/*                Nguyen Tri Phuc   - HE176442 (Leader)
*/
/* Group ID:      3
*/
/* Date:          July 14, 2022
*/
/*
*/
/* I declare that the attched assignment is out own work int
accordance with FPT university Academic Policy*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 100

#define lv1 10000000
#define lv2 50000000
#define r1  0.2
#define r2  0.3
#define r3  0.4

/// request 1 - truong hoang hiep
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

/// request 2 - vu duc trung
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
	if(balance < lv1) /// range 1
		rate = r1;
	if(balance >= lv1 & balance <= lv2) /// range 2
		rate = r2;
	if(balance > lv2) /// range 3
		rate = r3;
	double interest = 0;
	int i; /// exactly year no.
	for(i = 1; i * 365 <= days; ++i)
	{
		/// interest received after 1 year
		double interest1year = balance * rate / 100; 
		interest += interest1year; /// add to total interest of all time
		balance += interest1year; /// add to total balance of all time
	}
	
	printf("\nThe interest rate: %.1lf%c per year\n", rate, '%');
	printf("The interest received after %d days: %14.2lf VND\n", days, interest);
	printf("The total balance after %d days    : %14.2lf VND\n", days, balance);
	printf("==========\n\n");
}

/// seletion sort algorithm
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

/// request 3 - vu minh cuong
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
	
	/// sort the balance array increasing order
	selection_sort(num_customers, arr);
	
	if(num_customers == 1) /// check special condition number customer = 1
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

/// single line in table format
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

/// finding highest and second highest balance in each month
void find_High_2Highest(int *num_customers, double arr[][12], double Highest[], double Highest_2[])
{
	double mask[SIZE]; /// masking array to perform sort algo
	int i;
	for(i = 0; i < 12; ++i)
	{
		int j;
		/// copy balance in month i to mask for sorting
		for(j = 0; j < *num_customers; ++j)
			mask[j] = arr[j][i];
			
		selection_sort(*num_customers, mask);
		
		/// getting information after sort
		Highest[i] = mask[*num_customers-1];
		Highest_2[i] = mask[*num_customers-2];
	}
}

/// finding lowest and second lowest balance and total balance in each month
void find_Low_2Lowest_Total(int *num_customers, double arr[][12], double Lowest[], double Lowest_2[], double Total[])
{
	/// masking array for sort algo
	double mask[SIZE];
	int i;
	for(i = 0; i < 12; ++i)
	{
		int j;
		Total[i] = 0; /// original value 
		/// copy information to masking array for sort
		for(j = 0; j < *num_customers; ++j)
			mask[j] = arr[j][i], Total[i] += mask[j]; /// add to total of month i 
		
		/// perform sort in mask array	
		selection_sort(*num_customers, mask);
		
		/// getting information
		Lowest[i] = mask[0];
		Lowest_2[i] = mask[1];
	}
}

/// finding total balance of each customers
void find_Total_customer(int *num_customers, double arr[][12])  
{
	int i;
	printf("\nTotal amount of each customer by all month:\n");
	for(i = 0; i < *num_customers; ++i) 
	{
		double total = 0; /// original value of total balance
		int j;
		for(j = 0; j < 12; ++j)
			total += arr[i][j]; /// add to total balance
		printf("Customer %d: %14.2lf VND\n", i+1, total);
	}
}

/// request 4 - nguyen hoang minh
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
	
	if(*num_customers == 1) /// check special condition number customers = 1
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
		
		/// after implement show information in table format
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
		
		int id_month; /// index of month capture highest total balance
		double highest; /// highest value of balance of id_month
		for(i = 0; i < 12; ++i)
		{
			double total = 0; /// original value of total balance
			int j;
			for(j = 0; j < *num_customers; ++j)
				total += arr[j][i];
			if(i == 0) /// original value of id_month and highest balance
				id_month = 0, highest = total;
			if(total > highest) /// update index and highest value
				highest = total, id_month = i;
		}
		printf("\n%s is the month which captured the highest amount of all customers: %14.2lf VND\n", month[id_month], highest);
	}
	printf("==========\n\n");
	free(num_customers);
}

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

/// showing information of single customer
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

/// finding information by 2 method: by name and by id card number
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
			/// compare 2 string 
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
			/// compare 2 string
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

/// finding highest and lowest balance of all customers
void findHighest_Lowest(int *num_customers, struct customer arr[])
{
	/// selection sort algorithm
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

/// sorting in decreasing order of balance 
void sort_dec(int *num_customers, struct customer arr[])
{
	/// selection sort algorithm
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
	
	/// exporting to decrease.txt file
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
	/// selection sort algorithm
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
	
	/// export information to increase.txt file
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

/// exporting inputed information to customer.bat file
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

/// request 5 - nguyen tri phuc
void func_5()
{
	system("cls");
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

/// displaying mene of request
void showMenu()
{
	printf("**********************************************************************************************************\n");
    printf("*                                 ACCOUNTS MANAGEMENT IN TIEN PHONG BANK                                 *\n");
    printf("*                                             [1]. Request 1                                             *\n");
    printf("*                                             [2]. Request 2                                             *\n");
    printf("*                                             [3]. Request 3                                             *\n");
    printf("*                                             [4]. Request 4                                             *\n");
    printf("*                                             [5]. Request 5                                             *\n");
    printf("*                                             [6]. Exit                                                  *\n");
    printf("**********************************************************************************************************\n");	
}

/// header: showing information of program and members
void groupInfor()
{
	printf("==========================================================================================================\n");
    printf("#                                          PRF192-ASSIGNMENT                                             #\n");
    printf("#                                               GROUP 3                                                  #\n");
    printf("#                                          Date: 14/07/2022                                              #\n");
    printf("#                                Member's Name:                                                          #\n");
    printf("#                                 Leader: Nguyen Tri Phuc - HE176442                                     #\n");
    printf("#                                     - Nguyen Hoang Minh - HE168177                                     #\n");
    printf("#                                     - Truong Hoang Hiep - HE161790                                     #\n");
    printf("#                                     - Nguyen Minh Cuong - HE161873                                     #\n");
    printf("#                                     - Vu Duc Trung      - HE161769                                     #\n");
    printf("==========================================================================================================\n");
}

int main()
{
	groupInfor();
	while(1)
	{
		showMenu();
		char choice;
		scanf("%c", &choice);getchar();
		
		if(choice == '6')
			break;
			
		switch(choice)
		{
			case '1':
				func_1();
				break;
			case '2':
				func_2();
				break;
			case '3':
				func_3();
				break;
			case '4':
				func_4();
				break;
			case '5':
				func_5();
				break;
			default:
				printf("Wrong format input\n");
		}
	}
	return 0;
}
