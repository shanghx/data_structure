#include"BinTree.h"

int main()
{
	char *str = "ABD###CE##F##";
	int size = strlen(str);
	PBTNode pRoot = NULL;
	CreateBinTree(&pRoot, str, size, '#');

	printf("ǰ�����:"); PreOrder(pRoot); printf("\n");
	printf("������ǰ�����:"); CopyBinTree(pRoot); PreOrder(pRoot); printf("\n");
	printf("�������:"); InOrder(pRoot);printf("\n");
	printf("�������:"); PostOrder(pRoot); printf("\n");
	printf("���ٺ�:"); DestroyBinTree(&pRoot);printf("\n");
	system("pause");
	return 0;
}
