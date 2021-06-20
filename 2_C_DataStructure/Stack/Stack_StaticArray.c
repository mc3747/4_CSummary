#include <stdio.h>
/*
	ʵ�־�̬˳��ջ
	--zjp
	marc07@qq.com
*/
#define STACK_MAX_SIZE	5
typedef struct SSNode
{
	int stack_arr[STACK_MAX_SIZE];
	int stack_top;
}StaticStackNode;

//�ж�ջ�Ƿ�Ϊ��
int IsFullStaticStack(StaticStackNode *ptr)
{
	if (ptr->stack_top == STACK_MAX_SIZE - 1)
	{
		return 1;//ջΪ��
	}
	return 0;//ջΪδ��
}

//�ж�ջ�Ƿ�Ϊ��
int IsEmptyStaticStack(StaticStackNode *ptr)
{
	if (ptr->stack_top == -1)
	{
		return 1;//ջΪ��
	}
	return 0;//ջΪ�ǿ�
}

//��ջ
void PushStaticStack(StaticStackNode *ptr, int value)
{
	if (IsFullStaticStack(ptr))
	{
		printf("ջ������ջʧ��\n");
		return;
	}
	
	ptr->stack_top++;
	ptr->stack_arr[ptr->stack_top] = value;
	printf("��ջԪ�أ�%d\n", ptr->stack_arr[ptr->stack_top]);
}

//��ջ
void PopStaticStack(StaticStackNode *ptr, int *value)
{
	if (IsEmptyStaticStack(ptr))
	{
		printf("ջ�գ���ջʧ��\n");
		return;
	}

	*value = ptr->stack_arr[ptr->stack_top];
	ptr->stack_top--;
	printf("��ջԪ�أ�%d\n", *value);
}

//��ȡջ��Ԫ��
void GetTopElement(StaticStackNode *ptr, int *top_value)
{
	if (IsEmptyStaticStack(ptr))
	{
		printf("ջ�գ���ȡʧ��\n");
		return;
	}
	*top_value = ptr->stack_arr[ptr->stack_top];
	printf("ջ��Ԫ�أ�%d\n", *top_value);
}

//����ջ
void PrintStaticStack(StaticStackNode *ptr)
{
	int value;
	int i;
	if (IsEmptyStaticStack(ptr))
	{
		printf("ջ�գ�����ʧ��\n");
		return;
	}
	printf("��ǰԪ�أ�\n");
	for(i = ptr->stack_top; i >= 0; i--)
	{
		value = ptr->stack_arr[i];
		printf("%d ", value);
	}
	printf("\n");
}

//���Ծ�̬˳��ջ
void test_Stack_StaticArray(void)
{
	int top_value;
	StaticStackNode ptr = { {0}, -1 };//��ʼ��ջ��Ϊ-1
	//��1����ջ����
	PushStaticStack(&ptr, 1);
	PushStaticStack(&ptr, 2);
	PushStaticStack(&ptr, 3);
	PushStaticStack(&ptr, 4);
	PushStaticStack(&ptr, 5);
	//��ӡջ
	PrintStaticStack(&ptr);//5 4 3 2 1
	//��ȡջ��Ԫ��
	GetTopElement(&ptr, &top_value);//5
	//��ջ�����ջ��������
	PushStaticStack(&ptr, 6);//ջ������ջʧ��
	PrintStaticStack(&ptr);//5 4 3 2 1

	//��2����ջ����
	PopStaticStack(&ptr, &top_value);
	PopStaticStack(&ptr, &top_value);
	PopStaticStack(&ptr, &top_value);
	PopStaticStack(&ptr, &top_value);
	PopStaticStack(&ptr, &top_value);
	//��ӡ��ջ
	PrintStaticStack(&ptr);//���գ�
	//��ջ�����ջ�գ�����
	PopStaticStack(&ptr, &top_value);
	//�ٴ���ջ
	PushStaticStack(&ptr, 1);
	PushStaticStack(&ptr, 2);
	PrintStaticStack(&ptr);//2 1
	GetTopElement(&ptr, &top_value);//2
}

