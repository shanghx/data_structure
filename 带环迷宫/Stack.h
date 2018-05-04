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
//动态顺序栈
typedef struct stack
{
	DataType *_array;
	int capacity;
	int _top;
}Stack;

void StackInit(Stack* s, int capacity);// 栈的初始化 


void StackPush(Stack* s, DataType data);// 入栈 

										
void StackPop(Stack* s);// 出栈 


DataType StackTop(Stack* s);// 获取栈顶元素 


int StackSize(Stack* s);// 获取栈中元素个数 


int StackEmpty(Stack* s);// 检测栈是否为空 

