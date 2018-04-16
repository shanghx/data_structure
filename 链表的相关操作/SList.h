#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int DataType;
typedef struct SList
{
	DataType data;
	struct SList *p_next;

}SList,*PNode;

void SListInit(PNode* pHead);// ����ĳ�ʼ�� 

void SListPushBack(PNode* pHead, DataType data);// β��

void SListPopBack(PNode* pHead);// βɾ 

void SListPushFront(PNode* pHead, DataType data);// ͷ�� 

void SListPopFront(PNode* pHead);// ͷɾ 

PNode SListFind(PNode pHead, DataType data);// �������в���ֵΪdata��Ԫ�أ��ҵ��󷵻�ֵΪdata�Ľ��
 
void SListInsert(PNode* pHead, PNode pos, DataType data);// ��posλ�ò���ֵΪdata�Ľ��

void SListErase(PNode* pHead, PNode pos);// ɾ��posλ�õĽ�� 

int SListSize(PNode pHead);// ��ȡ����ĳ��� 

int SListEmpty(PNode pHead);// �ж������Ƿ�Ϊ�� 

void SListDestroy(PNode* pHead);// �����ı� 

void PrintSList(PNode pHead);//��ӡ�����ֵ
