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

void QueueInit(Queue *q);//���г�ʼ��
void QueuePush(Queue *q,QDataType data); //���
QDataType QueuePop(Queue *q);   //����
int QueueEmpty(Queue *q);   //�ж϶����Ƿ�Ϊ��
int QueueSize(Queue *q);   //��ȡ�ӵ���ЧԪ�صĳ���
void QueueDestory(Queue *q);   //���ٶ���
void QueuePrint(Queue *q);    //��ӡ������Ԫ��
