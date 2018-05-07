#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<asssert.h>
typedef int QDataType;

typedef struct QNode 
{
	QDataType data;
	struct QNode *p_next;
	
}QNode,*PQNode;


typedef struct Queue
{
	PQNode rear;
	PQNode front;
}Queue;

void QueueInit(Queue *q);//队列初始化
void QueuePush(Queue *q,QDataType data); //入队
QDataType QueuePop(Queue *q);   //出队
int QueueEmpty(Queue *q);   //判断队列是否为空
int QueueSize(Queue *q);   //获取队的有效元素的长度
void QueueDestory(Queue *q);   //销毁队列
void QueuePrint(Queue *q);    //打印队列列元素
