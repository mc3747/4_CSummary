#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
	ʵ��ѭ�����������ϲ�
	--zjp
	marc07@qq.com
*/
typedef struct node
{
	int data;
	struct node *pNext;
}CLListNode;

//����ѭ������
CLListNode *Create_CLList(int arr[], int length)
{
	CLListNode *head, *pNewNode, *rear;
	int i;
	head = (CLListNode *)malloc(sizeof(CLListNode));
	rear = head;

	for (i = 0; i < length; i++)
	{
		pNewNode = (CLListNode *)malloc(sizeof(CLListNode));
		pNewNode->data = arr[i];
		rear->pNext = pNewNode;
		rear = pNewNode;
	}
	rear->pNext = head;//��β����next��ָ��ͷ��㣬�γ�ѭ��
	return rear;//����β���ָ��
}

//�������
void Print_CLList(CLListNode *p)
{
	CLListNode *pHead = p->pNext;//ѭ����������βָ���next��ָ�����ͷ���
	CLListNode *pCur = pHead->pNext;
	while (pCur != pHead)
	{
		printf("%d ", pCur->data);
		pCur = pCur->pNext;
	}
	printf("\n");
}

//����ѭ������ϲ�
//�������������aβָ�룬����bβָ��
//����ֵ���ϲ��������βָ��
CLListNode *Connect_CLList(CLListNode *La, CLListNode *Lb)
{
	CLListNode *p;
	p = La->pNext;//��¼����a��ͷ����ַ
	La->pNext = Lb->pNext->pNext;//������b�ĵ�һ����㣨��ͷ��㣩���ӵ�����a��β��
	free(Lb->pNext);//�ͷ�����b��ͷ��㣬��Ϊ����Ҫ����ͷ��㣬ֻ��������a��ͷ���
	Lb->pNext = p;//��ԭ������a��ͷ������ӵ�����b��β��
	return Lb;//�����������βָ��
/*	        _______________________________
	       |							   |
	����a ͷ���++++++++++++++++++++++++++La |
	        ____________________________|  |
	       |							   |
	����b ��һ�����+++++++++++++++++++++++++Lb
	*/
}

void test_CircularLinkedList(void)
{
	//��ѭ������
	int arr[] = { 11, 22, 33, 44, 55 };
	CLListNode *pRear = Create_CLList(arr, sizeof(arr)/sizeof(int));
	Print_CLList(pRear);//11 22 33 44 55
	printf("===============\n");
	//˫ѭ������ϲ�
	int La_arr[] = { 1, 3, 5, 7, 9 };
	int Lb_arr[] = { 2, 4, 6, 8, 10};
	CLListNode *La = Create_CLList(La_arr, sizeof(La_arr) / sizeof(int));
	CLListNode *Lb = Create_CLList(Lb_arr, sizeof(Lb_arr) / sizeof(int));
	CLListNode *pRear_Con = Connect_CLList(La, Lb);
	Print_CLList(pRear_Con);//1 3 5 7 9 2 4 6 8 10
}
