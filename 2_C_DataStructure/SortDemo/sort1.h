#pragma once
#include<stdio.h>
#include<stdlib.h>
//Ϊ��ͳһ��һ·���մ�С��������
void BubbleSort(int arr[], int n);	//ð������	�����������Ƚϣ�������������ŵ�����λ��
void SelectSort(int arr[], int n);	//ѡ������	ÿһ����׼һ��λ�ã�ͨ�����λ�õ�ֵȥ�ͺ������е�ֵȥ���Ƚϣ���������������ֵ�������λ��
void InsertSort(int arr[], int n);	//��������	��һ������һ��������������������
void QuickSort(int arr[], int left, int right);//��������
void ShellSort(int arr[], int n);	//ϣ������
void MergeSort(int arr[], int left, int right);//�鲢����
void _merge_in_arr(int arr[], int left, int mid, int right);//�鲢�������������ϲ���
void radix_sort(int arr[], size_t len);	//Ͱ����

void show(int arr[], int n);			//��ʾ����
void swap(int arr[], int x, int y);
