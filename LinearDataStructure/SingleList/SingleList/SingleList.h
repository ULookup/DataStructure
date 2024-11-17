#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLTDatatype;
typedef struct SListNode
{ 
	SLTDatatype data;
	struct SListNode* next;
}SLTNode;


//��ӡ����
void SLTPrint(SLTNode* phead);
//������
SLTNode* SLTBuyNode(SLTDatatype x);
//β��
void SLTPushBack(SLTNode** pphead,SLTDatatype x);
//ͷ��
void SLTPushFront(SLTNode** pphead, SLTDatatype x);
//βɾ
void SLTPopBack(SLTNode** pphead);
//ͷɾ
void SLTPopFront(SLTNode** pphead);
//����
SLTNode* SLTFind(SLTNode* phead, SLTDatatype x);
//ָ��λ��ǰ����
void SLTInsertBefore(SLTNode** pphead, SLTNode* pos, SLTDatatype x);
//ָ��λ�ú����
void SLTInsertAfter(SLTNode** pphead, SLTNode* pos, SLTDatatype x);
//ɾ��pos���
void SLTErase(SLTNode** pphead, SLTNode* pos);
//ɾ��pos֮��Ľ��
void SLTEraseAfter(SLTNode** pphead, SLTNode* pos);
//��������
void SLTDestroy(SLTNode** pphead);