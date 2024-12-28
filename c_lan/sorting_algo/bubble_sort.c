#include <stdio.h>

int bubble_sort(int *parr, int size)
{
	int pass = 0;
	for(int i=1; i<size;i++)
	{
		if(parr[i-1] > parr[i])
		{
			pass++;
			int tmp = parr[i-1];
			parr[i-1] = parr[i];
			parr[i] = tmp;
		}
	}
	printf("pass = %d\n",pass);
	return pass;
}

void print_arr(int *arr,int size)
{
	for(int i=0; i<size;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void main()
{
	int arr[6] = {2, -2, 3, 0, 2,-5};
	int size = sizeof(arr)/sizeof(arr[0]);
	print_arr(arr, size);
	while(bubble_sort(arr, size)>0)
	{
	}
	print_arr(arr, size);
}

