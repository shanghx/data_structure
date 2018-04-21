#include"List.h"

void testPrintSListFromTail2Head(PNode pHead)  //���������ӡ
{
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	PrintfSList(pHead);
	PrintSListFromTail2Head(pHead);
}
void testDeleteListNotTailNode(PNode pHead)// ����ɾ������ķ�β��㣬Ҫ�󣺲��ܱ������� 

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
void testInesrtPosFront(PNode pHead) //����������posλ��ǰ����ֵ��data�Ľ��

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
void testFindMiddleNode(PNode pHead)// ���Բ���������м��㣬Ҫ��ֻ�ܱ���һ������ 
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
void testFindLastKNode(PNode pHead)// ���Բ�������ĵ�����K����㣬Ҫ��ֻ�ܱ���һ������
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
void testDeleteLastKNode(PNode pHead)//  ����ɾ������ĵ�����K����㣬Ҫ��ֻ�ܱ���һ������ 
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
void testJosephCircle(PNode pHead)// �����õ�����ʵ��Լɪ�� 
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
void testReverseSList(PNode pHead)// �������������--����ָ�� 
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
void testReverseSListOP(PNode pHead)// �������������--ͷ�巨 
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
void testBubbleSort(PNode pHead)// ������ð������˼��Ե������������
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
void testMergeSList(PNode pHead1, PNode pHead2)// ���Ժϲ��������������ϲ�����Ȼ���� 
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
void testIsSListCross(PNode pHead1, PNode pHead2)// �����ж������������Ƿ��ཻ�����󽻵�---�������� 
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
	pos=GetCorssNode(pHead1,pHead2);// �������������ཻ�Ľ���---��������
	printf("������Ľ�����%d\n", pos->data);
}
int main()
{
	PNode pHead = NULL;
	PNode pHead1 = NULL;
	PNode pHead2 = NULL;
	testPrintSListFromTail2Head(pHead);printf("\n");  //�����ӡ����
	testDeleteListNotTailNode(pHead);//����ɾ������ķ�β���
	testInesrtPosFront(pHead);//����������posλ��ǰ����ֵ��data�Ľ��
	testFindMiddleNode(pHead);//���Բ���������м��㣬Ҫ��ֻ�ܱ���һ������ 
	testFindLastKNode(pHead);//���Բ�������ĵ�����K����㣬Ҫ��ֻ�ܱ���һ������
	testDeleteLastKNode(pHead);//���� ɾ������ĵ�����K����㣬Ҫ��ֻ�ܱ���һ������
	testJosephCircle(pHead);//�����õ�����ʵ��Լɪ��
	testReverseSList(pHead);//�������������--����ָ�� 
	testReverseSListOP(pHead);//�������������--ͷ�巨 
	testBubbleSort(pHead);//������ð������˼��Ե������������ 
	testMergeSList(pHead1, pHead2);//���Ժϲ��������������ϲ�����Ȼ����
	testIsSListCross(pHead1, pHead2);//�����ж������������Ƿ��ཻ���󽻵�---�������� 
	system("pause");
	return 0;
}