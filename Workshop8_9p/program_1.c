#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int wordwrap(char wrapstring[], int fieldwidth)
{
	int state = 0;
	int n = strlen(wrapstring);
	char resultstr[n];
	int len = 0;
	int i;
	int cnt = 0; 
	for(i = 0; i < n; ++i)
	{
		if(wrapstring[i] == ' ')
		{
		    state = 0, cnt = 0;
		}
		else
		{
			if(state == 0) 
			{
				state = 1; 
				resultstr[len] = ' ';
				len++;
			}
			resultstr[len] = wrapstring[i];
			len++;			
			cnt++;
		}
	}
	for(i = 1; i < len; ++i)
		resultstr[i-1] = resultstr[i];
	len--;
	resultstr[len] = '\0';
	FILE *pg = fopen("result.txt", "w");
	char single_line[fieldwidth+1];
	single_line[fieldwidth] = '\0';
	int id = 0; 
	do
	{
		for(i = 0; i < fieldwidth; ++i)
			single_line[i] = ' ';
		for(i = id; i < n && i < id+fieldwidth; ++i)
			single_line[i-id] = resultstr[i];
		if(single_line[fieldwidth-1] != ' ' && id+fieldwidth < len)
		{
			if(resultstr[id+fieldwidth] != ' ') 
			{
				for(i = id+fieldwidth-1; i >= 0 && single_line[i-id] != ' '; --i)
					single_line[i-id] = ' ';
				id = i;
			} else id += fieldwidth;
		} else 
			id += fieldwidth;
		if(id < len && resultstr[id] == ' ')
			id++;
		fprintf(pg, "%s\n", single_line);
	}while(id < len);
	fclose(pg);
}
int main()
{
	char line[101];
	printf("String need to be wrapped: ");
	scanf("%[^\n]s", line); getchar();
	printf("Field width: ");
	int fieldwidth;
	scanf("%d", &fieldwidth); getchar();
	wordwrap(line, fieldwidth);
	return 0;
}
