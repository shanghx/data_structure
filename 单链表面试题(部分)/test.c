#include"List.h"

void testPrintSListFromTail2Head(PNode pHead)  //测试逆序打印
{
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	PrintfSList(pHead);
	PrintSListFromTail2Head(pHead);
}
void testDeleteListNotTailNode(PNode pHead)// 测试删除链表的非尾结点，要求：不能遍历链表 

{
	PNode pos = NULL;
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	pos = SListFindNode(pHead, 2);
	PrintfSList(pHead);
	DeleteListNotTailNode(pos);
	PrintfSList(pHead);
}
void testInesrtPosFront(PNode pHead) //测试在链表pos位置前插入值到data的结点

{
	PNode pos = NULL;
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	pos = SListFindNode(pHead, 3);
	PrintfSList(pHead);
	InesrtPosFront(pos, 10);

	PrintfSList(pHead);
}
void testFindMiddleNode(PNode pHead)// 测试查找链表的中间结点，要求只能遍历一次链表 
{
	PNode pos = NULL;
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	PrintfSList(pHead);
	pos= FindMiddleNode(pHead);
	printf("%d\n", pos->data);	
}
void testFindLastKNode(PNode pHead)// 测试查找链表的倒数第K个结点，要求只能遍历一次链表
{
	PNode pos = NULL;
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	PrintfSList(pHead);
	pos=FindLastKNode(pHead, 3);
	printf("%d\n", pos->data);
}
void testDeleteLastKNode(PNode pHead)//  测试删除链表的倒数第K个结点，要求只能遍历一次链表 
{
	PNode pos = NULL;
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	PrintfSList(pHead);
	DeleteLastKNode(pHead, 2);
	PrintfSList(pHead);

}
void testJosephCircle(PNode pHead)// 测试用单链表实现约瑟夫环 
{
	
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	PrintfSList(pHead);
	JosephCircle(&pHead, 3);
	PrintfSList(pHead);
}
void testReverseSList(PNode pHead)// 测试链表的逆置--三个指针 
{
	
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	PrintfSList(pHead);
	ReverseSList(&pHead);
	PrintfSList(pHead);
}
void testReverseSListOP(PNode pHead)// 测试链表的逆置--头插法 
{
	
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	PrintfSList(pHead);
	ReverseSListOP(&pHead);
	PrintfSList(pHead);
}
void testBubbleSort(PNode pHead)// 测试用冒泡排序思想对单链表进行排序
{
	
	SListPushBack(&pHead, 5);
	SListPushBack(&pHead, 6);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 10);
	SListPushBack(&pHead, 5);
	PrintfSList(pHead);
	BubbleSort(pHead);
	PrintfSList(pHead);
}
void testMergeSList(PNode pHead1, PNode pHead2)// 测试合并两个有序单链表，合并后依然有序 
{
	PNode pos = NULL;
	SListPushBack(&pHead1, 1);
	SListPushBack(&pHead1, 3);
	SListPushBack(&pHead1, 6);
	SListPushBack(&pHead1, 9);
	SListPushBack(&pHead1, 10);
	PrintfSList(pHead1);
	SListPushBack(&pHead2, 2);
	SListPushBack(&pHead2, 5);
	SListPushBack(&pHead2, 6);
	SListPushBack(&pHead2, 10);
	SListPushBack(&pHead2, 12);
	PrintfSList(pHead2);
	pos=MergeSList(pHead1, pHead2);
	PrintfSList(pos);
}
void testIsSListCross(PNode pHead1, PNode pHead2)// 测试判断两个单链表是否相交，并求交点---链表不带环 
{
	PNode pos = NULL;
	PNode pos1 = NULL;
	PNode pos2 = NULL;
	SListPushBack(&pHead1, 1);
	SListPushBack(&pHead1, 3);
	SListPushBack(&pHead1, 6);
	SListPushBack(&pHead1, 9);
	SListPushBack(&pHead1, 10);
	SListPushBack(&pHead1, 12);
	pos1=SListFindNode(pHead1, 6);
	SListPushBack(&pHead2, 2);
	SListPushBack(&pHead2, 5);
	SListPushBack(&pHead2, 7);
	pos2 = SListFindNode(pHead2, 7);
	pos2->p_next = pos1;
	PrintfSList(pHead1);
	PrintfSList(pHead2);
	printf("%d\n",IsSListCross(pHead1,pHead2));
	pos=GetCorssNode(pHead1,pHead2);// 求两个单链表相交的交点---链表不带环
	printf("两链表的交点是%d\n", pos->data);
}
int main()
{
	PNode pHead = NULL;
	PNode pHead1 = NULL;
	PNode pHead2 = NULL;
	testPrintSListFromTail2Head(pHead);printf("\n");  //逆序打印测试
	testDeleteListNotTailNode(pHead);//测试删除链表的非尾结点
	testInesrtPosFront(pHead);//测试在链表pos位置前插入值到data的结点
	testFindMiddleNode(pHead);//测试查找链表的中间结点，要求只能遍历一次链表 
	testFindLastKNode(pHead);//测试查找链表的倒数第K个结点，要求只能遍历一次链表
	testDeleteLastKNode(pHead);//测试 删除链表的倒数第K个结点，要求只能遍历一次链表
	testJosephCircle(pHead);//测试用单链表实现约瑟夫环
	testReverseSList(pHead);//测试链表的逆置--三个指针 
	testReverseSListOP(pHead);//测试链表的逆置--头插法 
	testBubbleSort(pHead);//测试用冒泡排序思想对单链表进行排序 
	testMergeSList(pHead1, pHead2);//测试合并两个有序单链表，合并后依然有序
	testIsSListCross(pHead1, pHead2);//测试判断两个单链表是否相交，求交点---链表不带环 
	system("pause");
	return 0;
}