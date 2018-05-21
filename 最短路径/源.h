#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<iostream>
using namespace std;
#include<cstring>
#include<string.h>
#define STACK_INIT_SIZE 100
#define MAX_VERTEX_NUM 50
#define STACKINCREMENT 10
typedef int SElemType;//栈内元素信息的类型
typedef int Status; //函数类型
typedef int InfoType;//弧的信息的类型
typedef char VertexType[4];//顶点的类型
typedef struct
{
	SElemType  *base;
	SElemType  *top;
	int stacksize;
}SqStack;


typedef struct ArcNode
{
	int adjvex;
	struct ArcNode *nextarc;
	InfoType *info;
}ArcNode;


typedef struct VNode
{
	VertexType data;
	ArcNode *firstarc;
}VNode, AdjList[MAX_VERTEX_NUM];


typedef struct
{
	 AdjList vertex;
	int vernum, arcnum;   //exnum,arcnum 分别为图的顶点数和边数
	int kind;
}ALGraph;


Status InitStack(SqStack S)
{
	S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base)exit(0);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return 0;
}
Status Push(SqStack S, SElemType e)
{
	if (S.top - S.base >= S.stacksize)
	{
		S.base = (SElemType *)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S.base)exit(0);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return 0;
}
Status Pop(SqStack S, SElemType e)
{
	if (S.top == S.base) exit(0);
	e = *--S.top;
	return 0;
}
