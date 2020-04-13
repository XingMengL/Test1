#include "Stack.h"
#include <assert.h>
#include <string.h>

void CheckCapacity(Stack * ps)
{   
	int NewCapacity = ps->capacity*3;
	SDataType* Newarray = NULL;
	if(ps->size >= ps->capacity)
	{
		//申请新空间
		Newarray = (SDataType*)malloc(sizeof(SDataType)*NewCapacity);
		//拷贝元素
		memcpy(Newarray,ps->array,sizeof(SDataType)*NewCapacity);
		//释放旧空间
		free(ps->array);
		ps->array = Newarray;
		ps->capacity = NewCapacity;
	}
}
void StackInit(Stack* ps)//栈的初始化
{
	int capacity = 10;
	ps->array = (SDataType*)malloc(sizeof(SDataType)*capacity);
	if(NULL == ps->array)
		return;
	ps->capacity = capacity;
	ps->size = 0;
}
void StackPush(Stack* ps, SDataType val)//入栈
{
	if(NULL == ps)
	{
		assert(0);
		return;
	}
	CheckCapacity(ps);//检测栈是否需要扩容
	ps->array[ps->size] = val;
	ps->size++;
	
}
void StackPop(Stack* ps)//出栈
{
	if(NULL == ps)
	{
		assert(0);
		return;
	}
	if(!IsEmpty(ps))
	{
		ps->size--;
	}
}
SDataType StackTop(Stack* ps)//获取栈顶元素
{
	if(NULL == ps)
	{
		assert(0);
	}
	return ps->array[ps->size-1];
}
int StackSize(Stack* ps)//获取有效个数
{
	if(NULL == ps)
	{
		assert(0);
		
	}
	return ps->size;
}
int IsEmpty(Stack* ps)//判断栈是否为空 如果为空返回非零结果，如果不为空返回0 
{
	if(NULL == ps)
	{
		assert(0);
	}
	return  0 == ps->size;
}
void StackDestroy(Stack* ps)//销毁栈
{
	if(NULL == ps)
	{
		assert(0);
		return;
	}
	free(ps->array);
	ps->size = 0;
	ps->capacity = 0;
	ps->array = NULL;
}

void Test()
{
	Stack ps;
	StackInit(&ps);
	StackPush(&ps,1);
	StackPush(&ps,2);
	StackPush(&ps,3);
	StackPush(&ps,5);
	StackPush(&ps,6);
	StackPush(&ps,7);
	StackPush(&ps,8);
	StackPush(&ps,9);
	StackPush(&ps,10);
	StackPush(&ps,11);
	StackPush(&ps,12);
	StackPush(&ps,13);
	StackPush(&ps,14);
	StackPush(&ps,15);

	printf("Top = %d\n",StackTop(&ps));
	printf("Size = %d\n",StackSize(&ps));
	printf("Capacity = %d\n",ps.capacity);
	StackPop(&ps);
	printf("Top = %d\n",StackTop(&ps));
	printf("Size = %d\n",StackSize(&ps));
	printf("Capacity = %d\n",ps.capacity);
	
}
