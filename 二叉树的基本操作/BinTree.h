#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
typedef char BTDataType;  

typedef struct BinTreeNode           
{
	struct BinTreeNode* _pLeft;          //����
	struct BinTreeNode* _pRight;         //�Һ���
	BTDataType _data;
}BTNode, *PBTNode;

PBTNode BuyBinTreeNode(BTDataType data);// �����������Ľ�� 


// ���������� 
void _CreateBinTree(PBTNode* pRoot, const BTDataType* array, int size, int* index, BTDataType invalid);
void CreateBinTree(PBTNode* pRoot, const BTDataType* array, int size, BTDataType invalid);


PBTNode CopyBinTree(PBTNode pRoot);// ���������� 


void DestroyBinTree(PBTNode *pRoot);// ���ٶ����� 


void PreOrder(PBTNode pRoot);// ǰ������ݹ� 




void InOrder(PBTNode pRoot);// ��������ݹ� 


void PostOrder(PBTNode pRoot);// ���������ݹ� 

