#include <stdio.h>
#include <unistd.h>

int counter = 4;
extern void increment(void);

void main()
{
	for(int i=0; i < 5;i++)
	{
		increment();
		printf("counter=%d \n",counter);
		sleep(1);
	}
}
