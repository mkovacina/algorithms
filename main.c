// from "Handbood of Applied Algorithms", section 1.2
// generating all subsets of the set {1,..,n}

#include <stdio.h>
#include <stdlib.h>

const int ERR_NO_INPUT = -1;
const int ERR_LESS_THAN_ONE = -2;

void print(const int* x, const int r);
void extend(int* const x, int* r);
void reduce(int* const x, int* r);

int main(const int argc, const char* argv[])
{
	if (argc < 2)
	{
		puts("usage: generate-subsets length");
		return ERR_NO_INPUT;
	}

	// the length of the sequence
	int length = atoi(argv[1]);

	if (length < 1)
	{
		puts("Length parameter must be greater than 0");
		return ERR_LESS_THAN_ONE;
	}

	int r = 0;
	int* x = calloc(length,sizeof(int));
	x[r] = 0;

	do
	{
		if(x[r] < length)
		{
			extend(x, &r);
		}
		else
		{
			reduce(x, &r);
		}

		print(x, r);
	}
	while(x[1]==length);
	
	return 0;
}

void print(const int* x, const int r)
{
	for( int i = 0; i <= r; i++ )
	{
		printf("%d ", x[i]);
	}
	puts("");
}

void extend(int* const x, int* r)
{
	x[*r+1] = x[*r]+1;
	*r = *r+1;
}

void reduce(int* const x, int* r)
{
	*r = *r-1;
	x[*r] = x[*r]+1;
}
