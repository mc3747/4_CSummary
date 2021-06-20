#include <stdio.h>
#include <stdlib.h>

/*
	ʵ�ֳ��������㷨
	--zjp
	marc07@qq.com
*/
#define MAX_SIZE	20 
typedef struct
{
	int arr[MAX_SIZE + 1]; //���ݼ��ϣ�1���ڱ� + 10�����ݣ�
	int length;
}SearchDataStruct;

void printResult(int res)
{
	printf("result index is : %d\n", res);
}

/****************************************1��˳������**************************************************/
void Sequential_Search(void)
{
	int i;
	int keyValue = 15;//������Ԫ��
	SearchDataStruct search = { { 9999, 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 }, 10};//ģ�����ݣ���Ԫ��Ϊ�ڱ�������ʹ��
	search.arr[0] = keyValue;//�ڱ�Ԫ��
	i = search.length;
	while (search.arr[i] != keyValue)
	{
		i--;
	}
	printResult(i);//��ӡ���
}

/****************************************2����������**************************************************/
//��1���۰����
void Binary_Search(void)
{
	int low, high, mid, result = -1;
	int keyValue = 15;//������Ԫ��
	SearchDataStruct search = { { 9999, 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 }, 10 };//ģ�����ݣ���Ԫ��Ϊ�ڱ�������ʹ��
	low = 1;
	high = search.length;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (keyValue < search.arr[mid])
		{
			high = mid - 1;
		}
		else if (keyValue > search.arr[mid])
		{
			low = mid + 1;
		}
		else//�ҵ�������Ԫ��
		{	
			result = mid;
			break;
		}
	}
	printResult(result);
}

//��2����ֵ���ң����������ң�
//��ֵ���ң�������۰���ң���mid�����޸ļ��ɡ�
void Inter_Search(void)
{
	int low, high, mid, result = -1;
	int keyValue = 15;//������Ԫ��
	SearchDataStruct search = { { 9999, 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 }, 10 };//ģ�����ݣ���Ԫ��Ϊ�ڱ�������ʹ��
	low = 1;
	high = search.length;
	while (low <= high)
	{
		//��mid = low + (high - low) * (1 / 2)�е�1/2�����Ż�����Ϊ(keyValue - search.arr[low]) / (search.arr[high] - search.arr[low]);
		mid = low + (high - low) * (keyValue - search.arr[low]) / (search.arr[high] - search.arr[low]);
		if (keyValue < search.arr[mid])
		{
			high = mid - 1;
		}
		else if (keyValue > search.arr[mid])
		{
			low = mid + 1;
		}
		else//�ҵ�������Ԫ��
		{
			result = mid;
			break;
		}
	}
	printResult(result);
}

//(3)쳲���������
//a.��������쳲���������
//fib_arr[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144....};
#define FIB_MAXSIZE 15  
void ProduceFib(int *fib, int size)
{
	int i;
	fib[0] = 0;
	fib[1] = 1;
	fib[2] = 1;
	for (i = 3; i < size; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
	}
}
//b.ʵ��쳲����������㷨
void Fibonacci_Search(void)
{
	int low, high, mid, k, i, fib_arr[FIB_MAXSIZE], result = -1;
	int keyValue = 9;//������Ԫ��
	//SearchDataStruct search = { { 9999, 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 }, 10 };//ģ�����ݣ���Ԫ��Ϊ�ڱ�������ʹ��
	SearchDataStruct search = { { 9999, 5, 7, 9, 11, 13, 15, 17, 19 }, 8 };//ģ�����ݣ���Ԫ��Ϊ�ڱ�������ʹ��
	k = 0;
	low = 1;
	high = search.length;
	ProduceFib(fib_arr, FIB_MAXSIZE);//����쳲��������� fib_arr[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144....};
	while (search.length > fib_arr[k])
	{
		k++;
	}
	for (i = search.length; i < fib_arr[k]; i++)
	{
		search.arr[i] = search.arr[search.length]; //��ȫԪ��
	}

	while (low <= high)
	{
		mid = low + fib_arr[k - 1] - 1;//����쳲��������н��лƽ�ָ�  
		if (keyValue < search.arr[mid])
		{
			high = mid - 1;
			k = k - 1;
		}
		else if (keyValue > search.arr[mid])
		{
			low = mid + 1;
			k = k - 2;
		}
		else
		{
			if (mid <= search.length)//�������˵��mid��Ϊ���ҵ���λ��
			{
				result = mid;
			}
			else
			{
				result = search.length;//��mid > length˵���ǲ�ȫ��ֵ������search.length
			}
			break;
		}
	}
	printResult(result);
}

extern void test_DenseIndex(void);

void test_Search(void)
{
	//1��˳������
	//Sequential_Search();

	//2����������
	//Binary_Search();//�۰����
	//Inter_Search();//��ֵ����
	//Fibonacci_Search();//쳲���������

	//3����������-���ļ�DenseIndexSearch.c
	test_DenseIndex();
}
