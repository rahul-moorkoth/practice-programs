#include <stdio.h>
#include <stdlib.h>

void mymemcpy(char *dest, char *src,int size)
{
	while(size > 0)
	{
		*dest = *src;
		size--;
		dest++;
		src++;
	}
}

void main()
{
	int a,b;
	a =100;
	mymemcpy(&b,&a,4);
	printf("b= %d\n",b);
}
