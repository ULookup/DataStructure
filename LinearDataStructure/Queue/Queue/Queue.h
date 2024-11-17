#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
typedef int QEDataType;
typedef struct QueueNode
{
	QEDataType data;
	struct QueueNode* next;

}QueueNode;
typedef struct Queue
{
	QueueNode* phead;
	QueueNode* ptail;
	int size;
}Queue;
//��ʼ������
void InitQueue(Queue* pq);
//�����½��
QueueNode* QueueBuyNode();
//�����п�
bool IsQueueEmpty(Queue* pq);
//���
void QueuePush(Queue* pq, QEDataType x);
//������
void QueuePop(Queue* pq);
//ȡ��ͷ����
QEDataType QueueHead(Queue* pq);
//ȡ��β����
QEDataType QueueTail(Queue* pq);
//���ٶ���
void DestroyQueue(Queue* pq);
//��ӡ����
void PrintQueue(Queue* pq);
//��ЧԪ�ظ���
int QueueSize(Queue* pq);