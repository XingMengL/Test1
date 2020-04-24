#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
// 支持动态增长的栈
typedef int STDataType;
typedef struct Stack
{
	STDataType* array;
	int _top;		// 栈顶
	int _capacity;  // 容量 
}Stack;
// 初始化栈 
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
// 入栈 
void StackPush(Stack* ps, STDataType data)
{
	if(NULL == ps)
	{
		assert(0);
		return;
	}
	//判断是否够

	ps->array[ps->_top++] = data;
	
}
// 出栈 
void StackPop(Stack* ps)
{
	if(0 != StackEmpty(ps))
	{
		return;
	}
	ps->_top--;
	
}
// 获取栈顶元素 
STDataType StackTop(Stack* ps)
{
	if(0!=StackEmpty(ps))
	{
		return -1;
	}
	return ps->_top-1;
}
// 获取栈中有效元素个数 
int StackSize(Stack* ps)
{
	return ps->_top;
}
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps)
{
	return 0 == ps->_top;
}
// 销毁栈 
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