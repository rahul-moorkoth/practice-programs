#include <stdio.h>
#include <stdlib.h>


/* Dutch National Flag Algorithm – One Pass – O(n) Time and O(1) Space
	
Traverse over the array till mid <= hi, according to the value of arr[mid] we can have three cases:

arr[mid] = 0, then swap arr[lo] and arr[mid] and increment lo by 1 because all the zeros are till index lo – 1 and move to the next element so increment mid by 1.
arr[mid] = 1, then move to the next element so increment mid by 1.
arr[mid] = 2, then swap arr[mid] and arr[hi] and decrement hi by 1 because all the twos are from index hi + 1 to n – 1. Now, we don’t move to the next element because the element which is now at index mid can be a 0 and therefore needs to be checked again.

*/

void sort(int *ptr, int size)
{
	int lo = 0,mid = 0,hi = size -1;
	int tmp;
	while(mid <= hi)
	{
		if(ptr[mid] == 0 && mid > lo)
		{
			tmp = ptr[mid];
			ptr[mid] = ptr[lo];
			ptr[lo] = tmp;
			lo++;	
		}
		else if(ptr[mid] == 1)
		{
			mid++;
		}
		else if(ptr[mid] == 2 && mid < hi)
		{
			tmp = ptr[mid];
			ptr[mid] = ptr[hi];
			ptr[hi] = tmp;
			hi--;
		}
		else
		{
			mid++;
		}
	}
}

void print_array(int *arr, int size)
{
	for(int i=0; i < size;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void main()
{
	int size = 8;
	int arr[8] = {2,0,2,1,1,0,1,1};
	print_array(arr, size);
	sort(arr,size);
	print_array(arr, size);
}
