#include "Queue.h"


QNode* BuyNewNode(int val)
{
	QNode* NewNode = (QNode*)malloc(sizeof(QNode));
	if(NULL == NewNode)
	{
		assert(0);
		return NULL;
	}
	NewNode -> next = NULL;
	NewNode ->val = val;

	return NewNode;
}
void QueueInit(Queue* q)//初始化队列
{
	QNode* HNode = BuyNewNode(0);//头节点
	assert(q);
	//带头节点的队列
	q->head = HNode;
	q->tail = HNode;
	q->size = 0;
	
}
void QueuePush(Queue* q,QDataType val)//入队
{
	QNode* NewNode = BuyNewNode(val);
	if(NULL == q)
	{
		assert(0);
		return;
	}
	q->tail->next = NewNode;
	q->tail = NewNode;
	q->size++;
}
void QueuePop(Queue* q)//出队
{
	QNode* DelNode = q->head->next;
	if(NULL == q)
	{
		assert(0);
		return;
	}
	if(QueueIsEmpty(q))
		return;
	q->head->next = DelNode->next;
	q->size--;
	free(DelNode);
}
QDataType QueueTop(Queue* q)//获取队头元素
{
	assert(q);
	return q->head->next->val;
}
int QueueSize(Queue* q)//获取有效元素个数
{
	assert(q);
	return q->size;
}
int QueueIsEmpty(Queue* q)//判断队列是否为空 如果为空返回非零结果，如果非空返回0 
{
	assert(q);

	return 0 == q->size;
	
}
void QueueDestory(Queue* q)//销毁队列
{
	assert(q);
	if(q->size)
	{
		QueuePop(q);
		q->size--;
	}
	free(q->head);
	q->head = NULL;
	q->tail = NULL;
}
void ShowHeadAndTail(Queue * q)
{
	assert(q);
	if(NULL == q)
		return;
	printf("队头 = %d\n",q->head->next->val);
	printf("队头 = %d\n",q->tail->val);


}
void Print(Queue * q)
{
	QNode * cur = q->head->next;
	while(cur)
	{
		printf("%d ->",cur->val);
		cur = cur->next;
	}
	printf("NULL\n");
}
void Test()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q,1);
	QueuePush(&q,2);
	QueuePush(&q,3);
	QueuePush(&q,4);
	QueuePush(&q,5);
	QueuePush(&q,6);
	QueuePush(&q,7);
	QueuePush(&q,8);
	QueuePush(&q,9);
	printf("size =%d \n",QueueSize(&q));
	Print(&q);
	ShowHeadAndTail(&q);
	QueuePop(&q);
	printf("size =%d\n",QueueSize(&q));
	ShowHeadAndTail(&q);
	Print(&q);
	


}
