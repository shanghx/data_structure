#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;
typedef int(*Compare)(int left, int right);

typedef struct Heap
{
	DataType *array;     //�ѵĵ�ַ
	int capacity;          //�ѵ�����
	int _size;              //������ЧԪ�صĸ���
	Compare com;
}Heap;

typedef int(*Compare)(int left, int right);

void InitHeap(Heap *hp);     //�ѵĳ�ʼ��
void CreatHeap(Heap *hp, DataType *array, int size, Compare com);   //������
void InsertHeap(Heap *hp, DataType data);            //����Ԫ��
void DeleteHeap(Heap *hp);                           //ɾ���Ѷ�Ԫ��
	
DataType GetHeapTop(Heap *hp);         //��ȡ���еĶѶ�Ԫ��	
int CountHeap(Heap *hp);       //��ȡ�ѵ���Ԫ�ظ���
int EmptyHeap(Heap *hp);            //�ж϶��Ƿ�Ϊ��
void DestoryHeap(Heap *hp);  //���ٶ�

							 // ����Ԫ�رȽϵıȽ��� 
int Greater(DataType left, DataType right);

int Less(DataType left, DataType right);
