#include"List.h"

//非接口函数声明
PNode  CreatSList();//创建单链表
void SListInit(PNode* pHead);//链表初始化
void SListPushBack(PNode* pHead, DataType data);// 尾插
PNode BuyNewNode(DataType data);//申请一个新结点
void PrintfSList(PNode pHead); //打印链表
PNode SListFindNode(PNode pHead, DataType data); //找到值为data的结点


//非接口函数实现
PNode  CreatSList()//创建一个链表
{
	int i = 0, n = 0;
	PNode pCur = NULL;
	PNode pHead = NULL;
	PNode pRet = NULL;
	DataType data;
	printf("输入链表结点数:");
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
void PrintfSList(PNode pHead) //打印链表
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
PNode BuyNewNode(DataType data)//创建一个新结点
{
	PNode pCur = NULL;
	pCur = (PNode)malloc(sizeof(Node));
	pCur->data = data;
	pCur->p_next = NULL;
	return pCur;
}
PNode SListFindNode(PNode pHead,DataType data)// 在链表中查找值为data的元素，找到后返回值为data的结点
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


//接口函数实现
void PrintSListFromTail2Head(PNode pHead)// 逆序打印单链表 
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

void DeleteListNotTailNode(PNode pos)// 删除链表的非尾结点，要求：不能遍历链表 
{
	PNode pCur = NULL;
	if (pos == NULL)
	{
		printf("不存在该结点,无法删除!!!\n");
		return;
	}
	//pCur是pos的下个节点
	pCur = pos->p_next;
	//将pCur的值赋值给pos
	pos->data = pCur->data;
	//将pCur的下个结点和pos链接上
	pos->p_next = pCur->p_next;
	//最后free掉pCur
	free(pCur);
}

void InesrtPosFront(PNode pos, DataType data)// 在链表pos位置前插入值为data的结点 
{
	PNode pCur = NULL;
	if(NULL==pos)
	{
		printf("链表中无该位置,无法插入!!!\n");
		return;
	}
	//采用交换值的方法插入
	pCur = BuyNewNode(data);
	pCur->p_next = pos->p_next;
	pos->p_next = pCur;
	//将两个结点的值交换
	{
		DataType temp = pos->data;
		pos->data = pCur->data;
		pCur->data = temp;
	}	
}

PNode FindMiddleNode(PNode pHead)// 查找链表的中间结点，要求只能遍历一次链表 
{
	PNode pSlow = pHead;
	PNode pFast = pHead;
	if (pHead == NULL)
		return NULL;
	//两个指针,快指针的速度是慢指针的2倍，快指针走到末尾时，慢指针刚好走到链表一半
	while (pFast->p_next&&pFast->p_next->p_next)
	{
		pFast = pFast->p_next->p_next;
		pSlow = pSlow->p_next;
	}
	if (pFast == NULL)//说明链表有奇数个结点，则返回最中间一个结点
	{
		return pSlow;
	}
	else   //说明链表有偶数个结点，有两个中间结点，返回第其中一个结点
	{
		return pSlow;    //返回中间第一个结点
#if 0
		return pSlow->p_next; //返回中间第二个节点
#endif
	}
}

PNode FindLastKNode(PNode pHead, int K)// 查找链表的倒数第K个结点，要求只能遍历一次链表 
{
	PNode pSlow = pHead;
	PNode pFast = pHead;
	if (pHead == NULL)
	{
		printf("链表为空\n");
		return NULL;
	}
	//先让快指针走k-1步，之后满指针和快指针一快走
	while (--K)
	{
		pFast = pFast->p_next;
	}
	//快慢指针一块走
	while (pFast->p_next)
	{
		pFast = pFast->p_next;
		pSlow = pSlow->p_next;
	}
	return pSlow;  //返回慢指针
}

void DeleteLastKNode(PNode pHead, int K)// 删除链表的倒数第K个结点，要求只能遍历一次链表 
{
	PNode pSlow = pHead;
	PNode pFast = pHead;
	PNode pRet = NULL;
	if (pHead == NULL)
	{
		printf("链表为空!!!\n");
		return NULL;
	}
	//利用FindLastKNode函数的方法，找到倒数第K个结点，再用替换法删除
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

void JosephCircle(PNode* pHead, const int M)// 用单链表实现约瑟夫环 
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

void ReverseSList(PNode* pHead)// 链表的逆置--三个指针 
{
	PNode pPre = NULL;//前一个结点为NULL，也就是逆置后链表的最后一个结点的Next
	PNode pMid = NULL; //中间结点
	PNode pNext = NULL; //后一个结点，用来保存每次逆置时链表的头结点
	assert(pHead);
	if (*pHead == NULL)
	{
		printf("链表为空!!!\n");
		return;
	}
	pMid = *pHead;//将头结点赋值给中间结点
	while (pMid)
	{
		pNext = pMid->p_next;//先保存下次逆置时链表的头结点
		pMid->p_next = pPre;//将当前结点插入到前一个结点的前面
		pPre = pMid;//前一个结点后移
		pMid = pNext;//当前结点后移
	}
	*pHead = pPre; //最后一个结点，将其置为头结点
	return;
}

void  ReverseSListOP(PNode *pHead)// 链表的逆置--头插法 
{
	PNode pCur = NULL;
	PNode pNext = NULL;
	if (*pHead == NULL)
	{
		printf("链表为空!!!\n");
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

void BubbleSort(PNode pHead)// 用冒泡排序思想对单链表进行排序 
{
	PNode pCur = NULL;
	PNode pNext = NULL;
	DataType Temp = 0;
	PNode pRet = NULL;
	if (pHead == NULL)
	{
		printf("链表为空!!!\n");
		return;
	}
	pCur = pHead; //外层循环的遍历指针
	while (pCur)  
	{

		pRet = pHead;
		while (pRet&&pRet->p_next)  //内层循环两个比较的指针，当循环跳出时，
		{	                        //说明最后两个结点已经比较完了                  
			pNext = pRet->p_next;  
			if (pRet->data > pNext->data) //将大的和小的交换
			{
				 Temp = pRet->data;
				 pRet->data = pNext->data;
				 pNext->data = Temp;
			}
			pRet = pRet->p_next; //指针后移
			
		}
		pCur = pCur->p_next;//外层循环指针后移
	}
}

PNode MergeSList(PNode pHead1, PNode pHead2)// 合并两个有序单链表，合并后依然有序 
{
	PNode pCur1 = NULL;
	PNode pCur2= NULL;
	PNode pCur = NULL;
	PNode pHead = NULL;
	if ((pHead1==NULL)&&(pHead2==NULL))return NULL;//判断如果两个链表都为空，退出
	if ((pHead1 == NULL) || (pHead2 == NULL))
		return pHead1 ? pHead2 : pHead1;
	pCur1 = pHead1; pCur2 = pHead2;//将头指针赋值给各自的遍历指针
	if (pCur1->data <= pCur2->data)//先找到第一个小的结点
	{
		pCur = pCur1; pCur1 = pHead1->p_next;//找到小的结点指针往后走一步
	}
	else
	{
		pCur = pCur2; pCur2 = pHead2->p_next;//找到小的结点指针往后走一步
	}
		pHead = pCur;//保存新链表的头指针
	while (pCur1&&pCur2)
	{
		if (pCur1->data <= pCur2->data)  
		{
			pCur->p_next = pCur1; //将小的赋值给新链表的p_next
			pCur = pCur1;//新的结点往后走一步
			pCur1 = pCur1->p_next;
		}
		else
		{
			pCur->p_next = pCur2;//将小的赋值给新链表的p_next
			pCur = pCur2;//新的结点往后走一步
			pCur2 = pCur2->p_next;
		}	
			
	}
	if (pCur1 == NULL)pCur->p_next = pCur2;
	else pCur->p_next = pCur1;
	return pHead;
}

int IsSListCross(PNode pHead1, PNode pHead2)// 判断两个单链表是否相交---链表不带环 
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

PNode GetCorssNode(PNode pHead1, PNode pHead2)// 求两个单链表相交的交点---链表不带环
{
	PNode pCur1 = pHead1;

	PNode pCur2 = pHead2;
	int count1=0, count2 = 0;
	int temp = 0;
	if (!IsSListCross(pHead1, pHead2))
	{
		printf("链表不相交，无交点!!!\n");return NULL;
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