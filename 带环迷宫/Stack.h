#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct position
{
	int _x;
	int _y;
}Position;
typedef Position  DataType;
//��̬˳��ջ
typedef struct stack
{
	DataType *_array;
	int capacity;
	int _top;
}Stack;

void StackInit(Stack* s, int capacity);// ջ�ĳ�ʼ�� 


void StackPush(Stack* s, DataType data);// ��ջ 

										
void StackPop(Stack* s);// ��ջ 


DataType StackTop(Stack* s);// ��ȡջ��Ԫ�� 


int StackSize(Stack* s);// ��ȡջ��Ԫ�ظ��� 


int StackEmpty(Stack* s);// ���ջ�Ƿ�Ϊ�� 

