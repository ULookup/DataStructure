#include <stdio.h>
#include <stdlib.h>
void swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
void AdjustDown(int* arr, int parent,int n)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && arr[child] < arr[child + 1])
			child++;
		if (arr[parent] < arr[child])
		{
			swap(&arr[parent], &arr[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
void AdjustUp(int* arr, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (arr[parent] < arr[child])
		{
			swap(&arr[parent], &arr[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}
void Heapsort(int* arr, int n)
{
	//�����򣬶�Ҫ��������ݽ����
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(arr,i,n);
	}//���µ����㷨���ѣ�ʱ�临�Ӷȸ�С
	
	 /*for (int i = 0; i < n; i++)
	{
		AdjustUp(arr, i);
	}���ϵ����㷨���ѣ�ʱ�临�Ӷȸ���*/

	//������
	int end = n - 1;
	while (end > 0)
	{
		swap(&arr[0], &arr[end]);
		AdjustDown(arr,0,end);
		end--;
	}
}
int main()
{
	int arr[10] = { 98,42,15,75,41,34,66,78,13,22 };
	int n = sizeof(arr) / sizeof(arr[0]);
	Heapsort(arr, n);
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	return 0;
}