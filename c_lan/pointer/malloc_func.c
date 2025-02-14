#include <stdio.h>
#include <stdlib.h>

void func(int **ptr)
{
	*ptr = malloc(sizeof(int));
	**ptr = 4;
	printf("%s %p\n",__func__,*ptr);
}

void main(void){

	int* ptr;
	printf("%s %p\n",__func__,ptr);
	func(&ptr);
	printf("%s %p\n",__func__,ptr);
	printf("%s %d\n",__func__,*ptr);
}
