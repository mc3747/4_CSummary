#include <stdio.h>
/*
	ʵ�־�̬����ѭ������
	--zjp
	marc07@qq.com
*/

#define QUEUE_SIZE	5
int queue[QUEUE_SIZE];
int head = 0;
int tail = 0;

//�����
void EnQueue(int value)
{
	if (isQueueFull())
	{
		printf("�����������޷��Ӷ�β����Ԫ��\n");
	}
	else
	{
		queue[tail] = value;
		tail = (tail + 1) % QUEUE_SIZE;
	}
}

//������
int DeQueue(void)
{
	int temp;
	if (isQueueEmpty())
	{
		printf("����Ϊ�գ�Ԫ���޷�������\n");
		return -1;
	}
	else
	{
		temp = queue[head];
		head = (head + 1) % QUEUE_SIZE;
	}
	printf("delete %d\n", temp);
	return temp;
}

//�ж϶����Ƿ�Ϊ��
int isQueueEmpty(void)
{
	if (head == tail)
	{
		return 1;//����Ϊ��
	}
	else
	{
		return 0;//���зǿ�
	}
}

//�ж϶����Ƿ�����
/*
*  �����ж϶����ĵķ�����
����һ����Ԫ�����ֶӿպͶ��������ʱ����һ�����е�Ԫ���������Ĵ�СΪSize,��ôʵ��ֻ�ܴ��(Size-1)��Ԫ�ء������ǱȽϳ��õ������ķ�ʽ��
*
*/
int isQueueFull(void)
{
	if ((tail + 1) % QUEUE_SIZE == head)
	{
		return 1;//����Ϊ��
	}
	else
	{
		return 0;//���з���
	}
}

//��ӡ������Ԫ��
void PrintQueue(void)
{
	int i = head;
	while(i != tail)
	{
		printf("%d ", queue[i]);
		i = (i + 1) % QUEUE_SIZE;
	}
	printf("\n");
}

//��̬����ѭ�����в���
void test_Queue_Array(void)
{
	EnQueue(10);
	EnQueue(20);
	EnQueue(30);
	EnQueue(40);
	PrintQueue();//10 20 30 40
	EnQueue(50);//"�����������޷��Ӷ�β����Ԫ��"
	PrintQueue();//10 20 30 40
	DeQueue();//delete 10
	PrintQueue();//20 30 40
	EnQueue(50);
	PrintQueue();//20 30 40 50
	DeQueue();//delete 20
	DeQueue();//delete 30
	DeQueue();//delete 40
	DeQueue();//delete 50
	DeQueue();//"����Ϊ�գ�Ԫ���޷�������"
}
