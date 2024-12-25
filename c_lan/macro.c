#include <stdio.h>
#include <stdlib.h>

#define XOR(x,y) ((x) ^ (y))

#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define LARGEST(x,y,z) MAX(MAX(x,y),z)

void main()
{
	int a,b,c;
	printf("Enter x ^ y \n");
	scanf("%d %d",&a,&b);
	printf("%d\n",XOR(a,b));
	printf("Max x y z\n");
	scanf("%d %d %d",&a,&b,&c);
	printf("Max %d\n",LARGEST(a,b,c));

}
