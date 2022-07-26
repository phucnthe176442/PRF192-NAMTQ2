#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int check(char single_line[], char searchstring[])
{
	int n = strlen(single_line);
	int m = strlen(searchstring);
	int i, j;
	for(i = 0; i+m-1 < n; ++i)
	{
		int flag = 1; 
		for(j = 0; j < m; ++j)
			if(single_line[i+j] != searchstring[j]) 
			{
				flag = 0;
				break;
			}
		if(flag)
			return 1;
	}
	return 0;
}
int mygrep(char filename[], char searchstring[])
{
	FILE *pg = fopen(filename, "r");
	char single_line[101];
	int id = 0;
	char c = getc(pg);
	int state = 1; 
	while(c != EOF)
	{
		id = 0;
		while(c != '\n' && c != EOF)
		{
			single_line[id] = c;
			c = getc(pg);
			id++;
		}
		single_line[id] = '\0'; 
		c = getc(pg); 
		int flag = check(single_line, searchstring);
		if(flag){
			if(state == 1) 
			{
				state = 0;
				printf("Lines that contain '%s'\n", searchstring);
			}
			printf("%s\n", single_line);
		}
	}
	return state;
}
int main()
{
	printf("BTP100 grep\n");
	printf("===========\n");
	printf("File name: ");
	char filename[101];
	scanf("%[^\n]s", filename); getchar();
	printf("Search string: ");
	char searchstring[101];
	scanf("%[^\n]s", searchstring); getchar();
	int flag = mygrep(filename, searchstring);
	if(flag == 1)
		printf("The string was not found in this file at all!");
	return 0;
}
