#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Note:
// fgetc fputc - characters
// fgets fputs - strings
// fscanf fprintf - format specifier e.g. fprintf(fptr,"%d.%s\n", i, str);

//int fseek(FILE *stream, long offset, int whence);
//long ftell(FILE *stream);
//void rewind(FILE *stream);
//int fgetpos(FILE *stream, fpos_t *pos);
//int fsetpos(FILE *stream, const fpos_t *pos);

void main()
{
	struct Node
	{
		int a;
		char name[10];
	};

	FILE *fptr;
	fptr = fopen("test.txt","r");
	if (fptr == NULL)
	{
		exit(1);
	}
	char* c;
	c = malloc(sizeof(c)*100);
//while(c != EOF){
//fgetc(fptr)
	while(fgets(c,5,fptr) != NULL){
		//fgets(c,5,fptr);
		printf("%s",c);
	}
	free(c);
	fclose(fptr);

	struct Node node1, node2;
	node1.a = 5;
	strcpy(node1.name, "raju");
	FILE *fpt1;
	fpt1 = fopen("node.txt","w+");
	if(fpt1 != NULL)
	{
		fwrite(&node1,sizeof(node1),1,fpt1);
	}
	rewind(fpt1);
	fread(&node2,sizeof(node2),1,fpt1);
	printf("node2: %d, %s \n",node2.a,node2.name);
	fclose(fpt1);
}
