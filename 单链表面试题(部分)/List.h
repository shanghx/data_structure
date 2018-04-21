#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int DataType;

typedef struct node
{
	DataType data;
	struct node *p_next;
}Node ,*PNode;

void PrintSListFromTail2Head(PNode pHead);// 逆序打印单链表 

void DeleteListNotTailNode(PNode pos);// 删除链表的非尾结点，要求：不能遍历链表 

void InesrtPosFront(PNode pos, DataType data);// 在链表pos位置前插入值到data的结点 

PNode FindMiddleNode(PNode pHead);// 查找链表的中间结点，要求只能遍历一次链表 

PNode FindLastKNode(PNode pHead, int K);// 查找链表的倒数第K个结点，要求只能遍历一次链表 

void DeleteLastKNode(PNode pHead, int K);// 删除链表的倒数第K个结点，要求只能遍历一次链表 

void JosephCircle(PNode* pHead, const int M);// 用单链表实现约瑟夫环 

void ReverseSList(PNode* pHead);// 链表的逆置--三个指针 

void ReverseSListOP(PNode *pHead);// 链表的逆置--头插法 

void BubbleSort(PNode pHead);// 用冒泡排序思想对单链表进行排序 

PNode MergeSList(PNode pHead1, PNode pHead2);// 合并两个有序单链表，合并后依然有序 

int IsSListCross(PNode pHead1, PNode pHead2);// 判断两个单链表是否相交---链表不带环 

PNode GetCorssNode(PNode pHead1, PNode pHead2);// 求两个单链表相交的交点---链表不带环