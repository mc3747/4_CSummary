#include <stdio.h>
#include <stdlib.h>

/*
	ʵ��ɢ�б���ң���ϣ����ң��㷨
	--zjp
	marc07@qq.com
*/

#define HASHSIZE	12
#define NULLKEY		-32768
typedef struct
{
	int elem[HASHSIZE];
}HashTable;

//��ʼ��ɢ�б�
void InitHashTable(HashTable *H)
{
	for(int i = 0; i < HASHSIZE; i++)
	{
		H->elem[i] = NULLKEY;
	}
}

//ɢ�к���
int Hash(int key)
{
	return key  % HASHSIZE;//����������
}

//����ؼ��ֵ�ɢ�б�
void InsertHash(HashTable *H, int key)
{
	int addr = Hash(key);//��ȡ��Ӧ��ɢ�е�ַ
	while (H->elem[addr] != NULLKEY)//����Ϊ��ֵ����˵���ÿռ�λ���Ѵ��Ԫ�أ��г�ͻ
	{
		addr = (addr + 1) % HASHSIZE;//���Ŷ�ַ��������̽�⣬�˴�Ҳ�ɸ���Ϊ���������ͻ�ķ���
	}
	H->elem[addr] = key;//ֱ���п�λ�����ؼ���
}

//ɢ�б���ҹؼ���
int SearchHash(HashTable *H, int key)
{
	int addr = Hash(key);//��ȡ��Ӧ��ɢ�е�ַ
	while (H->elem[addr] != key)//������ȣ�˵���ÿռ�λ���Ѵ������Ԫ��
	{
		addr = (addr + 1) % HASHSIZE;//���Ŷ�ַ��������̽��
		if (H->elem[addr] == NULLKEY || addr == Hash(key))//��һ��λ��û�д�ţ�����ѭ���ص�ԭ��
		{
			printf("Key %d isn't in HashTable.\n", key);
			return -1;
		}
	}
	printf("\nKey %d addr is %d\n", key, addr);
	return 1;
}

void test_HashSearch(void)
{
	HashTable H;
	int arr[HASHSIZE] = { 12, 67, 56, 16, 25, 37, 22, 29, 15, 47, 48, 34 };//ģ������
	//1.��ʼ��ɢ�б�
	InitHashTable(&H);

	//2.����ؼ��ֵ�ɢ�б�
	for (int i = 0; i < HASHSIZE; i++)
	{
		InsertHash(&H, arr[i]);
	}
	for (int i = 0; i < HASHSIZE; i++)
	{
		printf("%d ", H.elem[i]);//��ʾ������
	}//12 25 37 15 16 29 48 67 56 34 22 47

	//3.ɢ�б���ҹؼ���
	SearchHash(&H, 67);
	SearchHash(&H, 60);
}


