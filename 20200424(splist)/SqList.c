#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <windows.h>
#pragma warning(disable:4018)
// 顺序表的动态存储
typedef int SLDataType;

typedef struct SeqList
{
   SLDataType* array; // 指向动态开辟的数组
   size_t size ;    // 有效数据个数
   size_t capicity ;  // 容量空间的大小
}SeqList;

// 基本增删查改接口
// 顺序表初始化
void SeqListInit(SeqList* psl, size_t capacity)
{
	if(NULL==psl)
	{
		assert(0);
		return;
	}
	psl->array = (SLDataType*)malloc(sizeof(SLDataType)*capacity);
	if(	NULL==psl->array)
	{
		assert(0);
	}
	psl->capicity = capacity;
	psl->size = 0;
}
// 顺序表销毁
void SeqListDestory(SeqList* psl)
{
	if(NULL == psl)
	{
		assert(0);
		return;
	}
	free(psl->array);
	psl->array = NULL;
	psl->capicity = 0;
	psl->size = 0;
}
// 顺序表打印
void SeqListPrint(SeqList* psl)
{
	int i = 0;
	if(	NULL == psl)
	{
		assert(0);
		return;
	}
  	for( i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->array[i]);
	}
}
// 检查空间，如果满了，进行增容
void CheckCapacity(SeqList* psl)
{
	 SLDataType* Newarray = NULL;
	 int Newcapacity = 0;
	 if(NULL == psl)
	 {
		 assert(0);
		 return;

	 }
	 if(psl->size>=psl->capicity)
	 {
		//申请新空间
		 Newcapacity = (psl->capicity)*3;
		 Newarray = (SLDataType*)malloc(sizeof(SLDataType)*Newcapacity);

		 //拷贝数据
		 memcpy(Newarray,psl->array,sizeof(SLDataType)*psl->size);

		 //释放旧空间
		 free(psl->array);
		 psl->array = NULL;
		 psl->array = Newarray;
	 }
}
// 顺序表尾插
void SeqListPushBack(SeqList* psl, SLDataType x)
{
	if( NULL == psl)
	{
		assert(0);
		return;
	}
	CheckCapacity(psl);
	psl->array[psl->size] = x;
	psl->size++;
}
// 顺序表尾删
void SeqListPopBack(SeqList* psl)
{
	if( NULL == psl)
	{
		assert(0);
		return;
	}
	psl->size--;

}
// 顺序表头插
void SeqListPushFront(SeqList* psl, SLDataType x)
{	
	int end = 0;
	int i = 0;
	if( NULL == psl)
	{
		assert(0);
		return;
	}
	CheckCapacity(psl);
	end = psl->size;
	for(i = 0; i < end+1;i++)
	{
		psl->array[psl->size+1] = psl->array[psl->size];
		psl->size--;
	}
	psl->array[0] = x;
	psl->size = end+1;
}
// 顺序表头删
void SeqListPopFront(SeqList* psl)
{
	int i = 0;
	if( NULL == psl)
	{
		assert(0);
		return;
	}
	for(i = 0; i < psl->size-1; i++)
	{
		psl->array[i] = psl->array[i+1];
	}
	psl->size--;
}
// 顺序表查找
int SeqListFind(SeqList* psl, SLDataType x)
{
	 int i = 0;
	 if( NULL == psl)
	{
		assert(0);
		return -1;
	}
	 for( i = 0; i < psl->size; i++)
	 {
		 if(psl->array[i] == x)
			 break;
	 }
	return i;
}
// 顺序表在pos位置插入x
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
{
	int SIZE = 0;
	if( NULL == psl)
	{
		assert(0);
		return;
	}
	CheckCapacity(psl);
	SIZE = psl->size;

	while(psl->size >= pos)
	{
		psl->array[psl->size+1] = psl->array[psl->size];
		psl->size--;
	}
	psl->array[pos] = x;
	psl->size = SIZE+1;
}
// 顺序表删除pos位置的值
void SeqListErase(SeqList* psl, size_t pos)
{
	int SIZE = 0;
	int i = 0;
	int j = 0;
	if(NULL == psl)
	{
		assert(0);
		return;
	}
	//移动n-1个元素
	j = pos;
	SIZE = psl->size;
	for( i = 0; i < psl->size - pos;i++)
	{
		psl->array[j] = psl->array[j+1];
		j++;
	}
	psl->size =  SIZE -1;
}

int main()
{
	SeqList sq;

	SeqListInit(&sq,10);
	SeqListPushBack(&sq,1);
	SeqListPushBack(&sq,2);
	SeqListPushBack(&sq,3);
	SeqListPushBack(&sq,4);
	SeqListPushBack(&sq,5);
	SeqListPushBack(&sq,6);
	SeqListPrint(&sq);
	printf("\n");
	SeqListPushFront(&sq,0);
	SeqListPrint(&sq);
	
	
	/*printf("\n");
	/*SeqListPopBack(&sq);
	SeqListPopBack(&sq);
	SeqListPopBack(&sq);
	SeqListPopBack(&sq);
	SeqListPopBack(&sq);*/


	/*SeqListPopFront(&sq);
	SeqListPopFront(&sq);
	SeqListPopFront(&sq);
	SeqListPopFront(&sq);
	SeqListPrint(&sq);
	printf("2的位置是 ： %d",SeqListFind(&sq, 2));
	printf("\n");

	SeqListErase(&sq,1);
	SeqListPrint(&sq);*/




	system("pause");

}