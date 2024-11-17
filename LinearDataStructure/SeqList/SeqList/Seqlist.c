#include "Seqlist.h"
//��ʼ��˳���
void InitSL(SL* ps)
{
	ps->arr = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

//������޿ռ�
void CheckCapacity(SL* ps)
{
	assert(ps);
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* Tmp = (SLDataType*)realloc(ps->arr, newcapacity*sizeof(SLDataType));
		if (Tmp == NULL)
		{
			printf("realloc fail");
			exit(1);
		}
		ps->arr = Tmp;
		ps->capacity = newcapacity;
	}
}

//β��
void SLInsertBack(SL* ps,SLDataType x)
{
	assert(ps);
	CheckCapacity(ps);
	ps->arr[ps->size] = x;
	ps->size++;
}

//ͷ��
void SLInsertFront(SL* ps, SLDataType x)
{
	assert(ps);
	CheckCapacity(ps);
	ps->size++;
	for(int i=ps->size-1;i>0;i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[0] = x;
}

//βɾ
void SLPopback(SL* ps)
{
	assert(ps && ps->size);
	ps->size--;
}

//ͷɾ
void SLPopFront(SL* ps)
{
	assert(ps && ps->size);
	for (int i = 0; i < ps->size-1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}

//��ӡ
void SLPrint(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}

//����(�ҵ��򷵻��±꣬δ�ҵ��򷵻���Ч�±�)
//ע:ֻ���ҵ�һ�γ��ֵ�
void SLFind(SL* ps, SLDataType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->arr[i] == x)
			return i;
	}
	return -1;
}

//ָ��λ��ǰ����
void SLInsert(SL* ps, int pos,SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	CheckCapacity(ps);
	ps->size++;
	for (int i = ps->size - 1; i > pos; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[pos] = x;
}

//ɾ��ָ��λ�õ�����
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	for (int i = pos; i < ps->size-1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}

//����˳���
void SLDestroy(SL* ps)
{
	if (ps->arr)
		free(ps->arr);
	ps->arr = NULL;
	ps->capacity = 0;
	ps->size = 0;
}