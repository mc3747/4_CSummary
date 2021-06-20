#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
	�����㷨-������������-��������-��������
	--zjp
	marc07@qq.com
*/

//����ʵ�֣��༶��10��ѧ�������ڽ��г�����������

#define MAX_DATA_SIZE	10
typedef struct _Student  //��¼
{
	int key;//�����ؼ��룬�˴������ѧ��ѧ��
	char name[10]; //ѧ����Ϣ
	struct _Student *next;
}Student;

typedef struct _Index //����
{
	int key;
	Student *ind;
}Index;

Student* S;
Index I[MAX_DATA_SIZE];//��Ԫ��������ʹ�ã����ڼ�¼��������
int Insert_Search(Index *ind, int n, int key, int *loc);

//������Ϣ��������������
void AddInfo(int key, char* name)
{
	//��������
	Student *ST;
	int loc, i;
	ST = (Student *)malloc(sizeof(Student));
	strcpy(ST->name, name);
	ST->key = key;
	ST->next = S;//����ͷ�����뷨
	S = ST;
	//��������
	if (Insert_Search(I, I[0].key, ST->key, &loc) == -1)
	{
		for (i = I[0].key + 1; i > loc; i--)//locΪĿ��Ӧ�����λ�ã�����ֱ�Ӳ��������㷨
		{	//�ڳ��ռ�	
			I[i].key = I[i - 1].key;
			I[i].ind = I[i - 1].ind;
		}
		//����Ŀ��Ԫ��
		I[i].key = ST->key;
		I[i].ind = ST;
		I[0].key++;    //�洢�����С
	}
}

//����Ԫ��
int Search_Info(int key, Student** stu)
{
	int loc, res = -1;
	res = Insert_Search(I, I[0].key, key, &loc);
	if (res != -1) {
		*stu = I[loc].ind;
		printf("the target key=%d index is %d\n", key, loc);
	} else {
		return -1;
	}
	return 1;
}

//��ֵ����
int Insert_Search(Index *ind, int n, int key, int *loc)
{
	int low, high, mid;
	low = 1;
	high = n;
	if (n <= 1)
		mid = n + 1;//��0��1��Ŀ��Ԫ�صĲ���λ��Ϊ�������1��2λ��
	if (key<I[low].key)
	{
		*loc = low;//������Ԫ��С���������1��Ԫ�أ���Ŀ��Ԫ�ز��뵽�������1Ԫ��λ��
		return -1;
	}
	else if (key > I[high].key)
	{
		*loc = high + 1;//������Ԫ�ش������������Ԫ�أ���Ŀ��Ԫ�ز��뵽���������Ԫ�ص���һ��λ��
		return -1;
	}
	else
	{
		while (low <= high)
		{
			mid = low + (key - ind[low].key) / (ind[high].key - ind[low].key) * (high - low);//��ֵ����
			//mid = low + (high - low) / 2; //�۰���ң�����ֲ���
			if (ind[mid].key < key)
				low = mid + 1;
			else if (ind[mid].key > key)
				high = mid - 1;
			else
			{
				*loc = mid;
				return mid;
			}
		}
		mid++;//λ�ü�1������ȷ�Ĳ���λ��
	}
	*loc = mid;//�õ�Ŀ��Ԫ�ز���λ��
	return -1;
}

void test_DenseIndex(void)
{
	int key;
	char name[10];
	Student* info;
	I[0].key = 0;//��������Ԫ�ر���ʹ�ã����ڼ�¼������ǰ����

	//����Ŀ��Ԫ��
	key = 10;
	strcpy(name, "zjp1");
	AddInfo(key, name);

	key = 30;
	strcpy(name, "zjp3");
	AddInfo(key, name);

	key = 50;
	strcpy(name, "zjp5");
	AddInfo(key, name);

	key = 20; //�����ǰ��Ԫ����ֵС��Ԫ��
	strcpy(name, "zjp2");
	AddInfo(key, name);

	key = 1; //�����ǰ��Ԫ����ֵС��Ԫ��
	strcpy(name, "zjp1-1");
	AddInfo(key, name);

	//����Ŀ��1
	if (Search_Info(50, &info) == 1)
		printf("find student:%s %d\n", info->name, info->key);
	else
		printf("no find\n");
	//����Ŀ��2
	if (Search_Info(1, &info) == 1)
		printf("find student:%s %d\n", info->name, info->key);
	else
		printf("no find\n");

	//��ӡ������ؼ���
	for (int i = 0; i < MAX_DATA_SIZE; i++)
	{
		printf("Index[%d].key = %d\n", i, I[i].key);//��Ԫ��Ϊ��������
	}
}

