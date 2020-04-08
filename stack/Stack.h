#pragma once
#include <stdio.h>
#include <windows.h>
#include <malloc.h>

typedef int SDataType;
typedef struct Stack
{
	SDataType* array;
	int size;//有效个数
	int capacity;//容量
}Stack;

void StackInit(Stack* ps);//栈的初始化
void StackPush(Stack* ps, SDataType val);//入栈
void StackPop(Stack* ps);//出栈
SDataType StackTop(Stack* ps);//获取栈顶元素
int StackSize(Stack* ps);//获取有效个数
int IsEmpty(Stack* ps);//判断栈是否为空 如果为空返回非零结果，如果不为空返回0 
void StackDestroy(Stack* ps);//销毁栈

void Test();//测试