/*
 * program 1
 * program_1.c
 * Nguyen Tri Phuc - HE176442
 * 27-06-2022
 */
#include<stdio.h>

int main() {
	/* Input */
	int n;
	printf("Enter the number n: ");
	do
	{
		scanf("%d", &n);	
		if(n < 0 || n > 100)
			printf("Out of range [0,100]: ");
	}while(n < 0 || n > 100);
	printf("Enter the array of n elements:\n");
	int arr[100];
	int i;
	for(i = 0; i < n; ++i)
		scanf("%d", &arr[i]);
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
		printf("Only 1 element: largest: %d; position: 1", arr[0]);
		return 0;
	}
	
	int posMax = 0; /// storing position of largest to get secondlargest 
	for(i = 1; i < n; ++i)
		if(arr[i] > arr[posMax])
			posMax = i;
	int posSecond = 0; /// position of second largest
	if(posSecond == posMax) /// check if posMax take 1st-place
		posSecond = 1;
	for(i = 0; i < n; ++i)
		if(posMax != i && arr[i] > arr[posSecond]) /// reject element largest
			posSecond = i;
	/* End of Implement */

	/* Output */
	printf("The largest element in the array: %d", arr[posMax]);
	printf("\nThe position of latgest element in the array: %d", posMax+1);
	printf("\nThe second largest element in the array: %d", arr[posSecond]);
	printf("\nThe position of second latgest element in the array: %d", posSecond+1);
	/* End of Output */

    return 0;
}



