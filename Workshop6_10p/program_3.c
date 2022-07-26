/*
 * program 3
 * program_3.c
 * Nguyen Tri Phuc - HE176442
 * 27-06-2022
 */
#include<stdio.h>
#include<stdlib.h>

/// Add a value
void option_1(int arr[], int *n)
{
    if(*n == 100)
    {
        printf("Size of array is full!\n");
        return;
    }
    printf("Enter the adding value: ");
    int x;
    scanf("%d", &x);
    arr[*n] = x;
    *n = *n + 1;
}

/// Search a value
void option_2(int arr[], int n)
{
	if(!n)
	{
		printf("Current array is empty!\n");
		return;
	}
    printf("Enter the searching value: ");
    int x;
    scanf("%d", &x);
    int i;
    int ok = 0;
    printf("Positions existence: ");
    for(i = 0; i < n; ++i)
        if(arr[i] == x)
            printf("%d   ", i+1), ok = 1;
    if(!ok)
        printf("value does not exist");
    printf("\n");
}

/// Print out the array
void option_3(int arr[], int n)
{
	if(!n)
	{
		printf("Current array is empty!\n");
		return;
	}
    int i;
    printf("Current array: ");
    for(i = 0; i < n; ++i)
        printf("%d   ", arr[i]);
    printf("\n");
}

/// Print out values in a range[L,R]
void option_4(int arr[], int n)
{
	if(!n)
	{
		printf("Current array is empty!\n");
		return;
	}
    int maVal, miVal, i;
    printf("Enter the range[L, R] respectively: ");
    scanf("%d%d", &miVal, &maVal);
    printf("Valid elements: ");
    int ok = 0;
    for(i = 0; i < n; ++i)
        if(miVal <= arr[i] && arr[i] <= maVal)
            printf("%d   ", arr[i]), ok = 1;
    if(!ok)
    	printf("none of valid element");
    printf("\n");
}

/* swap two interger element function */
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/// Print out the array in descending order
void option_5(int arr[], int n)
{
	if(!n)
	{
		printf("Current array is empty!\n");
		return;
	}
    int mask[n]; /// storing array to a masking array for sort
    int i;
    for(i = 0; i < n; ++i)
        mask[i] = arr[i];
    
    /* selection sort algorithm */
    for(i = 0; i < n; ++i)
    {
        int j;
        int pos = i;
        for(j = i+1; j < n; ++j)
            if(mask[pos] > mask[j])
            	pos = j;
        if(pos != i)
       		swap(&mask[i], &mask[pos]);
	}
	
	printf("Descending order: ");
	for(i = 0; i < n; ++i)
        printf("%d   ", mask[n-i-1]);
    printf("\n");
}

/* calculate n-factorial value function */
int facto(int x)
{
    int ft = 1, i;
    for(i = 1; i <= x; ++i)
        ft *= i;
    return ft;
}

/* check strong number function */
int isStrong(int x)
{
    int n = x, sum = 0;
    while(x)
	{
		int digit = x%10;
        sum += facto(digit);
		x /= 10;
    }
    return n == sum;
}

/// Print out the strong numbers
void option_6(int arr[], int n)
{
	if(!n)
	{
		printf("Current array is empty!\n");
		return;
	}
    int i, ok = 0;
    printf("Strong numbers: ");
    for(i = 0; i < n; ++i)
        if(isStrong(arr[i]))
            printf("%d   ", arr[i]), ok = 1;
    if(!ok)
    	printf("none of strong number");
    printf("\n");
}

int main()
{
    /* Implement */
    int arr[100];
    int *n = (int*) malloc(sizeof(int)); /// current size of element
    *n = 0;
    while(1)
    {
    	printf("*********************************************");
        printf("\n[1].Add a value");
        printf("\n[2].Search a value");
        printf("\n[3].Print out the array");
        printf("\n[4].Print out values in a range[L,R]");
        printf("\n[5].Print out the array in descending order");
        printf("\n[6].Print out the strong numbers");
        printf("\n[7 & Others].Quit");
        printf("\nEnter an option: ");
        int choice;
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            option_1(arr, n);
            break;

        case 2:
            option_2(arr, *n);
            break;

        case 3:
            option_3(arr, *n);
            break;

        case 4:
            option_4(arr, *n);
            break;

        case 5:
            option_5(arr, *n);
            break;

        case 6:
            option_6(arr, *n);
            break;

        default:
            return 0;
            break;
        }
    }
    free(n);
    /* End of Implement */

    return 0;
}



