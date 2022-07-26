/*
 * program 3
 * program_3.c
 * Nguyen Tri Phuc - HE176442
 * date: 09.07.2022
 */
#include<stdio.h>
#include<string.h>

int main() {
	/* Implement */
	printf("Word Reverse");
	printf("\n============\n");
	printf("String to be reversed: ");
	char name[101];
	scanf("%[^\n]s", name);
	
	printf("Reversed sequence of words : ");
	int n = strlen(name);
	int i;
	for(i = n-1; i >= 0; --i)
	{
		if(name[i] != ' ') /// found new word i = [end of word]
		{
			int j = i;
			int cnt = 0;
			/* find j+1 = [begin of word] */
			while(j >= 0 && name[j] != ' ')
				j--;
			int k;
			/* printf word */
			for(k = j+1; k <= i; ++k)
				printf("%c", name[k]);
			i = j+1; /// move to find next word
		} 
		else 
			printf("%c", name[i]);
	}
	/* End of Implement */

    return 0;
}



