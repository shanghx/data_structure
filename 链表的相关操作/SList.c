#include"SList.h"
PNode BuyNewNode(DataType data)
{
	PNode pCur = NULL;
	pCur = (PNode )malloc(sizeof(SList));
	pCur->data = data;
	return pCur;
}
void SListInit(PNode* pHead)// ����ĳ�ʼ�� 
{
	*pHead = NULL;
	
}
void SListPushBack(PNode* pHead, DataType data)// β��
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
void SListPopBack(PNode* pHead)// βɾ
{
	PNode pCur = *pHead;
	PNode pPre = NULL;
	assert(pHead);
	if (*pHead == NULL)
	{
		printf("�����ѿգ��޷�ɾ��!!!\n");
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


void SListPushFront(PNode* pHead, DataType data)// ͷ�� 
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
void SListPopFront(PNode* pHead)// ͷɾ 
{
	PNode pCur = NULL;
	//�ж�pHead�Ƿ�Ϸ�
	assert(pHead);
	//��������Ƿ�Ϊ��
	if (NULL == *pHead)
	{
		printf("����Ϊ�գ��޷�ɾ��!!!\n");
		return;
	}
	else
	{
		//����Ϊ��
		pCur = *pHead;
		*pHead = (*pHead)->p_next;
		free(pCur);
	}
}
PNode SListFind(PNode pHead, DataType data)// �������в���ֵΪdata��Ԫ�أ��ҵ��󷵻�ֵΪdata�Ľ��
{
	PNode pCur = pHead;
	//��������Ƿ�Ϊ��
	if (pHead == NULL)
	{
		printf("��������Ԫ��!!!\n");
		return NULL;
	}
	//����Ϊ��
	while (pCur)
	{
		if (pCur->data == data)
			return pCur;
		pCur = pCur->p_next;
	}
	return NULL;
}
void SListInsert(PNode* pHead, PNode pos, DataType data)// ��posλ�ò���ֵΪdata�Ľ��
{
	PNode pCur = *pHead;
	PNode pRet = NULL;
	PNode pPre = NULL;
	//���pHead�Ϸ���
	assert(pHead);
	//����Ϊ��
	if (*pHead == NULL )
	{
		printf("����Ϊ�գ��޷�����!!!\n");
		return;
	}
	if (pos == NULL)
	{
		printf("����λ����Ч,�޷�����!!!\n");
	}
	else
	{
		//����Ϊ��
		pCur = *pHead;
		while(pCur!=pos&&pCur)		
		{
			pPre = pCur;
			pCur = pCur->p_next;
		}
		if (pCur == NULL)
		{
			printf("�������޸�λ��,�޷�����!!!\n");
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
void SListErase(PNode* pHead, PNode pos)// ɾ��posλ�õĽ�� 
{
	PNode pCur = *pHead;
	PNode pPre = NULL;
	assert(pHead);
	if (*pHead == NULL)
	{
		printf("����Ϊ�գ��޷�ɾ��!!!\n");
		return;
	}
	while (pCur != pos&&pCur)
	{
		pPre = pCur;
		pCur = pCur->p_next;
	}
	if (!pCur)
	{
		printf("�������޸ý��!!!\n");
		return;
	}
	else
	{
		pPre->p_next = pCur->p_next;
		free(pCur);
	}
}
int SListSize(PNode pHead)// ��ȡ����ĳ���
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

int SListEmpty(PNode pHead)// �ж������Ƿ�Ϊ�� 
{
	if (pHead == NULL)
		return 0;
	else return 1;
}
void SListDestroy(PNode* pHead)// �����ı� 
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
void PrintSList(PNode pHead)//��ӡ�����ֵ
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
