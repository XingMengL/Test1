#pragma once

typedef int BTDataType;

typedef struct BTNode
{
	struct BTNode* pLeft;
	struct BTNode* pRight;
	BTDataType val;
}BTNode;

//二叉树的创建
BTNode* CreatBinTree();
//前序遍历
void PreOrder(BTNode* pRoot);
//中序遍历
void InOrder(BTNode* pRoot);
//后序遍历
void PostOrder(BTNode* pRoot);
//获取二叉树节点的个数
int GetNodeCount(BTNode* pRoot);
//获取二叉树的高度
int GetBinTreeHigh(BTNode* pRoot);
//获取二叉树叶子节点的个数
int GetLeafCount(BTNode* pRoot);
//获取第k层中节点的个数
int GetKLevelCount(BTNode * pRoot,int k);

//测试 
void BinTreeTest();