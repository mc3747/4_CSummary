#include <stdio.h>
#include <stdlib.h>

/*
	ʵ�ִ�-KMP�㷨
	--zjp
	marc07@qq.com
	KMP�㷨Ϊ�ַ���ƥ���㷨
*/

//ģʽ������������ƥ��һ�Σ����next����
void get_next(char *T, int *next)
{
	int i, j;
	i = 1;
	j = 0;
	next[1] = 0;
	while (i < T[0])//�˴�T[0]��ʾģʽ��T�ĳ���
	{
		if (j == 0 || T[i] == T[j])//T[i]��ʾ��׺�ĵ����ַ���T[j]��ʾǰ׺�ĵ����ַ�
		{
			i++;
			j++;
			next[i] = j;
		}
		else
		{
			j = next[j];//����ǰ�ַ�����ͬ����j����
		}
	}
}

//�����Ӵ�T������S�е�pos���ַ�֮���λ�ã��������ڣ���������ֵΪ0
int KMP(char *S, char *T, int pos)
{
	int i = pos;
	int j = 1;
	int next[255];
	get_next(T, next);//��ȡnext����
	while (i <= S[0] && j <= T[0])
	{
		if (j == 0 || S[i] == T[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];//j����
		}
	}
	//���ؽ��
	if (j > T[0])
	{
		return i - T[0];
	}
	else
	{
		return 0;
	}
}

void test_String_KMP(void)
{
	int res = -1;
	char S[20], T[10];
	S[0] = 10;//��Ԫ��Ϊ�ַ���������
	T[0] = 5;//��Ԫ��Ϊģʽ��������
	memcpy((char *)(S + 1), "abcabcee", 9);//�����ַ�������
	memcpy((char *)(T + 1), "abcee", 6);//����ģʽ������ƥ�䴮��
	res = KMP(S, T, 1);//KMP�㷨ƥ��
	printf("res = %d\n", res);//res = 4
}

