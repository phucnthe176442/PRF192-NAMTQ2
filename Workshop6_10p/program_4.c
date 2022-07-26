/*
 * program 4
 * program_4.c
 * Nguyen Tri Phuc - HE176442
 * 27-06-2022
 */
#include<stdio.h>

int main() {
	/* Implement */
	printf("==============\n");
	printf("ISBN Validator\n");
	while(1)
	{
		printf("ISBN (0 to quit): ");
		char c, last;
		int ok = 1;
		int sz = 0, isbn_remainder = 0;
		do
		{
			last = c;
			scanf("%c", &c);
			if(c != '\n')
			{
				if(c < '0' || c > '9') 
				{
					ok = 0;
					continue;
				}
				if(sz == 10)
				{
					ok = 0;
					continue;
				}
				/// optimization: calculating isbn_remainder modulo 11 on time
				if(sz < 9)
					isbn_remainder = (isbn_remainder + (c-'0') * (10-sz)) % 11;
				else 
					isbn_remainder = (isbn_remainder + c-'0') % 11; 
				sz++;
			}
		}while(c != '\n');
		if(sz == 1 && last == '0')
		{
			printf("Have a nice day!");
			break;
		}
		/// isbn must has 10 digits
		if(sz != 10)
			ok = 0;
		if(!ok)
			printf("Wrong input format\n");
		else if(!isbn_remainder)
			printf("This is a valid ISBN.\n");
		else 
			printf("This is not a valid ISBN.\n");
	}
	/* End of Implement */

    return 0;
}



