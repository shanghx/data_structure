#include"SList.h"
PNode BuyNewNode(DataType data)
{
	PNode pCur = NULL;
	pCur = (PNode )malloc(sizeof(SList));
	pCur->data = data;
	return pCur;
}
void SListInit(PNode* pHead)// 链表的初始化 
{
	*pHead = NULL;
	
}
void SListPushBack(PNode* pHead, DataType data)// 尾插
{
	PNode pCur = NULL;
	PNode pRet = NULL;
	assert(pHead);
	if (*pHead == NULL)
	{
		*pHead =BuyNewNode(data);
		(*pHead)->p_next = NULL;
		return;
	}
	else
	{
		pCur = *pHead;
		while (pCur->p_next)
		{
			pCur = pCur->p_next;
		}
		pRet = BuyNewNode(data);
		 pCur->p_next= pRet;
		 pRet->p_next = NULL;
	}
	return;
}
void SListPopBack(PNode* pHead)// 尾删
{
	PNode pCur = *pHead;
	PNode pPre = NULL;
	assert(pHead);
	if (*pHead == NULL)
	{
		printf("链表已空，无法删除!!!\n");
		return;
	}

	while (pCur->p_next)
	{
		pPre = pCur;
		pCur = pCur->p_next;
	}
	pPre->p_next = NULL;
	free(pCur);

#if 0
	while (pCur->p_next->p_next)
	{
		pCur = pCur->p_next;
	}
	PNode pNext = NULL;
	pNext = pCur->p_next;
	pCur->p_next = NULL;
	free(pNext);
#endif
}


void SListPushFront(PNode* pHead, DataType data)// 头插 
{
	PNode pCur = *pHead;
	PNode pRet = NULL;
	assert(pHead);
	if (*pHead == NULL)
	{
		*pHead = BuyNewNode(data);
		(*pHead)->p_next = NULL;
	}
	else
	{
		pRet = BuyNewNode(data);
		pRet->p_next = pCur;
		*pHead = pRet;
	}
}
void SListPopFront(PNode* pHead)// 头删 
{
	PNode pCur = NULL;
	//判断pHead是否合法
	assert(pHead);
	//检测链表是否为空
	if (NULL == *pHead)
	{
		printf("链表为空，无法删除!!!\n");
		return;
	}
	else
	{
		//链表不为空
		pCur = *pHead;
		*pHead = (*pHead)->p_next;
		free(pCur);
	}
}
PNode SListFind(PNode pHead, DataType data)// 在链表中查找值为data的元素，找到后返回值为data的结点
{
	PNode pCur = pHead;
	//检测链表是否为空
	if (pHead == NULL)
	{
		printf("链表中无元素!!!\n");
		return NULL;
	}
	//链表不为空
	while (pCur)
	{
		if (pCur->data == data)
			return pCur;
		pCur = pCur->p_next;
	}
	return NULL;
}
void SListInsert(PNode* pHead, PNode pos, DataType data)// 在pos位置插入值为data的结点
{
	PNode pCur = *pHead;
	PNode pRet = NULL;
	PNode pPre = NULL;
	//检测pHead合法性
	assert(pHead);
	//链表为空
	if (*pHead == NULL )
	{
		printf("链表为空，无法插入!!!\n");
		return;
	}
	if (pos == NULL)
	{
		printf("插入位置无效,无法插入!!!\n");
	}
	else
	{
		//链表不为空
		pCur = *pHead;
		while(pCur!=pos&&pCur)		
		{
			pPre = pCur;
			pCur = pCur->p_next;
		}
		if (pCur == NULL)
		{
			printf("链表中无该位置,无法插入!!!\n");
			return;
		}
		else
		{
			pRet = BuyNewNode(data);
			pRet->p_next = pCur;
			pPre->p_next = pRet;
		}
	}
	return;
}
void SListErase(PNode* pHead, PNode pos)// 删除pos位置的结点 
{
	PNode pCur = *pHead;
	PNode pPre = NULL;
	assert(pHead);
	if (*pHead == NULL)
	{
		printf("链表为空，无法删除!!!\n");
		return;
	}
	while (pCur != pos&&pCur)
	{
		pPre = pCur;
		pCur = pCur->p_next;
	}
	if (!pCur)
	{
		printf("链表中无该结点!!!\n");
		return;
	}
	else
	{
		pPre->p_next = pCur->p_next;
		free(pCur);
	}
}
int SListSize(PNode pHead)// 获取链表的长度
{
	PNode pCur = pHead;

	int count = 0;
	if (pHead == NULL)
		return  0;
	while (pCur)
	{
		count++;
		pCur = pCur->p_next;
	}
	return count;
}

int SListEmpty(PNode pHead)// 判断链表是否为空 
{
	if (pHead == NULL)
		return 0;
	else return 1;
}
void SListDestroy(PNode* pHead)// 销毁聊表 
{
	PNode pCur = *pHead;
	PNode pPre = NULL;
	assert(pHead);
	if (*pHead == NULL)
		return;
	while (pCur)
	{
		pPre = pCur;
		pCur = pCur->p_next;	
		free(pPre);
	}
	*pHead = NULL;
}
void PrintSList(PNode pHead)//打印链表的值
{
	PNode pCur = NULL;
	pCur = pHead;
	while (pCur)
	{
		printf("%d ", pCur->data);
		pCur = pCur->p_next;
	}
	printf("\n");
}
