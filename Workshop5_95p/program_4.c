/*
 * program 4
 * program_4.c
 * Nguyen Tri Phuc - HE176442
 * 20-06-2022
 */
#include<stdio.h>
void swap(float *a, float *b)
{
	float tmp = *a; /// temporary variable
	*a = *b;
	*b = tmp;
}
int main() {
	/* Input */
	printf("Enter number a and b respentively: ");
	float a, b;
	scanf("%f%f", &a, &b);
	/* End of Input */

	/* Implement */
	swap(&a, &b);
	/* End of Implement */

	/* Output */
	printf("After swap: %f %f", a, b);
	/* End of Output */

    return 0;
}



