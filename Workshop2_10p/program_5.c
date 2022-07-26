/*
 * program 5
 * program_5.c
 * Nguyen Tri Phuc - HE176442
 * 28-5-2022
 */
#include<stdio.h>

int main() {
	/* Implement */
	int x, y;
	do
	{
		scanf("%d%d", &x, &y);
		int temp = x; /// temporary variable
		x = y;
		y = temp;
		printf("%d %d\n", x, y);
	} while(x && y);
	/* End of Implement */

    return 0;
}



