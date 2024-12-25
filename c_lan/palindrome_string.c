#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
	char name[20] = "malayalam";
	int size = strlen(name)/sizeof(char);

	char name1[20];
	int z;
	for(int i=size-1;i>=0;i--)
	{
		z = size - i -1;
		name1[z] = name[i];
		printf("%c size %d z %d\n",name1[z],size,z);
	}
	//name1[size+1] = '\0';
	if(strcmp(name, name1) == 0)
	{
		printf("It is Paladrome \n");
	}
	else
	{
		printf("It is not Paladrome %s:%s\n",name,name1);
	}
}
