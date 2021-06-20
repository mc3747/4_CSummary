#include <stdio.h>
#include <stdlib.h>
/*
	ʵ�ִ�ͷ������ʽջ
	(������ģ��ջ��ջ��Ϊͷ����next��)
	--zjp
	marc07@qq.com
*/
typedef struct LSNode
{
	int data;
	struct LSNode *next;
}LinkStackNode;

//������ͷ������ʽջ
void CreateLinkedStack(LinkStackNode **pHead)
{
	*pHead = (LinkStackNode *)malloc(sizeof(LinkStackNode));
	if (pHead == NULL)
	{
		printf("CreateLinkedStack fail:malloc error\n");
		return;
	}
	(*pHead)->next = NULL;
}

//���ջ
void ClearLinkStack(LinkStackNode *pHead)
{
	LinkStackNode *pDel;
	pDel = pHead->next;
	while (pDel != NULL)
	{
		pHead->next = pDel->next;
		free(pDel);
		pDel = pHead->next;//��ͷ����ȡ��һ��Ҫ�ͷŵĽ��
	}
}

//�ж�ջ�Ƿ�Ϊ��
int IsEmptyLinkStack(LinkStackNode *pHead)
{
	if (pHead->next == NULL)
	{
		printf("ջΪ��\n");
		return 1;
	}
	return 0;
}

//��ջ
void PushLinkedStack(LinkStackNode *pHead, int data)
{
	LinkStackNode *pInsert;
	pInsert = (LinkStackNode *)malloc(sizeof(LinkStackNode));
	if (pInsert == NULL)
	{
		printf("PushLinkedStack fail:malloc error\n");
		return;
	}
	pInsert->data = data;
	pInsert->next = pHead->next;//������ͷ�巨
	pHead->next = pInsert;
}

//��ջ
void PopLinkStack(LinkStackNode *pHead, int *data)
{
	LinkStackNode *pNode;
	if (IsEmptyLinkStack(pHead))
	{
		return;
	}
	pNode = pHead->next;
	*data = pNode->data;
	pHead->next = pNode->next;//����ջ�Ľ�����һ�����������ͷ���
	free(pNode);//�ͷų�ջ��㣬��ֹ�ڴ�й©
	pNode = NULL;//ָ��NULL����ֹҰָ��
}

//��ȡջ��Ԫ��
void GetTopElement_LinkStack(LinkStackNode *pHead, int *data)
{
	if (IsEmptyLinkStack(pHead))
	{
		return;
	}
	*data = pHead->next->data;//ͷ������һ�����Ϊջ�����
}

//��ȡջ��С
int GetSize_LinkStack(LinkStackNode *pHead)
{
	int size = 0;
	LinkStackNode *pMove;
	pMove = pHead->next;
	while (pMove != NULL)
	{
		size++;
		pMove = pMove->next;
	}
	return size;
}

//��ӡջԪ��
void PrintLinkStack(LinkStackNode *pHead)
{
	LinkStackNode *pMove;
	pMove = pHead->next;
	while (pMove != NULL)
	{
		printf("%d ", pMove->data);
		pMove = pMove->next;
	}
	printf("\n");
}

//������ʽջ
void test_Stack_Link(void)
{
	int value;
	LinkStackNode *pHead;
	//������ʽջ
	CreateLinkedStack(&pHead);
	//��ջ
	PushLinkedStack(pHead, 1);
	PushLinkedStack(pHead, 3);
	PushLinkedStack(pHead, 5);
	PushLinkedStack(pHead, 7);
	PushLinkedStack(pHead, 9);
	//��ӡջԪ��
	PrintLinkStack(pHead);//9 7 5 3 1
	//��ȡջ��С
	value = GetSize_LinkStack(pHead);
	printf("size:%d\n", value);//5
	//��ȡջ��Ԫ��
	GetTopElement_LinkStack(pHead, &value);
	printf("ջ��Ԫ�� = %d\r\n", value);//9
	//��ջ
	PopLinkStack(pHead, &value);
	printf("��ջԪ�� = %d\r\n", value);//9
	PopLinkStack(pHead, &value);
	printf("��ջԪ�� = %d\r\n", value);//7
	PopLinkStack(pHead, &value);
	printf("��ջԪ�� = %d\r\n", value);//5
	PopLinkStack(pHead, &value);
	printf("��ջԪ�� = %d\r\n", value);//3
	PopLinkStack(pHead, &value);
	printf("��ջԪ�� = %d\r\n", value);//1
	//��ջ�������
	PopLinkStack(pHead, &value);//ջΪ��
	//���ջ
	ClearLinkStack(pHead);
	//�ж�ջ�Ƿ�Ϊ��
	IsEmptyLinkStack(pHead);//ջΪ��
}


