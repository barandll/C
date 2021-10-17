/*
	Arrays
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
	int* buf;
	int size;
}dynamic_memory;

int create(int size, dynamic_memory* mem)
{
	mem->size = size;
	mem->buf  = malloc(size*sizeof(int));

	return size;
}

int shrink(dynamic_memory* mem, int size)
{
	mem->size = size;
	int* tmp  = malloc(size*sizeof(int));

	//copy
	for(int i=0; i<size; i++)
	{
		tmp[i] = mem->buf[i];
	}

	// free the old one
	free(mem->buf);

	// update the pointr to new memory
	mem->buf = tmp;

	return size;
}

int expand(dynamic_memory* mem, int size)
{
	int* tmp  = malloc(size*sizeof(int));

	//copy
	for(int i=0; i<mem->size; i++)
	{
		tmp[i] = mem->buf[i];
	}

	// free the old one
	free(mem->buf);

	mem->size = size;
	// update the pointr to new memory
	mem->buf = tmp;

	return size;
}

// add -> NA
// remove -> NA

// access -> ok
int access(dynamic_memory* mem, int index)
{
	return mem->buf[index];
}

//find -> ok
int find(dynamic_memory* mem, int what)
{
	for(int i=0; i<mem->size; i++)
	{
		if (mem->buf[i] == what)
			return 1;
	}

	return 0;
}

// is empty -> NA
// make empty -> NA
// get sub -> ok
int copy_sub(dynamic_memory* mem, int start, int end, dynamic_memory* dest)
{
	int j = 0;
	for(int i=start; i<end; i++, j++)
	{
		dest->buf[j] = mem->buf[i];
	}

	return j;
}

int copy_filterindex(dynamic_memory* mem, int size, dynamic_memory* dest, int what)
{
	int j = 0;
	for(int i=0; i<size; i++)
	{
		if (mem->buf[i] == what)
		{
			dest->buf[j] = i;
			j++;
		}
	}

	return j;
}

// [ 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ]

int main()
{
	dynamic_memory mem;
	create(10, &mem);

	int ret = find(&mem, -1);

	printf("%d\n", ret);



}