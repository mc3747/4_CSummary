#include <stdio.h>
#include <stdlib.h>
/*
	ʵ������������(��ͷ���)
	--zjp
	marc07@qq.com
*/
typedef char ElemType;
/*
	�����洢��־λ
	Link(0):��ʾָ�����Һ��ӵ�ָ��
	Thread(1):��ʾָ��ǰ����̵�����
*/
typedef enum 
{
	Link, 
	Thread
}PointerTag;
/*
	���������洢���ṹ
*/
typedef struct BiThrNode 
{
	ElemType data;/* ������� */
	struct BiThrNode *lchild;/* ���Һ���ָ�� */
	struct BiThrNode *rchild;
	PointerTag ltag;/* ���ұ�־*/
	PointerTag rtag;
}BiThrTreeNode, *BiThrTree;

//ȫ�ֱ�����ʼ��ָ��ոշ��ʹ��Ľڵ�
BiThrTree pre;

//���򴴽�������
void CreateBiThrTree(BiThrTree *T)
{
	ElemType ch;
	scanf("%c", &ch);
	getchar();//��scanf�����ַ�������ʱ�������getcharȥ��'\n'�ַ�
	if ('#' == ch)
	{
		*T = NULL;
	}
	else
	{
		*T = (BiThrTreeNode *)malloc(sizeof(BiThrTreeNode));
		if (*T == NULL)
		{
			printf("CreateBiThrTree fail:malloc error\n");
			return;
		}
		(*T)->data = ch;
		(*T)->ltag = Link;
		(*T)->rtag = Link;
		printf("������%c�����ӽ�㣺\n", ch);
		CreateBiThrTree(&((*T)->lchild));
		printf("������%c�����ӽ�㣺\n", ch);
		CreateBiThrTree(&((*T)->rchild));
	}
}

/* ������������� */
void InThreading(BiThrTree T)
{
	if (T)
	{
		InThreading(T->lchild);//����������
		if (T->lchild == NULL)//�����������//if(!T->lchild)
		{
			T->ltag = Thread;
			T->lchild = pre;//���浱ǰ����ǰ��
		}
		if (pre != NULL && pre->rchild == NULL)
		{
			pre->rtag = Thread;
			pre->rchild = T;//����շ��ʹ�����һ�����ĺ��
		}
		pre = T;//����preָ�룬ʼ��ָ��ոշ��ʹ�����һ�����
		InThreading(T->rchild);//����������
	}
}

/* �����������������������ͷ��� */
BiThrTree InOrderThreading(BiThrTree T)
{
	BiThrTree	Thrt;//ThrtΪͷ���ָ��
	Thrt = (BiThrTreeNode *)malloc(sizeof(BiThrTreeNode));
	if (Thrt == NULL)
	{
		printf("InOrderThreading fail:malloc error\n");
		return;
	}
	Thrt->ltag = Link;//ͷ�����ָ������ָ��Ϊ����㣬���������־ΪLink����ʾָ������
	Thrt->rtag = Thread;//ͷ�����ָ������ָ��Ϊ���һ����㣬���������־ΪThread,��ʾָ����
	Thrt->rchild = Thrt;//��ָ���ָ
	if (T == NULL)
	{
		Thrt->lchild = Thrt;//��������Ϊ�գ�����ָ���ָ
	}
	else
	{
		Thrt->lchild = T;//ͷ�������ָ����ڵ�
		pre = Thrt;//��ʼ����һ�����ʵĽ�㣬preȫ�ֱ���
		InThreading(T);//���������������������
		pre->rtag = Thread;//���ϱ�ǣ���ָ����ָ���̣��������Һ���
		pre->rchild = Thrt;//���һ���������������ָ��ͷ���
		Thrt->rchild = pre;//ͷ�����������
	}
	return Thrt;
}

//�����������������--�ǵݹ�
void InOrderTraverse_Thr(BiThrTree Thrt)
{
	BiThrTree p = Thrt->lchild;
	while (p != Thrt)
	{
		//һֱ������
		while (p->ltag == Link)
		{
			p = p->lchild;
		}
		printf("%c ", p->data);
		//������ұ�־λΪ1ʱ��ֱ���ҵ����̽��
		while (p->rtag == Thread && p->rchild != Thrt)
		{
			p = p->rchild;
			printf("%c ", p->data);
		}
		//���򣬰�����������Ĺ��ɣ������������������µĽ�㣬Ҳ���Ǽ���ѭ������
		p = p->rchild;
	}
}

//��������������
void test_BinaryTree_Threaded(void)
{
	BiThrTree T = NULL;
	BiThrTree Thrt = NULL;//ͷ���
	printf("����ǰ������������:\n");
	CreateBiThrTree(&T);
	Thrt = InOrderThreading(T);
	printf("�����������:\n");
	InOrderTraverse_Thr(Thrt);
}





