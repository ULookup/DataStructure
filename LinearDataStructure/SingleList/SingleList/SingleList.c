#include "SingleList.h"
//��ӡ����
void SLTPrint(SLTNode* phead)
{
	SLTNode* pcur = phead;
	while (pcur!=NULL)
	{
		printf("%d -> ", pcur->data);
		pcur = pcur->next;
	}
	printf("NULL\n");
}
//�����½��
SLTNode* SLTBuyNode(SLTDatatype x)
{
	SLTNode* node = (SLTNode*)malloc(sizeof(SLTNode));
	if (node == NULL)
	{
		printf("malloc fail!\n");
		exit(1);
	}
	node->data = x;
	node->next = NULL;

	return node;
}
//β��
void SLTPushBack(SLTNode** pphead, SLTDatatype x)
{
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x);//����Ҫβ��Ľ��
	if (*pphead == NULL)
		*pphead = newnode;//����ǿ�����ֱ�ӳ�Ϊͷ�ڵ�
	else
	{
		SLTNode* ptail = *pphead;
		while (ptail->next != NULL)
		{
			ptail = ptail->next;//������ǿս�㣬����������ҵ�β���
		}
		ptail->next = newnode;//β������½������
	}
}
//ͷ��
void SLTPushFront(SLTNode** pphead, SLTDatatype x)
{
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x);//����Ҫͷ��Ľ��
	newnode->next = *pphead;//������ԭ����ͷ�ڵ�����
	*pphead = newnode;//��ͷ����Ϊͷ��Ľ��
}
//βɾ
void SLTPopBack(SLTNode** pphead)
{
	assert(pphead&&*pphead);//*pphead����ȷ�����ǿ�����
	if ((*pphead)->next == NULL)//ֻ��һ���������
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* prev = *pphead;
		SLTNode* ptail = *pphead;
		while (ptail->next != NULL)
		{
			prev = ptail;
			ptail =ptail->next;//prev���ɾ���β��㣬ptail���Ҫβɾ�Ľ��
		}
		prev->next = NULL;
		free(ptail);
		ptail = NULL;
	}
}
//ͷɾ
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead && *pphead);//*pphead����ȷ�����ǿ�����

	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
	//���ֻ��һ��ͷ��㣬��next������NULL��һ�����Ը���*pphead
}
//����(ֻ�ܲ��ҵ���һ�γ��ֵģ�
SLTNode* SLTFind(SLTNode* phead,SLTDatatype x)
{
	assert(phead);
	
	SLTNode* pcur = phead;
	while (pcur->next != NULL)
	{
		if (pcur->data == x)
			return pcur;
		pcur = pcur->next;
	}
	return NULL;//δ�ҵ�
}
//ָ��λ��ǰ����
void SLTInsertBefore(SLTNode** pphead, SLTNode* pos, SLTDatatype x)
{
	assert(pphead&&pos);

	if (*pphead == pos)
		SLTPushFront(pphead,x);//ָ��λ��Ϊ�׽�㣬�൱��ͷ��
	else
	{
		SLTNode* newnode = SLTBuyNode(x);
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;//�ҵ�posǰ�Ľ��
		}
		prev->next = newnode;//ǰһ�������½��
		newnode->next = pos;//�½������pos���
	}
}
//ָ��λ�ú����
void SLTInsertAfter(SLTNode** pphead, SLTNode* pos, SLTDatatype x)
{
	assert(pphead&&pos);

	SLTNode* newnode = SLTBuyNode(x);
	newnode->next = pos->next;//�½������pos������һ����㣨���pos��β��㣬ͬ��������NULL��
	pos->next = newnode;//pos��������������½��
}
//ɾ��pos���
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead && pos);

	if (*pphead == pos)
		SLTPopFront(pphead);
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}
//ɾ��pos֮��Ľ��
void SLTEraseAfter(SLTNode** pphead,SLTNode* pos)
{
	assert(pphead && pos && pos->next);

	SLTNode* del = pos->next;
	pos->next = del->next;
	free(del);
	del = NULL;
}
//��������
void SLTDestroy(SLTNode** pphead)
{
	SLTNode* pcur = *pphead;
	while (pcur != NULL)
	{
		SLTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	*pphead = NULL;
}