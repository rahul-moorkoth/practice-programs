#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int row =3, col=2;
	int** arr = malloc(sizeof(int)*row);

	int count=0;
	for(int i=0;i<row;i++)
	{
		arr[i] = (int *) malloc(sizeof(int)*col);
	}
	//arr ={ {1,2},{3,4},{5,6}};
	printf("Filling the array with data...\n");
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			arr[i][j] = count;
			count++;
		}
	}
	for(int i=0;i<3;i++)
	{
		for(int j=0; j <2;j++)
		{
			printf("%d ",arr[i][j]);
		}
		free(arr[i]);
	}
	free(arr);
}
