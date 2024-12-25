#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
	int k,m,len=atoi(argv[1]);
	for(int i=0; i<10; i++)
	{
		m = len-i;
	        k = i;	
		for(int z=-2; z < i;z++)
		{
			printf(" ");
		}
		for(k; k < m; k++)
		{
			printf("# ");
		}
		printf("\n");

	}
}
