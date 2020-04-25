#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <windows.h>
typedef int QDataType;
// ��ʽ�ṹ����ʾ���� 
typedef struct QListNode 
{ 
	struct QListNode* _next; 
	QDataType _data; 
}QNode; 

// ���еĽṹ 
typedef struct Queue 
{ 
	QNode* _front; 
	QNode* _rear; 
}Queue; 

QNode* BuyNewNode(QDataType val)
{
	QNode* NewNode = (QNode*)malloc(sizeof(QNode));
	if(NULL == NewNode)
	{
		assert(0);
		return NULL;
	}
	NewNode->_data = val;
	NewNode->_next = NULL;

	return NewNode;
}

// ��ʼ������ 
void QueueInit(Queue* q)
{
	QNode* HNode = NULL;//ͷ�ڵ�
	if(NULL == q)
	{
		assert(0);
		return;
	}
	HNode =  BuyNewNode(0);
	q->_front = HNode;
	q->_rear = HNode;


}
// ��β����� 
void QueuePush(Queue* q, QDataType data)
{
	QNode* NewNode = BuyNewNode(data);
	q->_rear->_next = NewNode;
	q->_rear = NewNode;
}
// ��ͷ������ 
void QueuePop(Queue* q)
{
	QNode* DelNode = NULL;
	if(NULL == q)
	{
		return;
	}
	if(QueueEmpty(q))
		return;
	DelNode = q->_front->_next;
	q->_front->_next = DelNode->_next;
	free(DelNode);
	DelNode = NULL;
	
}
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	assert(q);
	return q->_front->_next->_data;

}
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{

	return q->_rear->_data;
}
// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q)
{
	int count = 0;
	QNode* cur = q->_front->_next;
	while(cur)
	{
		cur = cur->_next;
		count++;
	}
	return count;
}
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{ 
	return 0 ==(QueueSize(q) == 0);
}
// ���ٶ��� 
void QueueDestroy(Queue* q)
{
	if(QueueSize(q))
	{
		QueuePop(q);
	}
	free(q->_front);
	q->_front = NULL;
	q->_rear = NULL;

}
void Print(Queue * q)
{
	QNode * cur = q->_front->_next;
	while(cur)
	{
		printf("%d ->",cur->_data);
		cur = cur->_next;
	}
	printf("NULL\n");
}
int main()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q,1);
	QueuePush(&q,2);
	QueuePush(&q,3);
	QueuePush(&q,4);
	QueuePush(&q,5);
	Print(&q);
	

	system("pause");
	return 0;
}
