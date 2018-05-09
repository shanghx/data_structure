#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
typedef char BTDataType;  

typedef struct BinTreeNode           
{
	struct BinTreeNode* _pLeft;          //左孩子
	struct BinTreeNode* _pRight;         //右孩子
	BTDataType _data;
}BTNode, *PBTNode;

PBTNode BuyBinTreeNode(BTDataType data);// 构建二叉树的结点 


// 创建二叉树 
void _CreateBinTree(PBTNode* pRoot, const BTDataType* array, int size, int* index, BTDataType invalid);
void CreateBinTree(PBTNode* pRoot, const BTDataType* array, int size, BTDataType invalid);


PBTNode CopyBinTree(PBTNode pRoot);// 拷贝二叉树 


void DestroyBinTree(PBTNode *pRoot);// 销毁二叉树 


void PreOrder(PBTNode pRoot);// 前序遍历递归 




void InOrder(PBTNode pRoot);// 中序遍历递归 


void PostOrder(PBTNode pRoot);// 后续遍历递归 

