#include"BinTree.h"
PBTNode BuyBinTreeNode(BTDataType data)// �����������Ľ�� 
{
	PBTNode pNewTreeNode = (PBTNode)malloc(sizeof(BTNode));
	if (pNewTreeNode == NULL)
	{
		//�������һ�����Ŀռ䶼ʧ�ܣ�˵����ʱ������ڴ��Ѿ���С�ˣ������ǳ�������ڴ�й¶
		assert(pNewTreeNode);
		return NULL;   //Ȼ�󷵻ؿ�
	}
	//����ɹ�
	pNewTreeNode->_pLeft = NULL;
	pNewTreeNode->_pRight = NULL;
	pNewTreeNode->_data = data;
	return pNewTreeNode;
}

// ���������� 
void _CreateBinTree(PBTNode* pRoot, const BTDataType* array, int size, int *index, BTDataType invalid)
{
	*pRoot = NULL;  //�����������ָ���
	if ((*index < size)&&array[*index] != invalid) //��ǰ������Ч���ҵ�ǰ��ֵ���Ǳ�־��
	{ 
		*pRoot = BuyBinTreeNode(array[*index]);//�ȴ������ڵ�
		++(*index);

		_CreateBinTree(&(*pRoot)->_pLeft, array, size,  index, invalid);//�ݹ鴴������
		++(*index);
		_CreateBinTree(&(*pRoot)->_pRight, array, size,  index, invalid);//�ݹ鴴���Һ���
	}
	return;
	//�ݹ鷵�ص����ڵ㣬�������

}
//�ṩ���û��Ĵ���������
void CreateBinTree(PBTNode* pRoot, const BTDataType* array, int size, BTDataType invalid)
{
	int index=0 ;
	
	assert(pRoot);//��ʱpRoot�Ǹ��ڵ�ĵ�ַ�ĵ�ַ������Ϊ�գ��˴���Ҫ����
	assert(array);//��ʱarray������ĵ�ַ������Ϊ�գ��˴���Ҫ����
	_CreateBinTree(pRoot, array, size, &index, invalid);//���������Ĵ�������������
}

// ���������� 
PBTNode CopyBinTree(PBTNode pRoot)
{
	if (pRoot == NULL)//�ж����Ƿ�Ϊ��
		return NULL;
	PBTNode pNewRoot = NULL;  //�¶������Ľ��
	pNewRoot=BuyBinTreeNode(pRoot->_data);  //����һ���µĽ��
	CopyBinTree(pRoot->_pLeft);   //�ݹ鴴������
	CopyBinTree(pRoot->_pRight);      //�ݹ鴴���Һ���
}

// ���ٶ����� 
void DestroyBinTree(PBTNode *pRoot)
{
	assert(pRoot); //����ָ������ָ���Ƿ�Ϊ��

	if (*pRoot == NULL)    //	��Ϊ�գ�ֱ���˳�
		return;
		
	if((*pRoot)->_pLeft)       //������������ڣ��ݹ�����������
	DestroyBinTree(&(*pRoot)->_pLeft);
	if ((*pRoot)->_pRight)            //������������ڣ��ݹ�����������
	DestroyBinTree(&(*pRoot)->_pRight);
	
	free(*pRoot); *pRoot = NULL;   //��������
}


void PreOrder(PBTNode pRoot)// ǰ������ݹ� 
{
	if (pRoot == NULL)   //������Ϊ�գ������κβ���
		return;
	printf("%c ", pRoot->_data);
	if(pRoot->_pLeft)
	PreOrder(pRoot->_pLeft);
	if(pRoot->_pRight)
	PreOrder(pRoot->_pRight);	
	return;
}


// ��������ݹ� 
void InOrder(PBTNode pRoot)
{
	if (pRoot == NULL)
		return;
	if (pRoot->_pLeft)
		InOrder(pRoot->_pLeft);printf("%c ", pRoot->_data);
	if (pRoot->_pRight)
		InOrder(pRoot->_pRight);
	
}

// ���������ݹ� 
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

