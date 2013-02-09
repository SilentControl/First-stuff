#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long cifre(long x) //returns the number of digits a number has
{
	int nr = 0;
	while (x != 0)
	{
		x = x/10;
		nr++;
	}
	return nr;
}

int main()
{
	long i=0;
	FILE* g;
	char* v;
	char buffer[1025];
	int j=0;

	for (j=0;j<1024;j++)
		buffer[j] = 'x';

	while (1)
	{	
		v = (char*)malloc(cifre(i)+10);
		snprintf(v,cifre(i)+10,"%ld",i);
		g = fopen(v,"w");
		fprintf(g,"%s",buffer);
		free(v);
		fclose(g);
		i++;
	}
	return 0;
}
