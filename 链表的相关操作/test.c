#include"SList.h"
int main()
{
	SList List;
	PNode  pHead = &List;
	PNode  pCur = NULL;
	
	SListInit(&pHead);//链表初始化
	//尾插测试
	SListPushBack(&pHead, 5);
	SListPushBack(&pHead, 6);
	SListPushBack(&pHead, 7);
	SListPushBack(&pHead, 8);
	SListPushBack(&pHead, 9);
	PrintSList(pHead);  //打印
	//头插测试
	SListPushFront(&pHead, 4);	
	SListPushFront(&pHead, 3);
	SListPushFront(&pHead, 2);
	SListPushFront(&pHead, 1);
	SListPushFront(&pHead, 0);
	PrintSList(pHead);  //打印

	//任意位置插入测试
	pCur = SListFind(pHead, 2); //先获取pos位置

	SListInsert(&pHead, pCur, 10); PrintSList(pHead);//打印

	SListInsert(&pHead,	NULL, 100); PrintSList(pHead);//打印

	//任意位置删除
	pCur = SListFind(pHead, 10);
	SListErase(&pHead, pCur); PrintSList(pHead); //打印
	//尾删测试
	SListPopBack(&pHead); PrintSList(pHead);//打印
	//头删测试
	SListPopFront(&pHead); PrintSList(pHead);//打印
	//打印链表的长度
	printf("链表长度是:%d\n",SListSize(pHead));
	//判断链表是否为空
	printf("链表是否为空:%d\n", SListEmpty(pHead));
	//销毁链表
	SListDestroy(&pHead);
	//再次判断是否为空
	printf("链表是否为空:%d\n", SListEmpty(pHead));
	system("pause");
	return 0;
}
