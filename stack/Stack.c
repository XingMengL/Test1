#include "Stack.h"
#include <assert.h>
#include <string.h>

void CheckCapacity(Stack * ps)
{   
	int NewCapacity = ps->capacity*3;
	SDataType* Newarray = NULL;
	if(ps->size >= ps->capacity)
	{
		//�����¿ռ�
		Newarray = (SDataType*)malloc(sizeof(SDataType)*NewCapacity);
		//����Ԫ��
		memcpy(Newarray,ps->array,sizeof(SDataType)*NewCapacity);
		//�ͷžɿռ�
		free(ps->array);
		ps->array = Newarray;
		ps->capacity = NewCapacity;
	}
}
void StackInit(Stack* ps)//ջ�ĳ�ʼ��
{
	int capacity = 10;
	ps->array = (SDataType*)malloc(sizeof(SDataType)*capacity);
	if(NULL == ps->array)
		return;
	ps->capacity = capacity;
	ps->size = 0;
}
void StackPush(Stack* ps, SDataType val)//��ջ
{
	if(NULL == ps)
	{
		assert(0);
		return;
	}
	CheckCapacity(ps);//���ջ�Ƿ���Ҫ����
	ps->array[ps->size] = val;
	ps->size++;
	
}
void StackPop(Stack* ps)//��ջ
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
SDataType StackTop(Stack* ps)//��ȡջ��Ԫ��
{
	if(NULL == ps)
	{
		assert(0);
	}
	return ps->array[ps->size-1];
}
int StackSize(Stack* ps)//��ȡ��Ч����
{
	if(NULL == ps)
	{
		assert(0);
		
	}
	return ps->size;
}
int IsEmpty(Stack* ps)//�ж�ջ�Ƿ�Ϊ�� ���Ϊ�շ��ط������������Ϊ�շ���0 
{
	if(NULL == ps)
	{
		assert(0);
	}
	return  0 == ps->size;
}
void StackDestroy(Stack* ps)//����ջ
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
