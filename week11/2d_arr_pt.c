#include<stdio.h>

#define ROWS 3//행 개수
#define COLS 5//열 개수
void printARR(char arr[ROWS][COLS])
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			printf("%d ", arr[i][j]);
			
		}
		printf("\n");
		
	}
	
}
int main()
{
	char data[ROWS][COLS] = { 0 };//모든 요소 0
	char(*p)[COLS] = data;
	
	(*p)[1] = 3;
	(*(p + 1))[2] = 4;
	(*(p + 2))[4] = 5;

	printf("초기 배열 상태: \n");
	printARR(data);

	p = data;
	p++;
	(*p)[0] = 7;
	(*p)[4] = 8;
	(*(p - 1))[3] = 9;
	printf("두번째 수정 후 배열의 상태: \n");
	printARR(data);


	char* ptr = data;
	*(ptr + 6) = 10;//두번째의 두번째
	*(ptr + 10) = 11;//세번째의 첫번째
	*(ptr + 14) = 28;//마지막

	printf("포인터 산술연산 후 배열 상태: \n");
	printARR(data);

	char temp[COLS];
	for (int i = 0; i < COLS; i++)
	{
		temp[i] = data[0][i];
		data[0][i] = data[2][i];
		data[2][i] = temp[i];
	}
	printf("포인터 첫열 마지막 열 변경 후 배열 상태: \n");
	printARR(data);
}