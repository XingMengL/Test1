#pragma once
#include <stdio.h>
#include <windows.h>
#include <malloc.h>

typedef int SDataType;
typedef struct Stack
{
	SDataType* array;
	int size;//��Ч����
	int capacity;//����
}Stack;

void StackInit(Stack* ps);//ջ�ĳ�ʼ��
void StackPush(Stack* ps, SDataType val);//��ջ
void StackPop(Stack* ps);//��ջ
SDataType StackTop(Stack* ps);//��ȡջ��Ԫ��
int StackSize(Stack* ps);//��ȡ��Ч����
int IsEmpty(Stack* ps);//�ж�ջ�Ƿ�Ϊ�� ���Ϊ�շ��ط������������Ϊ�շ���0 
void StackDestroy(Stack* ps);//����ջ

void Test();//����