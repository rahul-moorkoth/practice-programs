#include <stdio.h>
#include <stdlib.h>

void main()
{
	printf("Enter Year\n");
	int yr;
	scanf("%d",&yr);
	if (yr % 4)
	{
		printf("Not a leap year\n");
	}
	else
	{
		printf("It is a leap year\n");
	}
}
