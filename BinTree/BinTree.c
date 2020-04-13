#include "BinTree.h"
#include <stdio.h>
#include <assert.h>
#include <malloc.h>

BTNode* BuyNewBTNode(BTDataType val)
{
	BTNode* NewBTNode = (BTNode*)malloc(sizeof(BTNode));
	if(NULL == NewBTNode)
	{
	 assert(0);
	 return NULL;
	}
	NewBTNode->pLeft = NULL;
	NewBTNode->pRight = NULL;
	NewBTNode->val = val;

	return NewBTNode;
}
//二叉树的创建
BTNode* CreatBinTree(int* array,int size,int *index,BTDataType invalid)
{
	  BTNode* pRoot = NULL;
	if(*index < size && array[*index] != invalid)
	{
		pRoot = BuyNewBTNode(array[*index]);
		++(*index);
		pRoot->pLeft = CreatBinTree(array,size,index,invalid);
		++(*index);
		pRoot->pRight = CreatBinTree(array,size,index,invalid);	
	}
	
	/*if( *index < size && array[*index] != invalid)
	{
		//创建根节点
		pRoot = BuyNewBTNode(array[*index]);
		//递归创建左子树
		++(*index);
		pRoot->pLeft = CreatBinTree(array,size,index,invalid);
		//递归创建右子树
		++(*index);
		pRoot->pRight= CreatBinTree(array,size,index,invalid);
	    
    }*/
	return pRoot;
}
//前序遍历
void PreOrder(BTNode* pRoot)
{
	if(pRoot)
	{
		printf("%d",pRoot->val);
		PreOrder(pRoot->pLeft);
		PreOrder(pRoot->pRight);
	}
}
//中序遍历
void InOrder(BTNode* pRoot)
{
  
	if(pRoot)
	{
		PreOrder(pRoot->pLeft);
		printf("%d",pRoot->val);
		PreOrder(pRoot->pRight);
	}
}
//后序遍历
void PostOrder(BTNode* pRoot)
{
	if(pRoot)
	{
		PreOrder(pRoot->pLeft);
		PreOrder(pRoot->pRight);
		printf("%d",pRoot->val);
	}
}
//获取二叉树节点的个数
int GetNodeCount(BTNode* pRoot)//根节点+左子树节点+右子树节点
{
	if(NULL == pRoot)
	{
	  return 0;
	}
	return GetNodeCount(pRoot->pLeft)+GetNodeCount(pRoot->pRight)+1;
}
//获取二叉树的高度
int GetBinTreeHigh(BTNode* pRoot)
{
	int left = 0;
	int right = 0;
	if(NULL == pRoot)
	{	
		return 0;
	}
	left = GetBinTreeHigh(pRoot->pLeft);
    right = GetBinTreeHigh(pRoot->pRight);

	return left > right?left+1:right+1;
}
//获取二叉树叶子节点的个数
int GetLeafCount(BTNode* pRoot)//左子树叶子节点 + 右子树叶子节点
{
	if(NULL == pRoot)
	{
		return 0;
	}
	if(NULL == pRoot->pLeft && NULL == pRoot->pRight)
		return 1;

	return GetLeafCount(pRoot->pLeft)+GetLeafCount(pRoot->pRight);
}
//获取第k层中节点的个数
int GetKLevelCount(BTNode * pRoot,int k)
{
	if(NULL == pRoot || k <= 0)
	{
		return 0;
	}
	if(k == 1)
		return 1;
	return GetKLevelCount(pRoot->pLeft,k-1)+GetKLevelCount(pRoot->pRight,k-1);

}

void BinTreeTest()
{
	int array[] ={1,2,3,-1,-1,-1,4,5,-1,-1,6};
	int index = 0;
	int k = 2;
	BTNode* pRoot =  CreatBinTree(array,sizeof(array)/sizeof(array[0]),&index,-1);
	void PreOrder(BTNode* pRoot);
//前序遍历
	PreOrder(pRoot);
	printf("\n");
//中序遍历
	InOrder(pRoot);
	printf("\n");
//后序遍历
	PostOrder(pRoot);
	printf("\n");
//获取二叉树节点的个数
	
	printf("二叉树节点的个数:%d\n",GetNodeCount(pRoot));
//获取二叉树的高度
	
	printf("二叉树的高度:%d\n",GetBinTreeHigh(pRoot));
//获取二叉树叶子节点的个数

	printf("二叉树叶子节点的个数 %d\n",	GetLeafCount(pRoot));
//获取第k层中节点的个数
	GetKLevelCount(pRoot,k);
		printf("第k层中节点的个数 %d\n",GetKLevelCount(pRoot,k));
}