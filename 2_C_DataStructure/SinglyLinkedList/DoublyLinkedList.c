#include <stdio.h>
#include <stdlib.h>
/*
	ʵ�ִ�ͷ��㡢β����˫������(��ѭ��)
	--zjp
	marc07@qq.com
*/
typedef struct DNode
{
	int data;
	struct DNode *prev, *next;
}DListNode;

//1.��ʼ����ͷ��㡢β����˫���ѭ������
void Init_DList(DListNode **pHead, DListNode **pTail)
{
	*pHead = (DListNode *)malloc(sizeof(DListNode));
	*pTail = (DListNode *)malloc(sizeof(DListNode));
	if (*pHead == NULL || *pTail == NULL)
	{
		printf("Init_DList fail:malloc error\n");
		return;
	}
	(*pHead)->prev = NULL;//ͷ����ǰ��Ϊ��ָ��
	(*pTail)->next = NULL;//β���ĺ��Ϊ��ָ��
	//����Ϊ��ʱ����ͷ����β�������
	(*pHead)->next = (*pTail);
	(*pTail)->prev = (*pHead);
}

//2.������ͷ��㡢β����˫���ѭ������
void Create_DList(DListNode *pHead, DListNode *pTail)
{
	DListNode *pMove;
	DListNode *pInsert = (DListNode *)malloc(sizeof(DListNode));
	if (pInsert == NULL)
	{
		printf("Create_DList fail:malloc error\n");
		return;
	}
	pInsert->prev = NULL;
	pInsert->next = NULL;
	pMove = pHead;
	scanf("%d", &(pInsert->data));
	while (pInsert->data > 0)//���������ݣ�����0��ɴ���
	{
		pMove->next = pInsert;
		pInsert->prev = pMove;//�����ϸ������
		pInsert->next = pTail;
		pTail->prev = pInsert;
		pMove = pInsert;

		pInsert = (DListNode *)malloc(sizeof(DListNode));
		if (pInsert == NULL)
		{
			printf("Create_DList fail:malloc error\n");
			return;
		}
		pInsert->prev = NULL;
		pInsert->next = NULL;
		scanf("%d", &(pInsert->data));
	}
}

//3.�����ӡ����
void Print_DList(DListNode *pHead, DListNode *pTail)
{
	DListNode *pMove;
	pMove = pHead->next;
	while (pMove != pTail)
	{
		printf("%d ", pMove->data);
		pMove = pMove->next;
	}
	printf("\n");
}

//4.�����ӡ����
void Print_Reverse_DList(DListNode *pHead, DListNode *pTail)
{
	DListNode *pMove;
	pMove = pTail->prev;
	while (pMove != pHead)
	{
		printf("%d ", pMove->data);
		pMove = pMove->prev;
	}
	printf("\n");
}

//5.�������������Ԫ�أ���Ϊ�ձ�
void Clear_DList(DListNode *pHead, DListNode *pTail)
{
	DListNode *pMove;
	pMove = pHead->next;
	while (pMove != pTail)
	{
		pMove->next->prev = pHead;
		pHead->next = pMove->next;
		free(pMove);
		pMove = pHead->next;
	}
}

//6.����������
int GetSize_DList(DListNode *pHead, DListNode *pTail)
{
	int length = 0;
	DListNode *pMove;
	pMove = pHead->next;
	while (pMove != pTail)
	{
		length++;
		pMove = pMove->next;
	}
	printf("GetSize_DList = %d\n", length);
	return length;
}

//7.�ж������Ƿ�Ϊ��
int IsEmpty_DList(DListNode *pHead, DListNode *pTail)
{
	if (pHead->next == pTail)
	{
		printf("��ǰ����Ϊ��\n");
		return 1;
	}
	else
	{
		printf("��ǰ����ǿ�");
		return 0;
	}
}

//8.��ȡ�����е�pos������е�Ԫ�أ�����ֵ-1��ʾ��ȡʧ��
int GetElementFromPos_DList(DListNode *pHead, DListNode *pTail, int pos)
{
	int i = 1;//�ӵ�1�������
	DListNode *pMove;
	if (pos < 1)
	{
		printf("Error.Please input 'pos' > 0.\n");
		return -1;
	}
	pMove = pHead->next;
	while (pMove != pTail)
	{
		if (i == pos)
		{
			printf("pos = %d, value = %d\n", pos, pMove->data);
			return pMove->data;//�����ҵ���Ԫ��
		}
		i++;
		pMove = pMove->next;
	}
	printf("GetElementFromPos fail.\n");
	return -1;
}

//9.��ȡ����ֵx�ĵ�һ��Ԫ�أ�����data���ַ
int *GetElementAddr_DList(DListNode *pHead, DListNode *pTail, int x)
{
	DListNode *pMove;
	pMove = pHead->next;
	while (pMove != pTail)
	{
		if (pMove->data == x)
		{
			printf("The x=%d addr is 0x%p\n", x, &(pMove->data));
			return &(pMove->data);//����Ԫ�ص�ַ
		}
		pMove = pMove->next;
	}
	printf("GetElementAddr fail\n");
	return NULL;
}

//10.�������е�pos����������ֵ�޸�Ϊx
int ModifyElement_DList(DListNode *pHead, DListNode *pTail, int pos, int x)
{
	int i = 1;//�ӵ�1�������
	DListNode *pMove;
	if (pos < 1)
	{
		printf("please input 'pos' > 0.\n");
		return -1;
	}
	pMove = pHead->next;
	while (pMove != pTail)
	{
		if (i == pos)
		{
			pMove->data = x;//�޸�Ԫ��
			return 1;
		}
		i++;
		pMove = pMove->next;
	}
	printf("ModifyElement_DList fail\n");
	return -1;
}

//11.������ͷ������Ԫ��
int InsertElement_Head_DList(DListNode *pHead, DListNode *pTail, int x)
{
	DListNode *pInsert = (DListNode *)malloc(sizeof(DListNode));
	if (pInsert == NULL)
	{
		printf("InsertElement_Head_DList fail:malloc error\n");
		return -1;
	}
	pInsert->data = x;
	pHead->next->prev = pInsert;//��ͷ���Ϊ��׼
	pInsert->next = pHead->next;
	pInsert->prev = pHead;
	pHead->next = pInsert;
	return 1;
}

//12.������β������Ԫ��
int InsertElement_Tail_DList(DListNode *pHead, DListNode *pTail, int x)
{
	DListNode *pInsert = (DListNode *)malloc(sizeof(DListNode));
	if (pInsert == NULL)
	{
		printf("InsertElement_Head_DList fail:malloc error\n");
		return -1;
	}
	pInsert->data = x;
	pTail->prev->next = pInsert;//��β���Ϊ��׼
	pInsert->prev = pTail->prev;
	pInsert->next = pTail;
	pTail->prev = pInsert;
	return 1;
}

void test_DoublyLinkedList(void)
{
	DListNode *pHead, *pTail;
	//��ʼ��˫����ͷ��㡢β���
	Init_DList(&pHead, &pTail);
	//����˫����
	Create_DList(pHead, pTail);
	//��ӡ˫����
	Print_DList(pHead, pTail);//1 2 3 4 5 6
	//�����ӡ˫����
	Print_Reverse_DList(pHead, pTail);// 6 5 4 3 2 1 
	//��ȡ˫������
	GetSize_DList(pHead, pTail);//6
	//��ȡָ��λ��Ԫ��
	GetElementFromPos_DList(pHead, pTail, 5);//5
	//��ȡָ��Ԫ�ص�һ��λ�õĵ�ַ
	GetElementAddr_DList(pHead, pTail, 3);//��ַ���
	//�ı�ָ��λ�õ�Ԫ��ֵ
	ModifyElement_DList(pHead, pTail, 3, 10);
	Print_DList(pHead, pTail);//1 2 10 4 5 6
	//ͷ�����뷨
	InsertElement_Head_DList(pHead, pTail, 99);
	Print_DList(pHead, pTail);//99 1 2 10 4 5 6
	InsertElement_Head_DList(pHead, pTail, 98);
	Print_DList(pHead, pTail);//98 99 1 2 10 4 5 6
    //β�����뷨
	InsertElement_Tail_DList(pHead, pTail, 100);
	Print_DList(pHead, pTail);//98 99 1 2 10 4 5 6 100
	//���˫����
	Clear_DList(pHead, pTail);
	//�ж�˫�����Ƿ�Ϊ��
	IsEmpty_DList(pHead, pTail);//��ǰ����Ϊ��
}



