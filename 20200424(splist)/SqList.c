#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <windows.h>
#pragma warning(disable:4018)
// ˳���Ķ�̬�洢
typedef int SLDataType;

typedef struct SeqList
{
   SLDataType* array; // ָ��̬���ٵ�����
   size_t size ;    // ��Ч���ݸ���
   size_t capicity ;  // �����ռ�Ĵ�С
}SeqList;

// ������ɾ��Ľӿ�
// ˳����ʼ��
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
// ˳�������
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
// ˳����ӡ
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
// ���ռ䣬������ˣ���������
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
		//�����¿ռ�
		 Newcapacity = (psl->capicity)*3;
		 Newarray = (SLDataType*)malloc(sizeof(SLDataType)*Newcapacity);

		 //��������
		 memcpy(Newarray,psl->array,sizeof(SLDataType)*psl->size);

		 //�ͷžɿռ�
		 free(psl->array);
		 psl->array = NULL;
		 psl->array = Newarray;
	 }
}
// ˳���β��
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
// ˳���βɾ
void SeqListPopBack(SeqList* psl)
{
	if( NULL == psl)
	{
		assert(0);
		return;
	}
	psl->size--;

}
// ˳���ͷ��
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
// ˳���ͷɾ
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
// ˳������
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
// ˳�����posλ�ò���x
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
// ˳���ɾ��posλ�õ�ֵ
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
	//�ƶ�n-1��Ԫ��
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
	printf("2��λ���� �� %d",SeqListFind(&sq, 2));
	printf("\n");

	SeqListErase(&sq,1);
	SeqListPrint(&sq);*/




	system("pause");

}