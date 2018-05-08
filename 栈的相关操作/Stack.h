#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//1. 实现栈的接口，注意：上课我们实现的是静态栈，缺陷是栈中元素收空间大小的限制，优点：实现简单
//大家需要实现动态栈，即栈中元素存满时需要自动增容

typedef int DataType;
#define MAX_SIZE 100 

typedef struct Stack
{
	DataType *_array;
	int capacity;
	int _top;
}Stack;


void StackInit(Stack* s,int capacity);// 栈的初始化 


void StackPush(Stack* s, DataType data);// 入栈 

// 出栈 
void StackPop(Stack* s);

// 获取栈顶元素 
DataType StackTop(Stack* s);

// 获取栈中元素个数 
int StackSize(Stack* s);

// 检测栈是否为空 
int StackEmpty(Stack* s);

