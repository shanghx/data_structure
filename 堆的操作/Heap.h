#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;
typedef int(*Compare)(int left, int right);

typedef struct Heap
{
	DataType *array;     //堆的地址
	int capacity;          //堆的容量
	int _size;              //堆中有效元素的个数
	Compare com;
}Heap;

typedef int(*Compare)(int left, int right);

void InitHeap(Heap *hp);     //堆的初始化
void CreatHeap(Heap *hp, DataType *array, int size, Compare com);   //创建堆
void InsertHeap(Heap *hp, DataType data);            //插入元素
void DeleteHeap(Heap *hp);                           //删除堆顶元素
	
DataType GetHeapTop(Heap *hp);         //获取堆中的堆顶元素	
int CountHeap(Heap *hp);       //获取堆的总元素个数
int EmptyHeap(Heap *hp);            //判断堆是否为空
void DestoryHeap(Heap *hp);  //销毁堆

							 // 用于元素比较的比较器 
int Greater(DataType left, DataType right);

int Less(DataType left, DataType right);
