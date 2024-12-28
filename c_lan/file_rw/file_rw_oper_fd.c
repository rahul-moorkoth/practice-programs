#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#include <string.h>

void main()
{
	int fd;
	char name[10] = "TECHY";
	int size = strlen(name)/sizeof(char);
	fd = open("file_fd.txt",O_WRONLY | O_CREAT);
	if (fd == -1)
	{
		printf("Error: %d \n",errno);
	}
	write(fd,name,size);
	close(fd);
}
