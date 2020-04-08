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
	int size;//��ЧԪ�ظ���
}Queue;

void QueueInit(Queue* q);//��ʼ������
void QueuePush(Queue* q,QDataType val);//���
void QueuePop(Queue* q);//����
QDataType QueueTop(Queue* q);//��ȡ��ͷԪ��
int QueueSize(Queue* q);//��ȡ��ЧԪ�ظ���
int QueueIsEmpty(Queue* q);//�ж϶����Ƿ�Ϊ�� ���Ϊ�շ��ط�����������ǿշ���0 
void QueueDestory(Queue* q);//���ٶ���

void Test();