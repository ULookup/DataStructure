#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
typedef int SLDataType;
typedef struct Seqlist
{
	int size;//��Ч��С
	int capacity;//����
	SLDataType* arr;//��̬˳���
}SL;
void InitSL(SL* s);//��ʼ��˳���

void CheckCapacity(SL* ps);//�������������

void SLInsertBack(SL* ps, SLDataType x);//β��

void SLInsertFront(SL* ps, SLDataType x);//ͷ��

void SLPopback(SL* ps);//βɾ

void SLPopFront(SL* ps);//ͷɾ

void SLPrint(SL* ps);//��ӡ

void SLInsert(SL* ps, int pos,SLDataType x);//ָ��λ��ǰ����

void SLErase(SL* ps, int pos);//ɾ��ָ��λ�õ�����

void SLDestroy(SL* ps);//����˳���