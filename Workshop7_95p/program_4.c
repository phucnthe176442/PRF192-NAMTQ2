/*
 * program 4
 * program_4.c
 * Nguyen Tri Phuc - HE176442
 * date: 11.07.2022
 */
#include<stdio.h>
#include<string.h>
void cleanText(char *str)
{
	/// clean first whitespace character 
	while(*str && *str == ' ')
	{
		str++;
	}	
	while(*str)
	{
		if(*str < ' ' || *str > '~') /// non-printable character replace by _
			printf("_");
		else 
		{
			/// found whitespace character -> doing clean text
			if (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\f' || *str == '\v')
			{
				while(*str && (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\f' || *str == '\v'))
					str++;
				printf(" "); /// after clean print space character
			} 
			if(*str != NULL){
				if(*str < ' ' || *str > '~') /// non-printable character replace by _
					printf("_");
			 	else 
				 	printf("%c", *str); /// print current character
			}
		}
		if(*str == NULL) /// before have while loop -> *str may be NULL
			return;
		str++;
	}
}

int main() {
	/* Implement */
	printf("String Cleaner");
	printf("\n==============\n");
	printf("String to be cleaned : ");
	char strin[101];
	scanf("%[^\n]s", strin);
	getchar();
	printf("Cleaned string       : ");
	cleanText(strin);
	/* End of Implement */

    return 0;
}



