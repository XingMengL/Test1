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
//�������Ĵ���
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
		//�������ڵ�
		pRoot = BuyNewBTNode(array[*index]);
		//�ݹ鴴��������
		++(*index);
		pRoot->pLeft = CreatBinTree(array,size,index,invalid);
		//�ݹ鴴��������
		++(*index);
		pRoot->pRight= CreatBinTree(array,size,index,invalid);
	    
    }*/
	return pRoot;
}
//ǰ�����
void PreOrder(BTNode* pRoot)
{
	if(pRoot)
	{
		printf("%d",pRoot->val);
		PreOrder(pRoot->pLeft);
		PreOrder(pRoot->pRight);
	}
}
//�������
void InOrder(BTNode* pRoot)
{
  
	if(pRoot)
	{
		PreOrder(pRoot->pLeft);
		printf("%d",pRoot->val);
		PreOrder(pRoot->pRight);
	}
}
//�������
void PostOrder(BTNode* pRoot)
{
	if(pRoot)
	{
		PreOrder(pRoot->pLeft);
		PreOrder(pRoot->pRight);
		printf("%d",pRoot->val);
	}
}
//��ȡ�������ڵ�ĸ���
int GetNodeCount(BTNode* pRoot)//���ڵ�+�������ڵ�+�������ڵ�
{
	if(NULL == pRoot)
	{
	  return 0;
	}
	return GetNodeCount(pRoot->pLeft)+GetNodeCount(pRoot->pRight)+1;
}
//��ȡ�������ĸ߶�
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
//��ȡ������Ҷ�ӽڵ�ĸ���
int GetLeafCount(BTNode* pRoot)//������Ҷ�ӽڵ� + ������Ҷ�ӽڵ�
{
	if(NULL == pRoot)
	{
		return 0;
	}
	if(NULL == pRoot->pLeft && NULL == pRoot->pRight)
		return 1;

	return GetLeafCount(pRoot->pLeft)+GetLeafCount(pRoot->pRight);
}
//��ȡ��k���нڵ�ĸ���
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
//ǰ�����
	PreOrder(pRoot);
	printf("\n");
//�������
	InOrder(pRoot);
	printf("\n");
//�������
	PostOrder(pRoot);
	printf("\n");
//��ȡ�������ڵ�ĸ���
	
	printf("�������ڵ�ĸ���:%d\n",GetNodeCount(pRoot));
//��ȡ�������ĸ߶�
	
	printf("�������ĸ߶�:%d\n",GetBinTreeHigh(pRoot));
//��ȡ������Ҷ�ӽڵ�ĸ���

	printf("������Ҷ�ӽڵ�ĸ��� %d\n",	GetLeafCount(pRoot));
//��ȡ��k���нڵ�ĸ���
	GetKLevelCount(pRoot,k);
		printf("��k���нڵ�ĸ��� %d\n",GetKLevelCount(pRoot,k));
}