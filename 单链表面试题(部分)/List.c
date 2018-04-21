#include"List.h"

//�ǽӿں�������
PNode  CreatSList();//����������
void SListInit(PNode* pHead);//�����ʼ��
void SListPushBack(PNode* pHead, DataType data);// β��
PNode BuyNewNode(DataType data);//����һ���½��
void PrintfSList(PNode pHead); //��ӡ����
PNode SListFindNode(PNode pHead, DataType data); //�ҵ�ֵΪdata�Ľ��


//�ǽӿں���ʵ��
PNode  CreatSList()//����һ������
{
	int i = 0, n = 0;
	PNode pCur = NULL;
	PNode pHead = NULL;
	PNode pRet = NULL;
	DataType data;
	printf("������������:");
	scanf("%d", &n); getchar();
	for (i = 0; i < n; ++i)
	{
		if (i == 0)
		{
			scanf("%d", &data); getchar();
			pHead = BuyNewNode(data);
			pCur = pHead;

		}
		else
		{
			scanf("%d", &data);getchar();
			pRet = BuyNewNode(data); 
			pCur->p_next = pRet;
			pCur = pRet;
		}
	}
	return pHead;
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
		*pHead = BuyNewNode(data);
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
		pCur->p_next = pRet;
		pRet->p_next = NULL;
	}
	return;
}
void PrintfSList(PNode pHead) //��ӡ����
{
	PNode pCur = pHead;
	while (pCur)
	{
		printf("%d ->", pCur->data);
		pCur = pCur->p_next;
	}
	printf("NULL");
	printf("\n");
}
PNode BuyNewNode(DataType data)//����һ���½��
{
	PNode pCur = NULL;
	pCur = (PNode)malloc(sizeof(Node));
	pCur->data = data;
	pCur->p_next = NULL;
	return pCur;
}
PNode SListFindNode(PNode pHead,DataType data)// �������в���ֵΪdata��Ԫ�أ��ҵ��󷵻�ֵΪdata�Ľ��
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


//�ӿں���ʵ��
void PrintSListFromTail2Head(PNode pHead)// �����ӡ������ 
{
	PNode pCur = pHead;
	PNode pRet = NULL;
	if (pHead == NULL)
		return;

	if (pCur->p_next)
	{
		
		PrintSListFromTail2Head(pCur->p_next);
	}
		
	if (!(pCur->p_next))
	{
		printf("NULL<--");printf("%d", pCur->data);
	}
		
	else
		printf("<-- %d ", pCur->data);

	/*if(pCur==pHead)
		printf("\n");*/
}

void DeleteListNotTailNode(PNode pos)// ɾ������ķ�β��㣬Ҫ�󣺲��ܱ������� 
{
	PNode pCur = NULL;
	if (pos == NULL)
	{
		printf("�����ڸý��,�޷�ɾ��!!!\n");
		return;
	}
	//pCur��pos���¸��ڵ�
	pCur = pos->p_next;
	//��pCur��ֵ��ֵ��pos
	pos->data = pCur->data;
	//��pCur���¸�����pos������
	pos->p_next = pCur->p_next;
	//���free��pCur
	free(pCur);
}

void InesrtPosFront(PNode pos, DataType data)// ������posλ��ǰ����ֵΪdata�Ľ�� 
{
	PNode pCur = NULL;
	if(NULL==pos)
	{
		printf("�������޸�λ��,�޷�����!!!\n");
		return;
	}
	//���ý���ֵ�ķ�������
	pCur = BuyNewNode(data);
	pCur->p_next = pos->p_next;
	pos->p_next = pCur;
	//����������ֵ����
	{
		DataType temp = pos->data;
		pos->data = pCur->data;
		pCur->data = temp;
	}	
}

PNode FindMiddleNode(PNode pHead)// ����������м��㣬Ҫ��ֻ�ܱ���һ������ 
{
	PNode pSlow = pHead;
	PNode pFast = pHead;
	if (pHead == NULL)
		return NULL;
	//����ָ��,��ָ����ٶ�����ָ���2������ָ���ߵ�ĩβʱ����ָ��պ��ߵ�����һ��
	while (pFast->p_next&&pFast->p_next->p_next)
	{
		pFast = pFast->p_next->p_next;
		pSlow = pSlow->p_next;
	}
	if (pFast == NULL)//˵����������������㣬�򷵻����м�һ�����
	{
		return pSlow;
	}
	else   //˵��������ż������㣬�������м��㣬���ص�����һ�����
	{
		return pSlow;    //�����м��һ�����
#if 0
		return pSlow->p_next; //�����м�ڶ����ڵ�
#endif
	}
}

PNode FindLastKNode(PNode pHead, int K)// ��������ĵ�����K����㣬Ҫ��ֻ�ܱ���һ������ 
{
	PNode pSlow = pHead;
	PNode pFast = pHead;
	if (pHead == NULL)
	{
		printf("����Ϊ��\n");
		return NULL;
	}
	//���ÿ�ָ����k-1����֮����ָ��Ϳ�ָ��һ����
	while (--K)
	{
		pFast = pFast->p_next;
	}
	//����ָ��һ����
	while (pFast->p_next)
	{
		pFast = pFast->p_next;
		pSlow = pSlow->p_next;
	}
	return pSlow;  //������ָ��
}

void DeleteLastKNode(PNode pHead, int K)// ɾ������ĵ�����K����㣬Ҫ��ֻ�ܱ���һ������ 
{
	PNode pSlow = pHead;
	PNode pFast = pHead;
	PNode pRet = NULL;
	if (pHead == NULL)
	{
		printf("����Ϊ��!!!\n");
		return NULL;
	}
	//����FindLastKNode�����ķ������ҵ�������K����㣬�����滻��ɾ��
	while (--K)
	{
		pFast = pFast->p_next;
	}
	while (pFast->p_next)
	{
		pFast = pFast->p_next;
		pSlow = pSlow->p_next;
	}
	pRet = pSlow->p_next;
	pSlow->data = pRet->data;
	pSlow->p_next = pRet->p_next;
	free(pRet);
}

void JosephCircle(PNode* pHead, const int M)// �õ�����ʵ��Լɪ�� 
{
	PNode pCur = NULL;
	PNode pPre = NULL;
	PNode pRet = NULL;
	int count = M;
	assert(pHead);
	if (*pHead == NULL)
	{
		return;
	}
	pCur = (*pHead);
	while (pCur->p_next)
	{
		pCur = pCur->p_next;
	}
	pCur->p_next = (*pHead);
	pCur = *pHead;
	while ((pCur->p_next)!=pCur)
	{
		count = M;
		while (--count)
		{
			pPre = pCur;
			pCur = pCur->p_next;
		}
		pRet = pCur;
		pPre->p_next = pCur->p_next;
		
		pCur = pCur->p_next;
		free(pRet);
	}
	
	pCur->p_next = NULL; *pHead = pCur;
	return;
}

void ReverseSList(PNode* pHead)// ���������--����ָ�� 
{
	PNode pPre = NULL;//ǰһ�����ΪNULL��Ҳ�������ú���������һ������Next
	PNode pMid = NULL; //�м���
	PNode pNext = NULL; //��һ����㣬��������ÿ������ʱ�����ͷ���
	assert(pHead);
	if (*pHead == NULL)
	{
		printf("����Ϊ��!!!\n");
		return;
	}
	pMid = *pHead;//��ͷ��㸳ֵ���м���
	while (pMid)
	{
		pNext = pMid->p_next;//�ȱ����´�����ʱ�����ͷ���
		pMid->p_next = pPre;//����ǰ�����뵽ǰһ������ǰ��
		pPre = pMid;//ǰһ��������
		pMid = pNext;//��ǰ������
	}
	*pHead = pPre; //���һ����㣬������Ϊͷ���
	return;
}

void  ReverseSListOP(PNode *pHead)// ���������--ͷ�巨 
{
	PNode pCur = NULL;
	PNode pNext = NULL;
	if (*pHead == NULL)
	{
		printf("����Ϊ��!!!\n");
		return;
	}
	pCur = *pHead;
	while ((*pHead)->p_next)
	{
		pNext = (*pHead)->p_next;
		(*pHead)->p_next = pNext->p_next;
		pNext->p_next = pCur;
		pCur = pNext;
	}
	 *pHead=pCur ;
}

void BubbleSort(PNode pHead)// ��ð������˼��Ե������������ 
{
	PNode pCur = NULL;
	PNode pNext = NULL;
	DataType Temp = 0;
	PNode pRet = NULL;
	if (pHead == NULL)
	{
		printf("����Ϊ��!!!\n");
		return;
	}
	pCur = pHead; //���ѭ���ı���ָ��
	while (pCur)  
	{

		pRet = pHead;
		while (pRet&&pRet->p_next)  //�ڲ�ѭ�������Ƚϵ�ָ�룬��ѭ������ʱ��
		{	                        //˵�������������Ѿ��Ƚ�����                  
			pNext = pRet->p_next;  
			if (pRet->data > pNext->data) //����ĺ�С�Ľ���
			{
				 Temp = pRet->data;
				 pRet->data = pNext->data;
				 pNext->data = Temp;
			}
			pRet = pRet->p_next; //ָ�����
			
		}
		pCur = pCur->p_next;//���ѭ��ָ�����
	}
}

PNode MergeSList(PNode pHead1, PNode pHead2)// �ϲ��������������ϲ�����Ȼ���� 
{
	PNode pCur1 = NULL;
	PNode pCur2= NULL;
	PNode pCur = NULL;
	PNode pHead = NULL;
	if ((pHead1==NULL)&&(pHead2==NULL))return NULL;//�ж������������Ϊ�գ��˳�
	if ((pHead1 == NULL) || (pHead2 == NULL))
		return pHead1 ? pHead2 : pHead1;
	pCur1 = pHead1; pCur2 = pHead2;//��ͷָ�븳ֵ�����Եı���ָ��
	if (pCur1->data <= pCur2->data)//���ҵ���һ��С�Ľ��
	{
		pCur = pCur1; pCur1 = pHead1->p_next;//�ҵ�С�Ľ��ָ��������һ��
	}
	else
	{
		pCur = pCur2; pCur2 = pHead2->p_next;//�ҵ�С�Ľ��ָ��������һ��
	}
		pHead = pCur;//�����������ͷָ��
	while (pCur1&&pCur2)
	{
		if (pCur1->data <= pCur2->data)  
		{
			pCur->p_next = pCur1; //��С�ĸ�ֵ���������p_next
			pCur = pCur1;//�µĽ��������һ��
			pCur1 = pCur1->p_next;
		}
		else
		{
			pCur->p_next = pCur2;//��С�ĸ�ֵ���������p_next
			pCur = pCur2;//�µĽ��������һ��
			pCur2 = pCur2->p_next;
		}	
			
	}
	if (pCur1 == NULL)pCur->p_next = pCur2;
	else pCur->p_next = pCur1;
	return pHead;
}

int IsSListCross(PNode pHead1, PNode pHead2)// �ж������������Ƿ��ཻ---�������� 
{
	PNode pCur1 = pHead1;
	
	PNode pCur2 = pHead2;
	if (pHead1 == NULL||pHead2==NULL)
	{
		return 0;
	}
	while (pCur1->p_next)
	{
		pCur1 = pCur1->p_next;
	}
	while (pCur2->p_next)
	{
		pCur2 = pCur2->p_next;
	}
	if (pCur1 == pCur2)
		return 1;
	else return 0;
	
}

PNode GetCorssNode(PNode pHead1, PNode pHead2)// �������������ཻ�Ľ���---��������
{
	PNode pCur1 = pHead1;

	PNode pCur2 = pHead2;
	int count1=0, count2 = 0;
	int temp = 0;
	if (!IsSListCross(pHead1, pHead2))
	{
		printf("�����ཻ���޽���!!!\n");return NULL;
	}
	while (pCur1)
	{
		count1++;
		pCur1 = pCur1->p_next; 
	}
	while (pCur2)
	{
		count2++;
		pCur2 = pCur2->p_next;
	}
	temp = count1 - count2;
	pCur1 = pHead1;
	pCur2 = pHead2;
	while (temp)
	{
		if (temp > 0)
		{
			pCur1 = pCur1->p_next;
			temp--;
		}
		else
		{
			pCur2 = pCur2->p_next;
			temp++;
		}
	}
	while (pCur1 != pCur2)
	{
		pCur1 = pCur1->p_next;
		pCur2 = pCur2->p_next;
	}
	return pCur1;  //return pCur2;
}