#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
	ʵ�ִ���ͷ���ĵ�����
	--zjp
	marc07@qq.com
*/
typedef int elemType;
typedef struct NodeList
{
	elemType element;
	struct NodeList *next;
}Node;

//1.��ʼ����ͷ���ĵ�����
void InitialList(Node **pNode)
{
	*pNode = (Node *)malloc(sizeof(Node));
	if (*pNode != NULL)
	{
		(*pNode)->next = NULL;
	}
	else
	{
		printf("InitialList fail:malloc error\n");
		return;
	}
	printf("InitialList success\n");
}

//2.������ͷ���ĵ�����
void CreateList(Node *pNode)
{
	Node *pInsert;
	Node *pMove;
	pInsert = (Node *)malloc(sizeof(Node));
	if (pInsert == NULL)
	{
		printf("CreateList fail:malloc error\n");
		return;
	}
	memset(pInsert, 0, sizeof(Node));
	pInsert->next = NULL;
	scanf("%d", &(pInsert->element));
	pMove = pNode;
	while (pInsert->element > 0)
	{
		pMove->next = pInsert;
		pMove = pInsert;
		pInsert = (Node *)malloc(sizeof(Node));
		if (pInsert == NULL)
		{
			printf("CreateList fail:malloc error\n");
			return;
		}
		memset(pInsert, 0, sizeof(Node));
		pInsert->next = NULL;
		scanf("%d", &(pInsert->element));
	}
	printf("CreateList success\n");
}

//3.��ӡ��ͷ���ĵ�����
void PrintList(Node *pNode)
{
	/**
	*  ע�⣬���������Ϊ�գ�ֻ��һ��ͷ��㣩����Ҳ��ʾ��ӡ�ɹ���ֻ������û��Ԫ�أ������Ϊ�գ�
	*/
	Node *pMove;
	pMove = pNode->next;
	while (pMove != NULL)
	{
		printf("%d ", pMove->element);
		pMove = pMove->next;
	}
	printf("\n");
	printf("PrintList success\n");
}

//4.������Ա��е�����Ԫ�أ����ͷ����нڵ㣨����ͷ��㣩��ʹ֮��Ϊһ���ձ�
void ClearList(Node *pNode)
{
	Node *pMove;
	pMove = pNode->next;
	while (pMove != NULL)
	{
		pNode->next = pMove->next;
		free(pMove);
		pMove = pNode->next;
	}
	printf("ClearList success\n");
}

//5.��ȡ��ͷ���ĵ�����ĳ���
int GetListSize(Node *pNode)
{
	int i = 0;
	Node *pMove;
	pMove = pNode->next;
	while (pMove != NULL)
	{
		i++;
		pMove = pMove->next;
	}
	return i;
}

//6.�жϴ�ͷ���ĵ������Ƿ�Ϊ�գ�Ϊ���򷵻�1�����򷵻�0
int IsEmptyList(Node *pNode)
{
	int isEmptyFlag = 0;
	if (pNode->next == NULL)
	{
		isEmptyFlag = 1;//����Ϊ��
	}
	else
	{
		isEmptyFlag = 0;//����ǿ�
	}
	return isEmptyFlag;
}

//7.��ȡ�������е�pos������е�Ԫ�أ�������-1����ʾû���ҵ�
int GetElement(Node *pNode, int pos)
{
	int i = 1;
	Node *pMove;
	pMove = pNode->next;
	while (pMove != NULL)
	{
		if (i == pos)
		{
			return pMove->element;
		}
		pMove = pMove->next;
		i++;
	}
	printf("GetElement fail:no element at pos=%d\n", pos);
	return -1;
}

//8.�ӵ������в��Ҿ��и���ֵx�ĵ�һ��Ԫ�أ������ҳɹ��򷵻ظý��data��Ĵ洢��ַ�����򷵻�NULL
int *GetElemAddr(Node *pNode, elemType x)
{
	int i;
	Node *pMove;
	pMove = pNode->next;
	while (pMove != NULL)
	{
		if (pMove->element == x)
		{
			return &(pMove->element);
		}
		pMove = pMove->next;
	}
	printf("GetElemAddr fail:no %d in pNode\n", x);
	return NULL;
}

//9.�ѵ������е�pos������ֵ�޸�Ϊx��ֵ
Node *ModifyElem(Node *pNode, int pos, elemType x)
{
	int i = 1;
	Node *pMove;
	pMove = pNode->next;
	while (pMove != NULL)
	{
		if (pos == i)
		{
			pMove->element = x;
			return pNode;
		}
		i++;
		pMove = pMove->next;
	}
	return NULL;
}

//10.������ı�ͷ����һ��Ԫ��
Node *InsertListHead(Node *pNode, elemType x)
{
	Node *pInsert;
	pInsert = (Node *)malloc(sizeof(Node));
	if (pInsert == NULL)
	{
		return NULL;
	}
	memset(pInsert, 0, sizeof(Node));
	pInsert->element = x;
	pInsert->next = pNode->next;
	pNode->next = pInsert;
	return pNode;
}

// 11.�������ĩβ���һ��Ԫ��
Node *InsertListTail(Node *pNode, elemType x)
{
	Node *pInsert;
	Node *pMove;
	pInsert = (Node *)malloc(sizeof(Node));
	if (pInsert == NULL)
	{
		return NULL;
	}
	memset(pInsert, 0, sizeof(Node));
	pInsert->element = x;
	pInsert->next = NULL;
	pMove = pNode;
	while (pMove->next != NULL)
	{
		pMove = pMove->next;
	}
	pMove->next = pInsert;
	return pNode;
}

//���������
void test_SinglyLinkedList(void)
{
	Node *pNode;
	Node *pTest = NULL;
	int temp = 0;
	int *test;

	InitialList(&pNode);//��ʼ������
	CreateList(pNode);//������������0��ɴ�����:1 2 3 4 5 6 7 8 9 10 
	PrintList(pNode);//��ӡ��������Ԫ�أ�1 2 3 4 5 6 7 8 9 10 
	temp = GetListSize(pNode);//��ȡ�����ȣ�10
	printf("GetListSize = %d\n", temp);
	temp = GetElement(pNode, 5);//��ȡ�����5��λ�õ�Ԫ��:5
	printf("GetElement = %d\n", temp);
	test = GetElemAddr(pNode, 5);//��ȡ�����5��λ��Ԫ�صĵ�ַ��0xxx(��ַ���)
	if(test != NULL)
	{
		printf("GetElemAddr = 0x%p\n", test);
	}
	pTest = ModifyElem(pNode, 10, 20);//�ı������е�10��λ��Ԫ��Ϊ20:
	if (pTest != NULL)
	{
		PrintList(pNode);//1 2 3 4 5 6 7 8 9 20 
	}
	pTest = InsertListHead(pNode, 50);//������ͷ������Ԫ��50:50 1 2 3 4 5 6 7 8 9 20
	if (pTest != NULL)
	{
		PrintList(pNode);
	}
	pTest = InsertListTail(pNode, 100);//������β������Ԫ��100:50 1 2 3 4 5 6 7 8 9 20 100
	if (pTest != NULL)
	{
		PrintList(pNode);
	}
	ClearList(pNode);//�������
	PrintList(pNode);//��ӡ�������������:��
	temp = GetListSize(pNode);//��ȡ��������ĳ��ȣ�Ϊ0
	printf("GetListSize = %d\n", temp);
}








