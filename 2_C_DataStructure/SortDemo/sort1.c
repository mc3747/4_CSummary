#include "sort1.h"
#include<string.h>

#pragma mark - ע��

void BubbleSort(int arr[], int n)
{
	//��С�������� �������������Ƚϣ���������������
	for (int i = 0; i < n - 1; i++)			//n-1����Ϊ�����±����Ϊn-1 Ҫ����10�ֱȽ�
	{
		//n-1����Ϊ�����±����Ϊn-1 Ҫ����10�αȽϣ��ټ�i����Ϊÿ����i��Ԫ���Ѿ�������Ҫ��������
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])			//�����Ƚϣ���С�����ݷ�ǰ��
			{
				swap(arr, j + 1, j);
			}
		}
	}
}

void SelectSort(int arr[], int n)
{
	/*	int k;		//ָ����СԪ���±�
		for (int i = 0; i < n - 1; i++)
		{
			k = i;	//��ʼָ��0��ÿ�������i��һ
			for (int j = i + 1; j < n; j++)
			{
				if (arr[k]>arr[j])
				{
					k = j;	//����СԪ���±긳ֵ��k
				}
			}
			swap(arr, k, i);
		}
	*/
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				swap(arr, i, j);
			}
		}
	}
}

void InsertSort(int arr[], int n)
{
	int tempVal;
	for (int i = 1, j; i < n; i++)
	{
		tempVal = arr[i];	//����Ҫ�����ֵ
		for (j = i - 1; tempVal < arr[j] && j >= 0; --j)	//���������ƶ�����Ҫ�����ֵ��λ
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = tempVal;	//��������
	}
}

void QuickSort(int arr[], int left, int right)
{
	if (left >= right) return;//ֻ��һ��Ԫ�ز���
	int i = left, j = right;
	while (i < j)
	{
		while (i < j&&arr[j] >= arr[left])	//���������ҵ�һ��С��arr[left]����
			--j;
		while (i < j&&arr[i] < arr[left])	//���������ҵ�һ�����ڵ���arr[left]����
			++i;
		if (i < j)
			swap(arr, i, j);
	}
	QuickSort(arr, left, i - 1);//�����
	QuickSort(arr, i + 1, right);//���ұ�
}

void ShellSort(int arr[], int n)
{
	int tempVal, j;
	int jump = n >> 2;			//����ֵ
	while (jump != 0)
	{
		for (int i = jump; i < n; i++)
		{
			tempVal = arr[i];	//���������ĵ�һ������Ҳ���Ǵ��������
			for (j = i - jump; j >= 0 && tempVal < arr[j]; j -= jump)
			{
				arr[j + jump] = arr[j];
			}
			arr[j + jump] = tempVal;
		}
		jump = jump >> 1;		//����ֵ����
	}
}

void MergeSort(int arr[], int left, int right)
{
	if (left >= right)//�ݹ����ֹ������left == right֤���������ֻ��һ��Ԫ�أ�����Ҫ�ٲ���
		return;
	int mid = ((right - left) >> 1) + left;//���е�
	MergeSort(arr, left, mid);		//�����
	MergeSort(arr, mid + 1, right);	//�����
	//������
	_merge_in_arr(arr, left, mid, right);
}

void _merge_in_arr(int arr[], int left, int mid, int right)
{
	int length = right - left + 1;					//����һ�������Ŀռ�ĳ���
	int *pData = (int*)malloc(sizeof(int)*length);//����һ����̬�ڴ�������Ԫ�ص�λ��
	memset(pData, 0, sizeof(int)* length);

	//�ϲ�
	int low = left;		//����������ʼ�±�
	int hig = mid + 1;	//�ұ��������ʼ�±�
	int index = 0;		//����������±�

	while (hig <= right)//������û�кϲ���
	{
		while (low <= mid && arr[low] <= arr[hig])//֤��������û�кϲ��꣬���������ֵС���������ֵ
		{
			pData[index] = arr[low];			//����ߵ�ֵ�Ž���������
			low++;								//�������λ�ƣ���һ����Ҫ�ж���ߵ����±�
			index++;							//��һ�ηŽ�������������±�
		}
		if (low > mid)	//֤���������Ѿ�����
			break;

		while (hig <= right && arr[low] > arr[hig])//֤��������û�кϲ��꣬���������ֵ�����������ֵ
		{
			pData[index] = arr[hig];			//���ұߵ�ֵ�Ž���������
			hig++;								//�ұ�����λ�ƣ���һ����Ҫ�ж��ұߵ����±�
			index++;							//��һ�ηŽ�������������±�
		}
	}

	//����һ����֤��������һ�������Ѿ��ϲ����
	if (hig <= right)	//֤���ұ�û�����
		memmove(&pData[index], &arr[hig], sizeof(int)* (right - hig + 1));
	if (low <= mid)		//֤�����û�����
		memmove(&pData[index], &arr[low], sizeof(int)* (mid - low + 1));

	//���������䶼�ϲ����˸�������
	memmove(&arr[left], pData, sizeof(int)* length);
	free(pData);	//�ͷſռ�
}

void radix_sort(int arr[], size_t len)
{
	int**temp = (int **)malloc(sizeof(int) * 10);	//10��
	//���붯̬�ڴ�   ��������temp[10][];
	for (int i = 0; i < 10; i++)
	{
		temp[i] = (int *)malloc(sizeof(int)*len);
	}

	for (int i = 1; i <= 100; i *= 10)//ѭ����ֵ�����е�λ��
	{
		for (int x = 0; x < 10; ++x)//����������ѭ��
		{
			for (int y = 0; y < len; ++y)//����������ѭ��
			{
				temp[x][y] = -1;//��������ĳ�ʼ����ֵ��-1��ʾ��arr���治���ܳ��ֵ���ֵ 
			}
		}
		//arr�����е�Ԫ�ط��븨������
		for (int m = 0; m < len; ++m)
		{
			int index = (arr[m] / i) % 10;
			temp[index][m] = arr[m];
		}
		//�Ѹ�����������ݷŻش���������
		int k = 0;//��������±�
		for (int x = 0; x < 10; x++)
		{
			for (int y = 0; y < len; ++y)
			{
				if (temp[x][y] != -1)
					arr[k++] = temp[x][y];
			}
		}
	}
	//�ͷ��ڴ�
	for (int i = 0; i < 10; i++)
	{
		free(temp[i]);
	}
	free(temp);
}

void show(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

void swap(int arr[], int x, int y)
{
	int temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}
