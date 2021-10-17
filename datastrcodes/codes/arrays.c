/*
	Arrays
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// add -> NA
// delete -> NA
// access -> ok
int access(int* arr, int index)
{
	return arr[index];
}

//find -> ok
int find(int* arr, int size, int what)
{
	for(int i=0; i<size; i++)
	{
		if (arr[i] == what)
			return 1;
	}

	return 0;
}

// is empty -> NA
// make empty -> NA
// get sub -> ok
int copy_sub(int* arr, int start, int end, int* dest)
{
	int j = 0;
	for(int i=start; i<end; i++, j++)
	{
		dest[j] = arr[i];
	}
}

int copy_filterindex(int* arr, int size, int* dest, int what)
{
	int j = 0;
	for(int i=0; i<size; i++)
	{
		if (arr[i] == what)
		{
			dest[j] = i;
			j++;
		}
	}

	return j;
}

int main()
{
	int arr[10];
	memset(arr, 0, sizeof(int)*10);

	int ret = find(arr, 10, -1);

	printf("%d\n", ret);



}