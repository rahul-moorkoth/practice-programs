#include <stdio.h>

// in: {3,1,3,4,2,3,3,1,3}
// out: 3,1

void main()
{
	int arr[9] = {3,1,3,4,2,3,3,1,3};
	int arr_1[9];
	int count=0;
	int flag=0;
	for(int i=0;i <9;i++)
	{
		for(int j=i+1; j<9; j++)
		{
			if(arr[i] == arr[j])
			{
				for(int z=0; z < count; z++)
				{
					if(arr_1[z] == arr[i])
					{
						flag = 1;
					}
				}
				if(!flag)
				{
					printf("%d \n", arr[i]);
					arr_1[count] = arr[i];
					flag=0;
					count++;
					break;
				}

			}
		}
	}
}
