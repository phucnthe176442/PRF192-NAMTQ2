/*
 * program 4
 * program_4.c
 * Nguyen Tri Phuc - HE176442
 * 03-06-2022
 */
#include<stdio.h>

/* Find difference between point (x,y) to center and radius */
int checkPosition(double x, double y, double r)
{
	double distDiff = x*x + y*y - r*r;
	if(distDiff > 0) return -1;	/// distance > radius 
	else if(!distDiff) return 0; /// distance = radius
	return 1; /// distance < radius
}

int main() {
	/* Input */
	printf("Enter the Descartes coordinates (x,y) of the point: ");
	double x, y, r;
	scanf("%lf%lf", &x, &y);
	printf("Enter the radius of the circle: ");
	do
	{
		scanf("%lf", &r);
		/* Wrong input format */
		if(r < 0)
			printf("Radius must be non-negative!: ");
	}while(r < 0);
	/* End of Input */
	
	/* Implement */
	int flag = checkPosition(x, y, r);
	/* End of Implement */

	/* Output */
	if(flag == -1) 
		printf("The point is out of the circle"); /// distance > radius 
	else if(flag == 0) 
		printf("The point is on the circle"); /// distance = radius
	else 
		printf("The point is in the circle"); /// distance < radius
	/* End of Output */

    return 0;
}



