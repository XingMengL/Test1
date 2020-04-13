#pragma once

typedef int BTDataType;

typedef struct BTNode
{
	struct BTNode* pLeft;
	struct BTNode* pRight;
	BTDataType val;
}BTNode;

//�������Ĵ���
BTNode* CreatBinTree();
//ǰ�����
void PreOrder(BTNode* pRoot);
//�������
void InOrder(BTNode* pRoot);
//�������
void PostOrder(BTNode* pRoot);
//��ȡ�������ڵ�ĸ���
int GetNodeCount(BTNode* pRoot);
//��ȡ�������ĸ߶�
int GetBinTreeHigh(BTNode* pRoot);
//��ȡ������Ҷ�ӽڵ�ĸ���
int GetLeafCount(BTNode* pRoot);
//��ȡ��k���нڵ�ĸ���
int GetKLevelCount(BTNode * pRoot,int k);

//���� 
void BinTreeTest();