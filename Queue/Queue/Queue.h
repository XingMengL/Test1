#pragma once
#include <stdio.h>
#include <windows.h>
#include <malloc.h>
#include <assert.h>

typedef int QDataType;

typedef struct QNode
{
	struct QNode* next;
	QDataType val;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;//有效元素个数
}Queue;

void QueueInit(Queue* q);//初始化队列
void QueuePush(Queue* q,QDataType val);//入队
void QueuePop(Queue* q);//出队
QDataType QueueTop(Queue* q);//获取队头元素
int QueueSize(Queue* q);//获取有效元素个数
int QueueIsEmpty(Queue* q);//判断队列是否为空 如果为空返回非零结果，如果非空返回0 
void QueueDestory(Queue* q);//销毁队列

void Test();