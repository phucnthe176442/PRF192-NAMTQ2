#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	printf("Statistics calculator\n");
	printf("=====================\n");
	printf("Enter the name of the data file: ");
	char filename[100];
	scanf("%[^\n]s", filename); getchar();
	printf("\n");
	FILE *pg = fopen(filename, "r");
	int n = 0;
	char c;
	double value;
	while(1)
	{
		do
		{
			c = getc(pg);
		}while(c != '\n' && c != EOF);
		c = getc(pg);
		n++;
		if(c == EOF) break;
	}
	printf("The number of data values read from this file was %d\n", n);
	fclose(pg);
	pg = fopen(filename, "r");
	double *arr = (double*)malloc(n*sizeof(double));	
	int i;
	for(i = 0; i < n; ++i)
		fscanf(pg, "%lf", &arr[i]);
	double m = 0; 
	for(i = 0; i < n; ++i)
		m += arr[i];
	m /= (double)n;
	double s = 0; 
	for(i = 0; i < n; ++i)
	 	s += arr[i] * arr[i];
	double d = (s/(double)n) - m * m; 
	printf("Their statistical mean is %.2lf\n", s);
	printf("Their standard deviation is %.2lf", d);
	free(arr);
	return 0;
}
