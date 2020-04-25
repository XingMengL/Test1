#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <windows.h>
typedef int QDataType;
// 链式结构：表示队列 
typedef struct QListNode 
{ 
	struct QListNode* _next; 
	QDataType _data; 
}QNode; 

// 队列的结构 
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

// 初始化队列 
void QueueInit(Queue* q)
{
	QNode* HNode = NULL;//头节点
	if(NULL == q)
	{
		assert(0);
		return;
	}
	HNode =  BuyNewNode(0);
	q->_front = HNode;
	q->_rear = HNode;


}
// 队尾入队列 
void QueuePush(Queue* q, QDataType data)
{
	QNode* NewNode = BuyNewNode(data);
	q->_rear->_next = NewNode;
	q->_rear = NewNode;
}
// 队头出队列 
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
// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	assert(q);
	return q->_front->_next->_data;

}
// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{

	return q->_rear->_data;
}
// 获取队列中有效元素个数 
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
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{ 
	return 0 ==(QueueSize(q) == 0);
}
// 销毁队列 
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
