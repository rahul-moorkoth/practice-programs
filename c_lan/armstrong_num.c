#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
	int ab;
	printf("Enter number:\n");
	scanf("%d",&ab);
	int numb=0,cr,output=0;
	cr = ab;
	printf("--numb = %d\n",numb);
	while(cr > 0)
	{
		cr /= 10;
		numb++;
	}
	printf("numb = %d\n",numb);
	cr = ab;
	int numb1 = numb;
	while(numb > 0)
	{
		int n = cr % 10;
		printf("n = %d \n",n);
		int res=1;
		for(int i=0; i<numb1;i++)
		{
			res *= n; 
		}
		printf("res = %d \n",res);
		output += res;
		cr /= 10;
		numb--;
	}
	printf("output = %d \n",output);
}
