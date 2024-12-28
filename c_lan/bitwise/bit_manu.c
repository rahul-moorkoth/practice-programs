#include <stdio.h>
#include <stdlib.h>

void print_binary(int numb)
{
	for(int i=7; i>=0; i--)
	{
		int tmp= (numb >> i) & 0x01;
		printf("%d ",tmp);
	}
	printf("\n");
}

void main()
{
	int n,a,bit;
	printf("Enter number:\n");
	scanf("%d",&n);
	printf("Enter bit position:\n");
	scanf("%d",&bit);
	print_binary(n);
	a = n | (1 << bit);
	printf("a | b\n");
	print_binary(a);
	a = n & ~(1 << bit);
	printf("a & b\n");
	print_binary(a);
	a = n ^ (1 << bit);
	printf("a ^ b\n");
	print_binary(a);
}


