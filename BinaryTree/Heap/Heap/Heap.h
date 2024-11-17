#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* arr;
	int size;
	int capacity;
}HP;

//��ʼ����
void InitHP(HP* php);

//���ٶ�
void DestroyHP(HP* php);

//���ϵ����㷨
void AdjustUp(HP* php, int child);

//��������
void swap(HPDataType* x, HPDataType* y);

//��������
void HPPush(HP* php, HPDataType x);

//�ж϶��Ƿ�Ϊ��
bool HPEmpty(HP* php);

//��ѵ����ݸ���
int HPSize(HP* php);

//���µ����㷨
void AdjustDown(HPDataType* arr, int parent, int n);

//�ӶѶ�ɾ������
void HPPop(HP* php);