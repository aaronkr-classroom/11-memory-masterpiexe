#include<stdio.h>

#define ROWS 3//�� ����
#define COLS 5//�� ����
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
	char data[ROWS][COLS] = { 0 };//��� ��� 0
	char(*p)[COLS] = data;
	
	(*p)[1] = 3;
	(*(p + 1))[2] = 4;
	(*(p + 2))[4] = 5;

	printf("�ʱ� �迭 ����: \n");
	printARR(data);

	p = data;
	p++;
	(*p)[0] = 7;
	(*p)[4] = 8;
	(*(p - 1))[3] = 9;
	printf("�ι�° ���� �� �迭�� ����: \n");
	printARR(data);


	char* ptr = data;
	*(ptr + 6) = 10;//�ι�°�� �ι�°
	*(ptr + 10) = 11;//����°�� ù��°
	*(ptr + 14) = 28;//������

	printf("������ ������� �� �迭 ����: \n");
	printARR(data);

	char temp[COLS];
	for (int i = 0; i < COLS; i++)
	{
		temp[i] = data[0][i];
		data[0][i] = data[2][i];
		data[2][i] = temp[i];
	}
	printf("������ ù�� ������ �� ���� �� �迭 ����: \n");
	printARR(data);
}