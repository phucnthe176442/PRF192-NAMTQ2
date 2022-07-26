/*
 * Nguyen Tri Phuc - HE176442
 */
#include<stdio.h>
int main() {
	printf("Enter the price of product: ");
	double PriceProduct;
	scanf("%lf", &PriceProduct); /// Input 1
	
	printf("The value added tax(VAT) is: $%lf\n", PriceProduct * 0.1); /// Output 1
	
	printf("Enter the quantity of product collected: ");
	int NumberProduct;
	scanf("%d", &NumberProduct); /// Input 2
	
	printf("The total amount of the bill that need to be paid is: $%lf", PriceProduct * NumberProduct * 1.1); /// Output 2
	
	/*Explore memory*/
	printf("\n--------------------------------\n");
	printf("Variable PriceProduct: at addr: %u, value: %lf, size: %d\n", &PriceProduct, PriceProduct, sizeof(PriceProduct));
	printf("Variable NumberProduct: at addr: %u, value: %d, size: %d\n", &NumberProduct, NumberProduct, sizeof(NumberProduct));
	/*End of Explore memory*/
	
	return 0;
}
