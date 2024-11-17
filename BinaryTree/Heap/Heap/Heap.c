#include "Heap.h"

//��ʼ����
void InitHP(HP* php)
{
	assert(php);
	php->arr = NULL;
	php->size = php->capacity = 0;
}

//���ٶ�
void DestroyHP(HP* php)
{
	if (php->arr)
		free(php->arr);
	php->arr = NULL;
	php->size = php->capacity = 0;
}

//����λ��
void swap(HPDataType* x, HPDataType* y)
{
	HPDataType tmp = *x;
	*x = *y;
	*y = tmp;
}

//���ϵ����㷨
void AdjustUp(HPDataType* arr, int child)
{
	int parent = (child - 1) / 2;
	while (child>0)
	{
		//С�� < ; ��� >
		if (arr[child] < arr[parent])
		{
			swap(&arr[child], &arr[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}

//��������
void HPPush(HP* php, HPDataType x)
{
	assert(php);
	//���ռ��Ƿ���㣬��������
	if (php->size == php->capacity)
	{
		int newcapacity = php->capacity == 0 ? 4 : 2 * php->capacity;
		HPDataType* tmp = (HPDataType*)realloc(php->arr, sizeof(HPDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail!\n");
			exit(1);
		}
		php->arr = tmp;
		php->capacity = newcapacity;
	}
	//��������
	php->arr[php->size] = x;
	//���ϵ�������ЧС��
	AdjustUp(php->arr, php->size);
	php->size++;
}

//�ж϶��Ƿ�Ϊ��
bool HPEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}

//��ѵ����ݸ���
int HPSize(HP* php)
{
	assert(php);
	return php->size;
}

//���µ����㷨
void AdjustDown(HPDataType* arr, int parent, int n)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		/*�����child����������child+1��������*/
		if (child + 1 < n && arr[child] > arr[child + 1])//С���� > �ҵ���С������������� < �ҵ���������
			child++;
		if (arr[parent] > arr[child])//С���� > ��С�������ƶ�������� < �Ѵ�������ƶ�
		{
			swap(&arr[parent], &arr[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

//�ӶѶ�ɾ������
void HPPop(HP* php)
{
	assert(!HPEmpty(php));

	swap(&php->arr[php->size - 1], &php->arr[0]);//�Ƚ����Ѷ��Ͷ�β�����ݣ���ֱ��ͷɾ�����öѵĽṹ����
	php->size--;

	AdjustDown(php->arr, 0, php->size);
}