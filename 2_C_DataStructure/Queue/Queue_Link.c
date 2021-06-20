#include <stdio.h>
#include<string.h>
/*
	ʵ����ʽ����
	--zjp
	marc07@qq.com
	����ȷ�����г������ֵ������£�����ѭ�����У����޷�Ԥ�����г��ȣ�������ʽ����
*/
typedef int DataType;
typedef struct Node
{
	DataType data;
	struct LinkQueueNode *next;
}LinkQueueNode;//���еĽ��ṹ

typedef struct
{
	LinkQueueNode *front;
	LinkQueueNode *rear;
}LinkQueue;//���е�����ṹ

//��ʼ������
void InitLinkQueue(LinkQueue *LQ)
{
	//����ͷ���
	LinkQueueNode *pHead = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	if (pHead == NULL)
	{
		printf("InitLinkQueue fail:malloc error\n");
		return;
	}
	LQ->front = LQ->rear = pHead;//��ͷ�Ͷ�βָ��ͷ��� ps:��Ҫ������Ĳ������ǻ��ڴ�
	LQ->front->next = NULL;
}

//�ж϶����Ƿ�Ϊ��
int IsEmptyQueue(LinkQueue *LQ)
{
	if (LQ->front == LQ->rear)//��ͷָ�����βָ����ȣ�����Ϊ��
	{
		return 1;//����Ϊ��
	}
	return 0;
}

//��Ԫ�����
void EnterLinkQueue(LinkQueue *LQ, DataType data)
{
	LinkQueueNode *pNewNode = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	if (pNewNode == NULL)
	{
		printf("EnterLinkQueue fail:malloc error\n");
		return;
	}
	//��ʽ���еĽ���Ƕ�̬���ٵģ�û���ж϶����Ƿ�Ϊ���Ĳ���
	//�������
	pNewNode->data = data;//������Ԫ�ظ�ֵ������������
	pNewNode->next = NULL;//������ָ�����ÿ�
	//ʵ�ֲ���
	LQ->rear->next = pNewNode;//�½��ӵ���һ�����β��
	LQ->rear = pNewNode;//��βָ������ָ�����ζ�β
}

//Ԫ�س���
void DeleteLinkQueue(LinkQueue *LQ, DataType *data)
{
	if (IsEmptyQueue(LQ))
	{
		printf("����Ϊ�գ�����ʧ��\n");
		return;
	}
	//pDelָ���ͷԪ�أ����ڶ�ͷָ��frontָ��ͷ��㣬����pDelָ��ͷ������һ�����
	LinkQueueNode *pDel = LQ->front->next;
	*data = pDel->data;//��Ҫ���ӵ�Ԫ�ظ���data
	LQ->front->next = pDel->next;//ʹָ��ͷ����ָ��ָ��pDel����һ�����
	if (LQ->rear == pDel )//���������ֻ��һ��Ԫ��,����βָ��ָ��ͷ��㣬����Ϊ��
	{
		LQ->rear = LQ->front;
	}
	free(pDel);//�ͷ�pDelָ��Ŀռ�
}

//��ȡ��ͷԪ��
int GetHeadData(LinkQueue *LQ, DataType *data)
{
	if (IsEmptyQueue(LQ))
	{
		printf("����Ϊ��\n");
		return 0;
	}
	LinkQueueNode *pCur = LQ->front->next;//pCurָ����еĵ�һ��Ԫ�أ���ͷ������һ�����
	*data = pCur->data;
	return *data;
}

//��ȡ���г���
int GetLinkQueueLength(LinkQueue *LQ)
{
	int length = 0;
	LinkQueueNode *pCur = LQ->front->next;
	while (pCur != NULL)
	{
		length++;
		pCur = pCur->next;
	}
	return length;
}

//��ӡ����Ԫ��
void PrintLinkQueue(LinkQueue *LQ)
{
	LinkQueueNode *pCur;
	pCur = LQ->front->next;
	while (pCur != NULL)
	{
		printf("%d ", pCur->data);
		pCur = pCur->next;
	}
	printf("\n");
}

//��ն���
void ClearLinkQueue(LinkQueue *LQ)
{
	while (LQ->front != NULL)
	{
		LQ->rear = LQ->front->next;//��ɾ������ʱ����βָ���û�ô��ˣ��˴����ö�βָ���������ͷָ�����һ�����
		free(LQ->front);//ȫ���ͷţ�����ͷ���
		LQ->front = LQ->rear;
	}
}

//��ʽ���в���
void test_Queue_Link(void)
{
	DataType value;
	LinkQueue *LQ = (LinkQueue *)malloc(sizeof(LinkQueue));
	if (LQ == NULL)
	{
		printf("LQ malloc error\n");
		return;
	}
	//��ʼ������
	InitLinkQueue(LQ);
	//���
	EnterLinkQueue(LQ, 1);
	EnterLinkQueue(LQ, 2);
	EnterLinkQueue(LQ, 3);
	EnterLinkQueue(LQ, 4);
	EnterLinkQueue(LQ, 5); 
	EnterLinkQueue(LQ, 6);
	EnterLinkQueue(LQ, 7);
	//��ӡ������Ԫ��
	printf("�����е�Ԫ��Ϊ��");
	PrintLinkQueue(LQ);//�����е�Ԫ��Ϊ��1 2 3 4 5 6 7
	//��ȡ���г���
	value = GetLinkQueueLength(LQ);
	printf("���г���Ϊ��%d\n", value);//���г���Ϊ��7
	//ȡ��ͷԪ��
	value = GetHeadData(LQ, &value);
	printf("��ͷԪ��Ϊ��%d\n", value);//��ͷԪ��Ϊ��1
	//����
	DeleteLinkQueue(LQ, &value);
	printf("���ӵ�Ԫ��Ϊ��%d\n", value);//���ӵ�Ԫ��Ϊ��1
	//��ӡ������Ԫ��
	printf("�����е�Ԫ��Ϊ��");//�����е�Ԫ��Ϊ��2 3 4 5 6 7
	PrintLinkQueue(LQ);
	//��ȡ���г���
	value = GetLinkQueueLength(LQ);
	printf("���г���Ϊ��%d\n", value);//���г���Ϊ��6
	//ȡ��ͷԪ��
	value = GetHeadData(LQ, &value);
	printf("��ͷԪ��Ϊ��%d\n", value);//��ͷԪ��Ϊ��2

	//��������
	DeleteLinkQueue(LQ, &value);
	DeleteLinkQueue(LQ, &value);
	DeleteLinkQueue(LQ, &value);
	DeleteLinkQueue(LQ, &value);
	DeleteLinkQueue(LQ, &value);
	DeleteLinkQueue(LQ, &value);
	printf("�����е�Ԫ��Ϊ��");
	PrintLinkQueue(LQ);//�����е�Ԫ��Ϊ�����գ�   ps:ȫ���������
	//�ٴγ��ӣ����Գ������
	DeleteLinkQueue(LQ, &value);//����Ϊ�գ�����ʧ��
	//��ȡ���г���
	value = GetLinkQueueLength(LQ);
	printf("���г���Ϊ��%d\n", value);//���г���Ϊ��0
	//��ն���
	ClearLinkQueue(LQ);
}


