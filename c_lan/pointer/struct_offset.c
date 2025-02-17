#include <stdio.h>
#include <stdlib.h>

#define OFFSET(struct_type, member) ((size_t) &(((struct_type *)0)->member))

struct name
{
	int a; // offset=0
	int b; // offset=4
	int c; // offset=8
};

void main()
{
	struct name* ptr = malloc(sizeof(struct name));
	printf("%p %p\n",ptr,&ptr->c);
	char* cptr = (char *) &ptr->c;
	printf("offset=%p\n",cptr-(char*)ptr);
	printf("offset=%p\n",&(((struct name*) NULL)->c));
	// using macro
	printf("offset=%zu\n", OFFSET(struct name, c));

}
