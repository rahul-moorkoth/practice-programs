#include <stdio.h>
#include <stdlib.h>

// 0,1,1,2,3,5,8...
// Note: take three varibles and do

void main()
{
	int cr=0,next=1,pr=0;

	for(int i=0; i<10;i++)
	{
		printf("%d ",cr);
		pr = cr;
		cr = next;
		next = cr + pr;
		//printf("(%d %d) ",cr,next);
	}
}

