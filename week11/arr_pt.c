#include<stdio.h>
#define SIZE 10
int main()
{
	char data[10] = {
		1,2,3,4,5,6,7,8,9,10
	};
	int result = 0,
		i;
	char* p = data;
	for (i = 0; i < SIZE; i++)
	{
		result += *(p + i);
	}
	printf("%d", result);
	
	return 0;
}