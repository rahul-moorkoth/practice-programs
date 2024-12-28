#include <stdio.h>
#include <stdlib.h>

void main()
{
	int c;
	printf("Enter Number to toggle alternate bit\n");
	scanf("%x",&c);
	int b = 0xAA; // 1010 1010
		      // 0110 1110 0x6E in
		      // 1100 0100 0xC4 out
	
	// XOR
	// 0 1 1
	// 1 0 1
	// 1 1 0
	// 0 0 0
	//
	// AND
	// 0 0 0
	// 0 1 0
	// 1 0 0
	// 1 1 1

	int result;
	result = c ^ b;
	printf("output = %x\n",result);
}
