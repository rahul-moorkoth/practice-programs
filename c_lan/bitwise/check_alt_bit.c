#include <stdio.h>
#include <stdlib.h>

void main()
{
	int c;
	printf("Enter Number to check alternate bit pattern\n");
	scanf("%x",&c);
	int a = 0x55; // 0101 0101
	int b = 0xAA; // 1010 1010
	
	int result;
	result = c & b;
	if(result == b)
	{
		printf("0xAA pattern matched \n");
	}
	result = c | a;
	if(result == a)
	{
		printf("0x55 pattern matched \n");
	}
}
