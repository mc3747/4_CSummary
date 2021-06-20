#include <stdio.h>
#include <string.h>
/*
	ʵ�ֶ�̬�ڴ�ѭ������(�����Զ��������ڱ�ʶ�ļ�����)
	--zjp
	marc07@qq.com
*/
typedef enum
{
	ERROR = 0,
	OK = 1,
	TRUE = 2,
	FALSE = 3
}STATUS;

typedef struct
{
	int *pBase;
	int front;
	int rear;
	int maxSize;
}queue;

//��������
STATUS initQueue(queue *pQueue, int queueCapacity)
{
	pQueue->pBase = (int *)malloc(queueCapacity * sizeof(int));
	if (pQueue->pBase == NULL)
	{
		printf("initQueue fail:malloc error\n");
		return ERROR;
	}
	pQueue->front = 0;
	pQueue->rear = 0;
	pQueue->maxSize = queueCapacity;
	return OK;
}

//���ٶ���
void destroyQueue(queue *pQueue)
{
	free(pQueue);
	pQueue = NULL;//�����ΪҰָ��
}

//��ն���
void clearQueue(queue *pQueue)
{
	pQueue->front = 0;
	pQueue->rear = 0;
}

//�ж϶����Ƿ�Ϊ��
STATUS isEmptyQueue(queue *pQueue)
{
	if (pQueue->front == pQueue->rear)
	{
		return TRUE;
	}
	return FALSE;
}

//�ж϶����Ƿ�Ϊ��
STATUS isFullQueue(queue *pQueue)
{
	if ((pQueue->rear + 1) % pQueue->maxSize == pQueue->front)
	{
		return TRUE;
	}
	return FALSE;
}

//��ȡ���г���
int getQueueLen(queue *pQueue)
{
	return (pQueue->rear - pQueue->front + pQueue->maxSize) % pQueue->maxSize;
}

//��Ԫ�����
STATUS enQueue(queue *pQueue, int element)
{
	if (isFullQueue(pQueue) == TRUE)
	{
		printf("�������������ʧ��\n");
		return ERROR;
	}
	pQueue->pBase[pQueue->rear] = element;
	pQueue->rear = (pQueue->rear + 1) % pQueue->maxSize;
	return OK;
}

//Ԫ�س���
STATUS deQueue(queue *pQueue, int *pElement)
{
	if (isEmptyQueue(pQueue) == TRUE)
	{
		printf("����Ϊ�գ�����ʧ��\n");
		return ERROR;
	}
	*pElement = pQueue->pBase[pQueue->front];
	pQueue->front = (pQueue->front + 1) % pQueue->maxSize;
	return OK;
}

//��������
void printQueue(queue *pQueue)
{
	int temp = pQueue->front;//�˴�������ֱ�Ӳ���pQueue->front������Ӱ��ԭ��ֵ��Ӧ�þֲ��������
	while (temp != pQueue->rear)
	{
		printf("%d ", pQueue->pBase[temp]);
		temp = (temp + 1) % pQueue->maxSize;
	}
	printf("\n");
}

void test_Queue_Malloc(void)
{
	int temp = 0;
	int value = 0;
	queue *pQueue;
	pQueue = (queue *)malloc(sizeof(queue));
	if (pQueue == NULL)
	{
		printf("queue malloc error\n");
		return;
	}
	//��ʼ�����У�Ԫ������Ϊ5
	initQueue(pQueue, 5);
	//Ԫ�����
	enQueue(pQueue, 1);
	enQueue(pQueue, 2);
	enQueue(pQueue, 3);
	enQueue(pQueue, 4);
	printQueue(pQueue);//1 2 3 4
	enQueue(pQueue, 5);//�������������ʧ��
	printQueue(pQueue);//1 2 3 4
	temp = getQueueLen(pQueue);
	printf("getqueuelen = %d\n", temp);//getqueuelen = 4
	//����һ��Ԫ�أ��ó���λ��
	deQueue(pQueue, &value);
	printf("delete %d\n", value);//delete 1
	printQueue(pQueue);//2 3 4
	temp = getQueueLen(pQueue);
	printf("getqueuelen = %d\n", temp);//getqueuelen = 3
	//����һ��Ԫ�غ󣬿�λ�ò���һ����Ԫ��
	enQueue(pQueue, 5);
	printQueue(pQueue);// 2 3 4 5 
	temp = getQueueLen(pQueue);
	printf("getqueuelen = %d\n", temp);//getqueuelen = 4

	//��ն��У����²���Ԫ��
	clearQueue(pQueue);
	enQueue(pQueue, 10);
	enQueue(pQueue, 20);
	enQueue(pQueue, 30);
	enQueue(pQueue, 40);
	printQueue(pQueue);//10 20 30 40
	temp = getQueueLen(pQueue);
	printf("getqueuelen = %d\n", temp);//getqueuelen = 4

	//���ٶ���
	destroyQueue(pQueue);
}