#include"BinTree.h"

int main()
{
	char *str = "ABD###CE##F##";
	int size = strlen(str);
	PBTNode pRoot = NULL;
	CreateBinTree(&pRoot, str, size, '#');

	printf("前序遍历:"); PreOrder(pRoot); printf("\n");
	printf("拷贝后前序遍历:"); CopyBinTree(pRoot); PreOrder(pRoot); printf("\n");
	printf("中序遍历:"); InOrder(pRoot);printf("\n");
	printf("后序遍历:"); PostOrder(pRoot); printf("\n");
	printf("销毁后:"); DestroyBinTree(&pRoot);printf("\n");
	system("pause");
	return 0;
}
