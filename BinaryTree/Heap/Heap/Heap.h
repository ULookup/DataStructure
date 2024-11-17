#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* arr;
	int size;
	int capacity;
}HP;

//初始化堆
void InitHP(HP* php);

//销毁堆
void DestroyHP(HP* php);

//向上调整算法
void AdjustUp(HP* php, int child);

//交换数据
void swap(HPDataType* x, HPDataType* y);

//插入数据
void HPPush(HP* php, HPDataType x);

//判断堆是否为空
bool HPEmpty(HP* php);

//求堆的数据个数
int HPSize(HP* php);

//向下调整算法
void AdjustDown(HPDataType* arr, int parent, int n);

//从堆顶删除数据
void HPPop(HP* php);