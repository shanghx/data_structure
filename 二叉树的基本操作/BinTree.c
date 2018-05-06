#include"BinTree.h"
PBTNode BuyBinTreeNode(BTDataType data)// 构建二叉树的结点 
{
	PBTNode pNewTreeNode = (PBTNode)malloc(sizeof(BTNode));
	if (pNewTreeNode == NULL)
	{
		//如果开辟一个结点的空间都失败，说明此时计算机内存已经很小了，可能是程序存在内存泄露
		assert(pNewTreeNode);
		return NULL;   //然后返回空
	}
	//申请成功
	pNewTreeNode->_pLeft = NULL;
	pNewTreeNode->_pRight = NULL;
	pNewTreeNode->_data = data;
	return pNewTreeNode;
}

// 创建二叉树 
void _CreateBinTree(PBTNode* pRoot, const BTDataType* array, int size, int *index, BTDataType invalid)
{
	*pRoot = NULL;  //先让树根结点指向空
	if ((*index < size)&&array[*index] != invalid) //当前索引有效并且当前的值不是标志符
	{ 
		*pRoot = BuyBinTreeNode(array[*index]);//先创建根节点
		++(*index);

		_CreateBinTree(&(*pRoot)->_pLeft, array, size,  index, invalid);//递归创建左孩子
		++(*index);
		_CreateBinTree(&(*pRoot)->_pRight, array, size,  index, invalid);//递归创建右孩子
	}
	return;
	//递归返回到根节点，创建完成

}
//提供给用户的创建二叉树
void CreateBinTree(PBTNode* pRoot, const BTDataType* array, int size, BTDataType invalid)
{
	int index=0 ;
	
	assert(pRoot);//此时pRoot是根节点的地址的地址，不能为空，此处需要断言
	assert(array);//此时array是数组的地址，不能为空，此处需要断言
	_CreateBinTree(pRoot, array, size, &index, invalid);//调用真正的创建二叉树函数
}

// 拷贝二叉树 
PBTNode CopyBinTree(PBTNode pRoot)
{
	if (pRoot == NULL)//判断树是否为空
		return NULL;
	PBTNode pNewRoot = NULL;  //新二叉树的结点
	pNewRoot=BuyBinTreeNode(pRoot->_data);  //创建一个新的结点
	CopyBinTree(pRoot->_pLeft);   //递归创建左孩子
	CopyBinTree(pRoot->_pRight);      //递归创建右孩子
}

// 销毁二叉树 
void DestroyBinTree(PBTNode *pRoot)
{
	assert(pRoot); //断言指向树根指针是否为空

	if (*pRoot == NULL)    //	树为空，直接退出
		return;
		
	if((*pRoot)->_pLeft)       //如果左子树存在，递归销毁左子树
	DestroyBinTree(&(*pRoot)->_pLeft);
	if ((*pRoot)->_pRight)            //如果右子树存在，递归销毁右子树
	DestroyBinTree(&(*pRoot)->_pRight);
	
	free(*pRoot); *pRoot = NULL;   //销毁树根
}


void PreOrder(PBTNode pRoot)// 前序遍历递归 
{
	if (pRoot == NULL)   //二叉树为空，不做任何操作
		return;
	printf("%c ", pRoot->_data);
	if(pRoot->_pLeft)
	PreOrder(pRoot->_pLeft);
	if(pRoot->_pRight)
	PreOrder(pRoot->_pRight);	
	return;
}


// 中序遍历递归 
void InOrder(PBTNode pRoot)
{
	if (pRoot == NULL)
		return;
	if (pRoot->_pLeft)
		InOrder(pRoot->_pLeft);printf("%c ", pRoot->_data);
	if (pRoot->_pRight)
		InOrder(pRoot->_pRight);
	
}

// 后续遍历递归 
void PostOrder(PBTNode pRoot)
{
	if (pRoot == NULL)
		return;
	if (pRoot->_pLeft)
		PostOrder(pRoot->_pLeft);
	if (pRoot->_pRight)
		PostOrder(pRoot->_pRight);
	printf("%c ", pRoot->_data);
}

