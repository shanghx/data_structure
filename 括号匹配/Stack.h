#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//1. ʵ��ջ�Ľӿڣ�ע�⣺�Ͽ�����ʵ�ֵ��Ǿ�̬ջ��ȱ����ջ��Ԫ���տռ��С�����ƣ��ŵ㣺ʵ�ּ�
//�����Ҫʵ�ֶ�̬ջ����ջ��Ԫ�ش���ʱ��Ҫ�Զ�����

typedef int DataType;
#define MAX_SIZE 100 

typedef struct Stack
{
	DataType *_array;
	int capacity;
	int _top;
}Stack;


void StackInit(Stack* s,int capacity);// ջ�ĳ�ʼ�� 


void StackPush(Stack* s, DataType data);// ��ջ 

// ��ջ 
void StackPop(Stack* s);

// ��ȡջ��Ԫ�� 
DataType StackTop(Stack* s);

// ��ȡջ��Ԫ�ظ��� 
int StackSize(Stack* s);

// ���ջ�Ƿ�Ϊ�� 
int StackEmpty(Stack* s);

