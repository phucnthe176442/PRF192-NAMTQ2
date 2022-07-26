/* Course:        PRF192
*/
/* Student Names: Nguyen Tri Phuc
*/
/* Group ID:
*/
/* Date:          July 14, 2022
*/
/*
*/
/* I declared that the attached assignment is our own work in
accordance with FPT University Academic Policy */

#include<stdio.h>
void swap(double* a, double* b)
{
    double t = *a;
    *a = *b;
    *b = t;
}
double max(double a, double b)
{
    if(a < b)
        return b;
    return a;
}
double min(double a, double b)
{
    if(a > b)
        return b;
    return a;
}
int partition (double a[], int lb, int rb)
{
    double pivot = a[rb];
    int i = (lb - 1), j;
    for (j = lb; j <= rb-1; ++j)
    {

        if (a[j] < pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i+1], &a[rb]);
    return i+1;
}
void quick_sort(double a[], int lb, int rb)
{
    if(lb < rb)
    {
        int id = partition(a, lb, rb);
        quick_sort(a, lb, id-1);
        quick_sort(a, id+1, rb);
    }
}

char Name_owner[50];
void Request_1()
{
    printf("Please enter the name owner of bank account: ");
    scanf(" %[^\n]s", Name_owner);
    printf("Please enter the balance of account: ");
    long long Balance;
    scanf("%lld", &Balance);
    printf("The name owner of bank account is: ");
    int n = strlen(Name_owner);
    int i;
    for(i=0; i<n; ++i)
        printf("%c", Name_owner[i]);
    printf("\nThe balance of account is: %lld VND", Balance);
}

void Request_2()
{
    printf("Please enter the balance: ");
    double balance;
    scanf("%lf", &balance);
    printf("Please enter number of days: ");
    int days;
    scanf("%d", &days);
    double rate;
    if(balance < 10000000)
        rate = 0.002;
    else if(10000000 <= balance && balance <= 50000000)
        rate = 0.003;
    else
        rate = 0.004;
    printf("The summation of balance after %d days is: %lf VND", days, balance * (1 + rate * days / 365));
}

double balance[100];
void Request_3()
{
    int numbers_customers;
    printf("Please enter the number of customers: ");
    scanf("%d", &numbers_customers);
    printf("Please enter the balance of each customer: ");
    if(numbers_customers == 1)
    {
        double x;
        scanf("%lf", &x);
        printf("There is only one customer!");
        return;
    }
    int i;
    for(i=0; i<numbers_customers; ++i)
        scanf("%lf", &balance[i]);
    quick_sort(balance, 0, numbers_customers-1);
    printf("The highest balance among all account balances is: %lf VND\n", balance[numbers_customers-1]);
    printf("The second highest balance among all account balances is: %lf VND\n", balance[numbers_customers-2]);
    printf("The lowest balance among all account balances is: %lf VND\n", balance[0]);
    printf("The second lowest balance among all account balances is: %lf VND\n", balance[1]);
    printf("The increasing order of the array of balance is: ");
    for(i=0; i<numbers_customers; ++i)
        printf("%lf ", balance[i]);
    printf("(VND)");
    printf("\n");
    printf("The decreasing order of the array of balance is: ");
    for(i=numbers_customers-1; i>=0; --i)
        printf("%lf ", balance[i]);
    printf("(VND)");
}

double arr[1005][12], balance_each[12005];
void Request_4()
{
    /* Test
    2
    1 2 3 4 5 6 7 8 9 10 11 12
    12 11 10 9 8 7 6 5 4 3 2 1
    End Test */

    /* Input */
    printf("Please enter the number of customers: ");
    int number_customers;
    scanf("%d", &number_customers);
    printf("Please enter the amount for each month(from 1\'s to 12\'s) of each customer:\n");
    int i, j;
    for(i = 0; i < number_customers; ++i)
        for(j = 0; j < 12; ++j)
            scanf("%lf", &arr[i][j]);
    printf("\n");
    /* End of Input */

    /* Subtask12 */
    for(j = 0; j < 12; ++j) 
	{
    	int cnt = 0;
    	for(i = 0; i < number_customers; ++i)
            balance_each[cnt++] = arr[i][j];
    	quick_sort(balance_each, 0, cnt-1);
    	printf("The highest and second highest balance for month among all account balance of %d\'s month is: ", j+1);
    	printf("%lf %lf VND\n", balance_each[cnt-1], balance_each[cnt-2]);
    	printf("The lowest and second lowest balance for month among all account balance of %d\'s month is: ", j+1);
    	printf("%lf %lf VND\n\n", balance_each[0], balance_each[1]);
    }
    /* End of Subtask12 */

    /* Subtask3 */
    for(i = 0; i < number_customers; ++i)
    {
        double total = 0;
        for(j = 0; j < 12; ++j)
            total += arr[i][j];
        printf("The total amount of customer %d by all months is: %lf VND\n", i+1, total);
    }
    printf("\n");
    /* End of Subtask3 */

    /* Subtask45 */
    int id_month;
    double Max = -1;
    for(i = 0; i < 12; ++i)
    {
        double total = 0;
        for(j = 0; j < number_customers; ++j)
            total += arr[j][i];

        if(Max == -1 || Max < total)
            id_month = i, Max = total;

        printf("The total amount of %d\'s month deposited in TienPhong of all customers is: %lf VND\n", i+1, total);
    }
    printf("\nThe name of month which capture the highest amounts of all customers is %d\'s month (%lf VND)\n", id_month+1, Max);
    /* End of Subtask45 */
}

void Request_5()
{

}

int Display_menu()
{
    printf("Please choose the number:\n");
    printf("0.End program\n");
    printf("1.Request 1\n");
    printf("2.Request 2\n");
    printf("3.Request 3\n");
    printf("4.Request 4\n");
    printf("5.Request 5\n");
    int x;
    scanf("%d", &x);
    return x;
}

int main()
{
    while(1)
    {
        int x = Display_menu();
        if(x == 0)
            break;
        if(x == 1)
            Request_1();
        else if(x == 2)
            Request_2();
        else if(x == 3)
            Request_3();
        else if(x == 4)
            Request_4();
        else if(x == 5)
            Request_5();
        else
            printf("ERROR!");
        printf("\n\n");
        printf("------------------------------");
        printf("\n");
    }
    return 0;
}

