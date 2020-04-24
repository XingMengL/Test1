#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
// ֧�ֶ�̬������ջ
typedef int STDataType;
typedef struct Stack
{
	STDataType* array;
	int _top;		// ջ��
	int _capacity;  // ���� 
}Stack;
// ��ʼ��ջ 
void StackInit(Stack* ps)
{
	ps->array = (STDataType*)malloc(sizeof(STDataType)*10);
	if(NULL == ps->array)
	{
		assert(0);
		return;
	}
	ps->_capacity = 10;
	ps->_top = 0;
}
// ��ջ 
void StackPush(Stack* ps, STDataType data)
{
	if(NULL == ps)
	{
		assert(0);
		return;
	}
	//�ж��Ƿ�

	ps->array[ps->_top++] = data;
	
}
// ��ջ 
void StackPop(Stack* ps)
{
	if(0 != StackEmpty(ps))
	{
		return;
	}
	ps->_top--;
	
}
// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps)
{
	if(0!=StackEmpty(ps))
	{
		return -1;
	}
	return ps->_top-1;
}
// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps)
{
	return ps->_top;
}
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps)
{
	return 0 == ps->_top;
}
// ����ջ 
void StackDestroy(Stack* ps)
{
	free(ps->array);
	ps->array = NULL;
	ps->_capacity = 0;
	ps->_top = 0;
}
void Print(Stack* ps)
{
	int i = 0;
	for( i; i < ps->_top; i++)
	{
		printf("%d ",ps->array[i]);
	}
	printf("\n");
}
int main()
{
	Stack ps;
	int ret = 0;
	StackInit(&ps);
	StackPush(&ps,1);
	StackPush(&ps,2);
	StackPush(&ps,3);
	StackPush(&ps,4);
	StackPush(&ps,5);
	printf("SIZE = %d \n",StackSize(&ps));
	printf("TOP = %d \n",StackTop(&ps));
	Print(&ps);
	StackPop(&ps);
	StackPop(&ps);
	StackPop(&ps);
	StackPop(&ps);
	StackPop(&ps);
	StackPop(&ps);
	printf("SIZE = %d \n",StackSize(&ps));
	printf("TOP = %d \n",StackTop(&ps));
	ret = StackEmpty(&ps);
	printf("%d \n",ret);
	



	system("pause");
	return 0;
}