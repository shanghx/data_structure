#include"SList.h"
int main()
{
	SList List;
	PNode  pHead = &List;
	PNode  pCur = NULL;
	
	SListInit(&pHead);//�����ʼ��
	//β�����
	SListPushBack(&pHead, 5);
	SListPushBack(&pHead, 6);
	SListPushBack(&pHead, 7);
	SListPushBack(&pHead, 8);
	SListPushBack(&pHead, 9);
	PrintSList(pHead);  //��ӡ
	//ͷ�����
	SListPushFront(&pHead, 4);	
	SListPushFront(&pHead, 3);
	SListPushFront(&pHead, 2);
	SListPushFront(&pHead, 1);
	SListPushFront(&pHead, 0);
	PrintSList(pHead);  //��ӡ

	//����λ�ò������
	pCur = SListFind(pHead, 2); //�Ȼ�ȡposλ��

	SListInsert(&pHead, pCur, 10); PrintSList(pHead);//��ӡ

	SListInsert(&pHead,	NULL, 100); PrintSList(pHead);//��ӡ

	//����λ��ɾ��
	pCur = SListFind(pHead, 10);
	SListErase(&pHead, pCur); PrintSList(pHead); //��ӡ
	//βɾ����
	SListPopBack(&pHead); PrintSList(pHead);//��ӡ
	//ͷɾ����
	SListPopFront(&pHead); PrintSList(pHead);//��ӡ
	//��ӡ����ĳ���
	printf("��������:%d\n",SListSize(pHead));
	//�ж������Ƿ�Ϊ��
	printf("�����Ƿ�Ϊ��:%d\n", SListEmpty(pHead));
	//��������
	SListDestroy(&pHead);
	//�ٴ��ж��Ƿ�Ϊ��
	printf("�����Ƿ�Ϊ��:%d\n", SListEmpty(pHead));
	system("pause");
	return 0;
}
