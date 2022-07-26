/*
 * program 1
 * program_1.c
 * Nguyen Tri Phuc - HE176442
 * date: 09.07.2022
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/// count how many words in a null terminated string of text
int countWords(char *str)
{
    int status = 0; // current state of pointer
    int wc = 0;  // word count
    
    while (*str)
    {
        if (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\f' || *str == '\v')
            status = 0; /// get out of word
        else if (status == 0)
        {
            status = 1; /// get in to new word 
            ++wc; /// found new word
        }
        ++str; /// next character
    }  
    return wc;
}

int main() {
	/* Implement */
	printf("Word Counter");
	printf("\n============\n");
	char s[101];
	printf("String to be counted: ");
	scanf("%[^\n]s", s);
	
	int result = countWords(s);
	
	printf("Number of words in the string : %d", result);
	/* End of Implement */

    return 0;
}



