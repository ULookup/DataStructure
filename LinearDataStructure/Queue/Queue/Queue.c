#include "Queue.h"
//��ʼ������
void InitQueue(Queue* pq)
{
	assert(pq);

	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}
//�����½��
QueueNode* QueueBuyNode()
{
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	return newnode;
}
//�����п�
bool IsQueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->phead == NULL;
}
//�����
void QueuePush(Queue* pq, QEDataType x)
{
	assert(pq);
	QueueNode* newnode = QueueBuyNode();
	if (newnode == NULL)
	{
		perror("malloc fail!\n");
		exit(1);
	}
	newnode->next = NULL;
	newnode->data = x;

	if (IsQueueEmpty(pq))
	{
		pq->phead = pq->ptail = newnode;
	}
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = pq->ptail->next;
	}
	pq->size++;
}
//������
void QueuePop(Queue* pq)
{
	assert(pq&&(!IsQueueEmpty(pq)));

	if (pq->phead == pq->ptail)
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	else
	{
		QueueNode* next = pq->phead->next;
		free(pq->phead);
		pq->phead = next;
	}
	pq->size--;
}
//ȡ��ͷ����
QEDataType QueueHead(Queue* pq)
{
	assert(pq && (!IsQueueEmpty(pq)));

	return pq->phead->data;
}
//ȡ��β����
QEDataType QueueTail(Queue* pq)
{
	assert(pq && (!IsQueueEmpty(pq)));

	return pq->ptail->data;
}
//��ЧԪ�ظ���
int QueueSize(Queue* pq)
{
	assert(pq);

	return pq->size;
}
//���ٶ���
void DestroyQueue(Queue* pq)
{
	assert(pq);
	QueueNode* pcur = pq->phead;
	while (pcur)
	{
		QueueNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}
//��ӡ����
void PrintQueue(Queue* pq)
{
	assert(pq && (!IsQueueEmpty(pq)));

	QueueNode* pcur = pq->phead;
	while (pcur)
	{
		printf("%d", pcur->data);
		pcur = pcur->next;
	}
	printf("\n");
}