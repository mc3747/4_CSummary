#include <stdio.h>
#include <stdlib.h>
/*
	ѭ������Ӧ�ã����Լɪ������
	--zjp
	marc07@qq.com
*/
typedef struct node
{
	int data;
	struct node *pNext;
}JoseListNode;

//����Լɪ�򻷵�ѭ������
//����ͷ��㣺ģ��Լɪ�򻷵Ĺ�������
JoseListNode *Create_JoeList(int arr[], int length)
{
	JoseListNode *head, *pNewNode, *rear;
	int i;
	head = (JoseListNode *)malloc(sizeof(JoseListNode));//�����׽��
	if (head == NULL)
	{
		printf("Create_JoeList fail:head malloc error\n");
		return NULL;
	}
	head->data = arr[0];//�׽�㸳ֵ  ps:ע����ͷ�������ͷ��㲻��ֵ
	rear = head;
	for (i = 1; i < length; i++)
	{
		pNewNode = (JoseListNode *)malloc(sizeof(JoseListNode));
		if (pNewNode == NULL)
		{
			printf("Create_JoeList fail:pNewNode malloc error\n");
			return NULL;
		}
		pNewNode->data = arr[i];
		rear->pNext = pNewNode;//�����½��
		rear = pNewNode;//βָ�����
	}
	rear->pNext = head;//βָ��ָ���׽��
	return rear;
}

void test_CircularLinkedList_JosephRing(void)
{
	//��λ��1��ʼ����ʼ30�ˣ�ʣ��15��
	int s = 1;//λ��1
	int m = 9;//ÿ��9�ͳ�Ȧ
	int k = 15;//������Ҫ��15�ˣ�������Ȧ��Ҫ��15��
	int arr[30];//30�������
	//�����ʼ����
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		arr[i] = i + s;//��λ��1��ʼ��1 2 3 4 5  6 ....29 30
	}
	//����ѭ������
	JoseListNode *p, *q;
	JoseListNode *rear;
	rear = Create_JoeList(arr, sizeof(arr) / sizeof(int));
	p = rear;//pΪ����ָ��
	//Լɪ�򻷴���
	while (k > 0)//��Ȧ����
	{
		for (int j = 0; j < m - 1; j++)
		{
			p = p->pNext;//ָ��ƫ�ƣ�����ƫ�ƣ�
		}
		//��ʱ��pͣ��m-1��
		q = p->pNext;//qָ���m����
		printf("��%d��Ԫ�س�Ȧ\n", q->data);
		//��m-1��m+1����
		p->pNext = p->pNext->pNext;
		free(q);//�ͷŵ�m����㣬��Ȧ
		k--;
	}
}