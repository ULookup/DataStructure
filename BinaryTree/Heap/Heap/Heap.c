#include "Heap.h"

//初始化堆
void InitHP(HP* php)
{
	assert(php);
	php->arr = NULL;
	php->size = php->capacity = 0;
}

//销毁堆
void DestroyHP(HP* php)
{
	if (php->arr)
		free(php->arr);
	php->arr = NULL;
	php->size = php->capacity = 0;
}

//交换位置
void swap(HPDataType* x, HPDataType* y)
{
	HPDataType tmp = *x;
	*x = *y;
	*y = tmp;
}

//向上调整算法
void AdjustUp(HPDataType* arr, int child)
{
	int parent = (child - 1) / 2;
	while (child>0)
	{
		//小堆 < ; 大堆 >
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

//插入数据
void HPPush(HP* php, HPDataType x)
{
	assert(php);
	//检查空间是否充足，否则扩容
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
	//插入数据
	php->arr[php->size] = x;
	//向上调整成有效小堆
	AdjustUp(php->arr, php->size);
	php->size++;
}

//判断堆是否为空
bool HPEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}

//求堆的数据个数
int HPSize(HP* php)
{
	assert(php);
	return php->size;
}

//向下调整算法
void AdjustDown(HPDataType* arr, int parent, int n)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		/*这里的child是左子树，child+1是右子树*/
		if (child + 1 < n && arr[child] > arr[child + 1])//小堆用 > 找到最小的子树；大堆用 < 找到最大的子树
			child++;
		if (arr[parent] > arr[child])//小堆用 > 把小的向上移动；大堆用 < 把大的向上移动
		{
			swap(&arr[parent], &arr[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

//从堆顶删除数据
void HPPop(HP* php)
{
	assert(!HPEmpty(php));

	swap(&php->arr[php->size - 1], &php->arr[0]);//先交换堆顶和堆尾的数据，若直接头删，会让堆的结构混乱
	php->size--;

	AdjustDown(php->arr, 0, php->size);
}