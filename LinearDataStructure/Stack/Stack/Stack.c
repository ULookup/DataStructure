#include "Stack.h"

//��ʼ��
void InitST(ST* ps)
{
	assert(ps);

	ps->arr = NULL;
	ps->top = 0;
	ps->capacity = 0;
}
//����
void DestroyST(ST* ps)
{
	assert(ps);

	if (ps->arr != NULL)
		free(ps->arr);
	ps->arr = NULL;
	ps->top = ps->capacity = 0;
}
//��ջ
void StackPush(ST* ps, StackDataType x)
{
	assert(ps);

	if (ps->top == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		StackDataType* tmp = (StackDataType*)realloc(ps->arr, sizeof(StackDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail!\n");
			exit(1);
		}
		ps->arr = tmp;
		ps->capacity = newcapacity;
	}
	ps->arr[ps->top] = x;
	ps->top++;
}
//ջ�Ƿ�Ϊ��
bool IsStackEmpty(ST* ps)
{
	assert(ps);

	return ps->top == 0;
}
//��ջ
void StackPop(ST* ps)
{
 	assert(ps&&(!IsStackEmpty(ps)));

	ps->top--;
}
//ȡջ��Ԫ��
StackDataType StackTop(ST* ps)
{
	assert(ps && (!IsStackEmpty(ps)));

	return ps->arr[ps->top - 1];
}
//��ȡջ����ЧԪ�ظ���
int StackSize(ST* ps)
{
	assert(ps);

	return ps->top;
}
//��ӡ
void PrintStack(ST* ps)
{
	assert(ps);

	for (int i = 0; i < ps->top; i++)
	{
		printf("%3d", ps->arr[i]);
	}
	printf("\n");
}
//����
void StackDestroy(ST* ps)
{
	if (ps->arr != NULL)
		free(ps->arr);
	ps->arr = NULL;
	ps->top = ps->capacity = 0;
}