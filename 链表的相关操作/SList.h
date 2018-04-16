#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int DataType;
typedef struct SList
{
	DataType data;
	struct SList *p_next;

}SList,*PNode;

void SListInit(PNode* pHead);// 链表的初始化 

void SListPushBack(PNode* pHead, DataType data);// 尾插

void SListPopBack(PNode* pHead);// 尾删 

void SListPushFront(PNode* pHead, DataType data);// 头插 

void SListPopFront(PNode* pHead);// 头删 

PNode SListFind(PNode pHead, DataType data);// 在链表中查找值为data的元素，找到后返回值为data的结点
 
void SListInsert(PNode* pHead, PNode pos, DataType data);// 在pos位置插入值为data的结点

void SListErase(PNode* pHead, PNode pos);// 删除pos位置的结点 

int SListSize(PNode pHead);// 获取链表的长度 

int SListEmpty(PNode pHead);// 判断链表是否为空 

void SListDestroy(PNode* pHead);// 销毁聊表 

void PrintSList(PNode pHead);//打印链表的值
