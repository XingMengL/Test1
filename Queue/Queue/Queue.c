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
void QueueInit(Queue* q)//��ʼ������
{
	QNode* HNode = BuyNewNode(0);//ͷ�ڵ�
	assert(q);
	//��ͷ�ڵ�Ķ���
	q->head = HNode;
	q->tail = HNode;
	q->size = 0;
	
}
void QueuePush(Queue* q,QDataType val)//���
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
void QueuePop(Queue* q)//����
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
QDataType QueueTop(Queue* q)//��ȡ��ͷԪ��
{
	assert(q);
	return q->head->next->val;
}
int QueueSize(Queue* q)//��ȡ��ЧԪ�ظ���
{
	assert(q);
	return q->size;
}
int QueueIsEmpty(Queue* q)//�ж϶����Ƿ�Ϊ�� ���Ϊ�շ��ط�����������ǿշ���0 
{
	assert(q);

	return 0 == q->size;
	
}
void QueueDestory(Queue* q)//���ٶ���
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
	printf("��ͷ = %d\n",q->head->next->val);
	printf("��ͷ = %d\n",q->tail->val);


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
