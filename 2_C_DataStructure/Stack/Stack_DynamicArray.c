#include <stdio.h>
#include <stdlib.h>
/*
	ʵ�ֶ�̬˳��ջ
	--zjp
	marc07@qq.com
*/
typedef struct DSNode
{
	int *stack_arr;//ջ��
	int stack_size;//ջ��С
	int stack_top;//ջ��
}DynamicStackNode;//��̬˳��ջ�ṹ

//������̬˳��ջ
DynamicStackNode *CreateDynamicStack(int capacity)
{
	DynamicStackNode *ptr = (DynamicStackNode *)malloc(sizeof(DynamicStackNode));
	if (ptr == NULL)
	{
		printf("CreateDynamicStack fail:malloc error\n");
		return;
	}
	ptr->stack_size = capacity;
	ptr->stack_top = -1;
	ptr->stack_arr = (int *)malloc(capacity * sizeof(int));
	if (ptr->stack_arr == NULL)
	{
		printf("CreateDynamicStack fail:malloc error\n");
		return;
	}
	return ptr;
}

//�ж�ջ�Ƿ�Ϊ��
int IsFullDynamicStack(DynamicStackNode *ptr)
{
	if (ptr->stack_top == ptr->stack_size - 1)
	{
		return 1;//ջΪ��
	}
	return 0;//ջΪδ��
}

//�ж�ջ�Ƿ�Ϊ��
int IsEmptyDynamicStack(DynamicStackNode *ptr)
{
	if (ptr->stack_top == -1)
	{
		return 1;//ջΪ��
	}
	return 0;//ջΪ�ǿ�
}

//��ջ
void PushDynamicStack(DynamicStackNode *ptr, int value)
{
	if (IsFullDynamicStack(ptr))
	{
		printf("ջ������ջʧ��\n");
		return;
	}

	ptr->stack_top++;
	ptr->stack_arr[ptr->stack_top] = value;
	printf("��ջԪ�أ�%d\n", ptr->stack_arr[ptr->stack_top]);
}

//��ջ
void PopDynamicStack(DynamicStackNode *ptr, int *value)
{
	if (IsEmptyDynamicStack(ptr))
	{
		printf("ջ�գ���ջʧ��\n");
		return;
	}

	*value = ptr->stack_arr[ptr->stack_top];
	ptr->stack_top--;
	printf("��ջԪ�أ�%d\n", *value);
}

//��ȡջ��Ԫ��
void GetTopElement_DStack(DynamicStackNode *ptr, int *top_value)
{
	if (IsEmptyDynamicStack(ptr))
	{
		printf("ջ�գ���ȡʧ��\n");
		return;
	}
	*top_value = ptr->stack_arr[ptr->stack_top];
	printf("ջ��Ԫ�أ�%d\n", *top_value);
}

//����ջ
void PrintDynamicStack(DynamicStackNode *ptr)
{
	int value;
	int i;
	if (IsEmptyDynamicStack(ptr))
	{
		printf("ջ�գ�����ʧ��\n");
		return;
	}
	printf("��ǰԪ�أ�\n");
	for (i = ptr->stack_top; i >= 0; i--)
	{
		value = ptr->stack_arr[i];
		printf("%d ", value);
	}
	printf("\n");
}

//���Զ�̬˳��ջ
void test_Stack_DynamicArray(void)
{
	int top_value;
	DynamicStackNode *ptr;
	//��0��������̬˳��ջ
	ptr = CreateDynamicStack(5);
	//��1����ջ����
	PushDynamicStack(ptr, 1);
	PushDynamicStack(ptr, 2);
	PushDynamicStack(ptr, 3);
	PushDynamicStack(ptr, 4);
	PushDynamicStack(ptr, 5);
	//��ӡջ
	PrintDynamicStack(ptr);//5 4 3 2 1
	//��ȡջ��Ԫ��
	GetTopElement_DStack(ptr, &top_value);//5
	//��ջ�����ջ��������
	PushDynamicStack(ptr, 6);//ջ������ջʧ��
	PrintDynamicStack(ptr);//5 4 3 2 1

	//��2����ջ����
	PopDynamicStack(ptr, &top_value);
	PopDynamicStack(ptr, &top_value);
	PopDynamicStack(ptr, &top_value);
	PopDynamicStack(ptr, &top_value);
	PopDynamicStack(ptr, &top_value);
	//��ӡ��ջ
	PrintDynamicStack(ptr);//���գ�
	//��ջ�����ջ�գ�����
	PopDynamicStack(ptr, &top_value);//ջ�գ���ջʧ��
	//�ٴ���ջ
	PushDynamicStack(ptr, 1);
	PushDynamicStack(ptr, 2);
	PrintDynamicStack(ptr);//2 1
	GetTopElement_DStack(ptr, &top_value);//2
}

