#include <stdio.h>
#include <stdlib.h>

/*
	ʵ�ֳ�������
	--zjp
	marc07@qq.com
*/

#define MAXSIZE	10
typedef struct
{
	int r[MAXSIZE + 1];	//���ڴ洢Ҫ��������飬r[0]�����ڱ�����ʱ����
	int length;			//���ڼ�¼˳���ĳ���
}SqList;

typedef enum
{
	FALSE = 0,
	TRUE
}Status;

//��������ǰ������Ԫ��
void Swap(SqList *L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

//��ӡ������
void Print_Result(SqList *L)
{
	printf("sort result: \n");
	for (int i = 1; i <= L->length; i++)
	{
		printf("%d ", L->r[i]);
	}
	printf("\n");
}

/****************************************1��ð������**************************************************/
//ð�������㷨1--����ð������
void BubbleSort_1(void)
{
	int i, j;
	SqList L = { { 9999, 9, 1, 5, 8, 3, 7, 2, 4, 6, 10 }, MAXSIZE };//��Ԫ�ر���ʹ�ã���������������

	for (i = 1; i <= L.length; i++)
	{
		for (j = i + 1; j <= L.length; j++)
		{
			if (L.r[i] > L.r[j])	//����
			{
				Swap(&L, i, j);
			}
		}
	}

	Print_Result(&L);//��ӡ������
}

//ð�������㷨2--����ð������
void BubbleSort_2(void)
{
	int i, j;
	SqList L = { { 9999, 9, 1, 5, 8, 3, 7, 2, 4, 6, 10 }, MAXSIZE };//��Ԫ�ر���ʹ�ã���������������

	for (i = 1; i < L.length; i++)
	{
		for (j = L.length - 1; j >= i; j--)
		{
			if (L.r[j] > L.r[j + 1])//ð������
			{
				Swap(&L, j, j+1);
			}
		}
	}

	Print_Result(&L);//��ӡ������
}

//ð�������㷨2--ð���Ż�
//�ɱ����ڴ󲿷�Ԫ�������������½����������ѭ���ж�
void BubbleSort_2_Improve(void)
{
	int i, j;
	Status flag = TRUE;//��ӱ�Ǵ���
	SqList L = { { 9999, 2, 1, 3, 4, 5, 6, 7, 8, 9, 10 }, MAXSIZE };//��Ԫ�ر���ʹ�ã���������������
	//ע�⣬����Ԫ���Ѵ󲿷�����
	for (i = 1; i < L.length && flag; i++)//����flag
	{
		flag = FALSE;//Ĭ��FALSE
		for (j = L.length - 1; j >= i; j--)
		{
			if (L.r[j] > L.r[j+1])
			{
				Swap(&L, j, j+1);
				flag = TRUE; //�޸ı�ǣ�����ָʾ��Ҫ������һ��ѭ���жϣ�����������ɡ�
			}
		}
	}

	Print_Result(&L);//��ӡ������
}

/****************************************2��ѡ������**************************************************/
void SelectSort(void)
{
	int i, j, min;
	SqList L = { { 9999, 9, 1, 5, 8, 3, 7, 2, 4, 6, 10 }, MAXSIZE };//��Ԫ�ر���ʹ�ã���������������

	for (i = 1; i < L.length; i++)
	{
		min = i;
		for (j = i + 1; j <= L.length; j++)
		{
			if (L.r[min] > L.r[j])
			{
				min = j;
			}
		}
		if (min != i)
		{
			Swap(&L, i, min);
		}
	}

	Print_Result(&L);//��ӡ������
}

/****************************************3��ֱ�Ӳ�������**************************************************/
void InsertSort(void)
{
	int i, j;
	SqList L = { { 0, 5, 1, 4, 6, 2 }, 5 };//��Ԫ�����ڱ�����������������

	for (i = 2; i <= L.length; i++)
	{
		if (L.r[i] < L.r[i - 1])
		{
			L.r[0] = L.r[i];//�ڱ�Ԫ�أ����˴���¼Ϊ������Ԫ��
			for (j = i - 1; L.r[j] > L.r[0]; j--)
			{
				L.r[j + 1] = L.r[j];//Ԫ�������ƶ����ڳ�λ��
			}
			L.r[j + 1] = L.r[0];//�ҵ��˺���λ�ã������ڱ�Ԫ��
		}
	}

	Print_Result(&L);//��ӡ������
}

/****************************************4��ϣ������**************************************************/
void ShellSort(void)
{
	int i, j;
	SqList L = { { 0, 9, 1, 5, 8, 3, 7, 2, 4, 6, 10 }, MAXSIZE };//��Ԫ�����ڱ�����������������
	int increment = L.length;
	do
	{
		increment = increment / 3 + 1; //�˴��Զ�����������
		for (i = increment + 1; i < L.length; i++)
		{
			if (L.r[i] < L.r[i - increment])
			{
				L.r[0] = L.r[i];
				for (j = i - increment; j > 0 && L.r[j] > L.r[0]; j -= increment)
				{
					L.r[j + increment] = L.r[j];
				}
				L.r[j + increment] = L.r[0];
			}//�˴�ʵ��Ϊֱ�Ӳ�������ֻ����������Ϊincrement��������1
		}
		printf("������Ϊ %d �����н���ϣ������\n", increment);
		Print_Result(&L);//��ӡϣ�������м���̽��
	} while (increment > 1);//�����������У����ж��ֱ�Ӳ�������
	printf("����ϣ����������\n");
	Print_Result(&L);//��ӡ����������
}

/****************************************5��������**************************************************/
/* ��������̣��Դ󶥶�Ϊ����
��1������һ����ȫ�������󶥶ѣ�ȡ���Ѷ����֣�Ҳ�������ֵ����
��2����ʣ�µ��������¹���һ���󶥶ѣ���ȡ���Ѷ����֣�Ҳ����ʣ��ֵ���е����ֵ����
��3���ظ����Ϲ��̣�ֱ��ȡ��������֣����յõ�һ���Ӵ�С���е�����
*/
//������ȫ�������󶥶�
void HeapAddjust(SqList *L, int s, int m)
{
	int temp, j;
	temp = L->r[s];
	for (j = 2 * s; j <= m; j *= 2)//���ӽڵ��±���2��Ծ����
	{
		if (j < m && L->r[j] < L->r[j + 1])
		{
			++j;	//�عؼ��ֽϴ�ĺ��ӽ��
		}
		if (temp >= L->r[j])
		{
			break;
		}
		L->r[s] = L->r[j];//����
		s = j; //��¼����λ��
	}
	L->r[s] = temp;	//����
}
//�������㷨
void HeapSort()
{
	int i;
	SqList L = { { 0, 9, 1, 5, 8, 3, 7, 2, 4, 6, 10 }, MAXSIZE };
	//1�������󶥶ѣ����±�Ϊn/2�Ľڵ㿪ʼ
	for (i = L.length / 2; i > 0; i--)
	{
		HeapAddjust(&L, i, L.length);
	}
	//2����ȡ�Ӵ�С�ĶѶ����֣����¹����󶥶ѣ�����ȡ�������
	for (i = L.length; i > 1; i--)
	{
		Swap(&L, 1, i);//���Ѷ���¼�͵�ǰδ������������е����һ����¼����
		HeapAddjust(&L, 1, i - 1);//��L.r[1...i -1]���¹���Ϊ�󶥶ѣ��ӶѶ���ʼ
	}

	Print_Result(&L);//��ӡ����������
}

/****************************************6���鲢����**************************************************/
//���һ�����鲢������
void Merge(int SR[], int TR[], int left, int middle, int rightEnd)
{
	int j, k, l;
	for (j = middle + 1, k = left; left <= middle && j <= rightEnd; k++)
	{   
		if (SR[left] < SR[j])
		{
			TR[k] = SR[left++];
		}
		else
		{
			TR[k] = SR[j++];
		}
	}
	if (left <= middle)//�ұ��Ƚ���
	{
		for (l = 0; l <= (middle - left); l++)
		{
			TR[k + l] = SR[left + l];//ʣ�µ�Ԫ��ֱ�ӱ��浽Ŀ������
		}
	}
	if(j <= rightEnd)//����Ƚ���
	{
		for (l = 0; l <= (rightEnd - j); l++)
		{
			TR[k + l] = SR[j + l];
		}
	}
}

void MSort(int SR[], int TR1[], int left, int rightEnd)
{
	int middle;
	int TR2[MAXSIZE + 1];
	if (left == rightEnd)
	{
		TR1[left] = SR[rightEnd];
	}
	else
	{
		middle = (left + rightEnd) / 2;//ȡ�м�ֽ�
		MSort(SR, TR2, left, middle);//��ߵݹ�
		MSort(SR, TR2, middle + 1, rightEnd);//�ұߵݹ�
		Merge(TR2, TR1, left, middle, rightEnd);//�鲢������
	}
}

//�鲢�����㷨ʵ��
void MergeSort(void)
{
	SqList L = { { 0, 9, 1, 5, 8, 3 }, 5 };//��Ԫ�ر���������������
	MSort(L.r, L.r, 1, L.length);//���õݹ���ʽ
	Print_Result(&L);//��ӡ����������
}

/****************************************7����������**************************************************/
/*
	��������
	��1������˼�룺ͨ��һ�����򽫴������¼�ָ�ɶ����������֣�����һ���ּ�¼�Ĺؼ��־�����һ���ּ�¼�Ĺؼ���С��
	��ɷֱ���������ּ�¼�������������Ѵﵽ�������������Ŀ��
	��2���������̣�a.ѡ��pivot�����᣻b.������pivot�����ַ���pivot�ұߣ���С��pivot�����ַ���pivot��ߣ�
	c.�ֱ�������������ظ�ǰ����������
*/
int Partition(SqList *L, int low, int high)
{
	int pivotkey;
	pivotkey = L->r[low];//�̶�ѡȡ��1��Ԫ��Ϊ����
	while (low < high)
	{
		while (low < high && L->r[high] >= pivotkey)
		{
			high--;
		}
		Swap(L, low, high);
		while (low < high && L->r[low] <= pivotkey)
		{
			low++;
		}
		Swap(L, low, high);
	}
}

void QSort(SqList *L, int low, int high)
{
	int pivot;
	if (low < high)
	{
		pivot = Partition(L, low, high);
		QSort(L, low, pivot - 1);
		QSort(L, pivot + 1, high);
	}
}

//���������㷨ʵ��1
void QuickSort()
{
	SqList L = { { 0, 9, 1, 5, 8, 3, 8 }, 6 };//��Ԫ�ر���������������
	QSort(&L, 1, L.length);
	Print_Result(&L);//��ӡ����������
}

/****���������㷨�Ż�1****/
int Partition_2(SqList *L, int low, int high)
{
	int pivotkey;
	int mid = low + (high - low) / 2; // ��(low + high) / 2����Ϊ�˱�������������ӳ���int��Χ����תΪ��ʽlow + (high - low) / 2
	//�Ż�һ����pivotkeyֵ����ȡֵ�Ż�������ȡ��(ȥ����ֵ��Сֵ��ȡ�м�ֵΪ���ᣩ
	if (L->r[low] > L->r[high])
	{
		Swap(L, low, high);
	}
	if (L->r[mid] > L->r[high])
	{
		Swap(L, mid, high);
	}
	if (L->r[mid] > L->r[low])
	{
		Swap(L, mid, low);
	}
	/*��ʱL.r[low]�Ѿ�Ϊ�������������������ؼ��ֵ��м�ֵ*/

	pivotkey = L->r[low];
	L->r[0] = pivotkey;//������ֵ�浽�ڱ���
	//�Ż������Ż�����Ҫ�Ľ���
	while (low < high)
	{
		while (low < high && L->r[high] >= pivotkey)
		{
			high--;
		}
		L->r[low] = L->r[high];//ֱ���滻����Ϊ�״α���ʱ��L->r[low]�Ѿ����浽�ڱ���
		while (low < high && L->r[low] <= pivotkey)
		{
			low++;
		}
		L->r[high] = L->r[low];//ֱ���滻
	}
	L->r[low] = L->r[0];//����λ���滻Ϊ�ڱ�Ԫ�ؼ���
	return low;//������������λ��
}

void QSort_2(SqList *L, int low, int high)
{
	int pivot;
	if (low < high)
	{
		pivot = Partition_2(L, low, high);
		QSort_2(L, low, pivot - 1);
		QSort_2(L, pivot + 1, high);
	}
}
//������QSort_2���������Ż�
#define MAX_LENGTH_INSERT_SORT	7
void QSort_2_new(SqList *L, int low, int high)
{
	int pivot;
	if ((high - low) > MAX_LENGTH_INSERT_SORT)
	{
		while(low < high)
		pivot = Partition_2(L, low, high);
		QSort_2_new(L, low, pivot - 1);
		low = pivot + 1;//�Ż�һ��β�ݹ��Ż�������һ�εݹ����
	}
	else//�Ż�����С������ת��Ϊֱ�Ӳ����㷨Ϊ��
	{
		//InsertSort(L); //�˴��������޸�Ϊ��������ֱ�Ӳ����㷨
	}
}

//���������㷨ʵ��2--�Ż�1
void QuickSort_2()
{
	SqList L = { { 0, 9, 1, 5, 8, 3, 8 }, 6 };//��Ԫ�ر���������������
	QSort_2(&L, 1, L.length);
	Print_Result(&L);//��ӡ����������
}

void test_Sort(void)
{
	//1��ð������
	//BubbleSort_1();
	//BubbleSort_2();
	//BubbleSort_2_Improve();

	//2��ѡ������
	//SelectSort();

	//3��ֱ�Ӳ�������
	//InsertSort();

	//4��ϣ������
	//ShellSort();

	//5��������
	//HeapSort();

	//6���鲢����
	//MergeSort();

	//7����������
	//QuickSort();
	QuickSort_2();
}

