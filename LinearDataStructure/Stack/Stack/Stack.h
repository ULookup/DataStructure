#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
typedef int StackDataType;
typedef struct Stack
{
	StackDataType* arr;
	int top;
	int capacity;
}ST;

//��ʼ��
void InitST(ST* ps);

//����
void DestroyST(ST* ps);

//��ջ
void StackPush(ST* ps, StackDataType x);

//ջ�Ƿ�Ϊ��
bool IsStackEmpty(ST* ps);

//��ջ
void StackPop(ST* ps);

//ȡջ��Ԫ��
StackDataType StackTop(ST* ps);

//��ȡջ����ЧԪ�ظ���
int StackSize(ST* ps);

//��ӡ
void PrintStack(ST* ps);

//����
void StackDestroy(ST* ps);