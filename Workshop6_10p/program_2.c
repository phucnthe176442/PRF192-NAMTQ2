/*
 * program 2
 * program_2.c
 * Nguyen Tri Phuc - HE176442
 * 27-06-2022
 */
#include<stdio.h>
#include<stdlib.h>

/* swap two float elements function */
void swap(float *i, float *j)
{
	float tmp = *i;
	*i = *j;
	*j = tmp;
}

int main() {
	/* Input */
	int n;
	printf("Enter the number n: ");
	do
	{
		scanf("%d", &n);	
		if(n < 0 || n > 50)
			printf("Out of range [0,50]: ");
	}while(n < 0 || n > 50);
	printf("Enter the array of n elements:\n");
	float arr[50];
	int i;
	for(i = 0; i < n; ++i)
		scanf("%f", &arr[i]);
	/* End of Input */

	/* Implement */
	/* special condition */
	if(!n)
	{
		printf("None of element.");
		return 0;
	}
	if(n == 1)
	{
		printf("Only 1 element!\nAscending: %f\nDescending: %f", arr[0], arr[0]);
		return 0;
	}
	
	/// Bubble sort algorithm
	for(i = 0; i < n; ++i)
	{
		int j, ok = 1;
		for(j = 0; j < n-i-1; ++j)
			if(arr[j] > arr[j+1])
				swap(&arr[j], &arr[j+1]), ok = 0;
		if(ok) /// check if no swap then sorted
			break;
	}
	/* End of Implement */

	/* Output */
	printf("Array sorted in ascending order: \n");
	for(i = 0; i < n; ++i)
		printf("%f   ", arr[i]);
	printf("\nArray sorted in descending order: \n");
	for(i = 0; i < n; ++i)
		printf("%f   ", arr[n-i-1]);
	/* End of Output */

    return 0;
}



