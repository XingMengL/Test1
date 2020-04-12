#pragma once

#include <stdio.h>
#include <windows.h>
#include "Stack.h"

void Print(int * array, int size)
{
	int i = 0;
	for(i;i<size;i++)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
}
void Swap(int* a, int* b)
{
	int temp  = *a;
	*a = *b;
	*b = temp;//XML

}
void InsertSort(int * array, int size)
{
	int i = 1;
	int key = 0;
	int pre = 0;
	for(i = 0; i<size;i++)
	{
		 key = array[i];
		 pre = i - 1;
		 while( pre >= 0 && key < array[pre] )
		 {
			array[pre+1] = array[pre];
			pre--;
		 }

		 array[pre+1] = key;//����  array[pre] < key
	}
}
void ShellSort(int* array,int size)
{
	int key = 0;
	int pre = 0;
	int i = 1;
	int gap = size;
	while(gap>1)
	{
		gap = gap/3+1;
	for(i = gap;i < size; i++)
	{
		key = array[i];
		pre = i - gap;
		while(pre>=0 && array[pre] > key)
		{
			//
			array[pre+gap] = array[pre];
			pre-= gap;

		}

		array[pre+gap] = key;

	}

	}
}
void SelectSort(int* array, int size)
{
		int i, j = 0;
		int maxPos = 0;
		for( i = 0; i < size - 1; i++)
		{    
			maxPos = 0; //������Ԫ�ص��±�
			for(j = 1; j  < size - i;j++)
			{
				if(array[j] > array[maxPos])
					maxPos = j;
			}
			if(maxPos != size-i-1)
				Swap(&array[maxPos],&array[size-i-1]);
		}
		}
void SelectSortOP(int* array,int size)
{
	int begin = 0;
	int end = size -1;
	while(begin <= end)
	{
		int maxPos = begin;//XML
		int minPos = begin;//XML
		int index = begin+1;//XML
		while(index <= end)
		{
			if(array[maxPos] <  array[index])
				maxPos = index;
			if(array[minPos] > array[index])
				minPos =index;
				index++;
		}
		//���Ҳ�λ�ÿ��ܴ洢���ǵ�ǰ��Сֵ��������minPos��ǵĲ�����Сֵ
		if(maxPos != end)
			Swap(&array[maxPos],&array[end]);
		//�ڽ�����Ҫ��ʱ�ĸ���minPos�ı��λ��
		if(minPos == end)//XML
minPos = maxPos;
		//Swap(&array[maxPos],&array[begin]);
   if(minPos != begin)
	Swap(&array[minPos],&array[begin]);

		begin++;
		end--;
		
	}

}
void BubbleSort(int* array,int size)
{
	int i,j = 0;
	for(i = 0;i < size - 1;i++)//����ð�ݵ����� size-1��
	{
		//�����ð�ݷ�ʽ�����������ڵ�����Ԫ�ؽ��бȽϣ����������ƶ�
		//j��ʾ��������±� ---> ��ʾǰһ��Ԫ�ص��±�
		/*for(j = 0;j < size - i -1;j++)//XML
		{
			if(array[j] > array[j+1])
				Swap(&array[j],&array[j+1]);
		}*/
		//j��ʾ��������±� ---> ��ʾ��һ��Ԫ�ص��±�
		for(j = 1; j < size - i; j++)//XML
			{
				if(array[j-1]>array[j])
				Swap(&array[j],&array[j-1]);
			}
	}
}
/*void AdjustDn(int* array, int size,int parent)
{
	//���ȱ������ 
	int child = parent * 2 + 1;
	while(child < size )
	{
		//�ҵ����ĺ���
		//child+1<size��֤�Һ��ӵĴ���
		if(child+1 < size && array[child+1] > array[child])
			child += 1;
		//
		if(array[child] > array[parent])
		{
			Swap(&array[child],&array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			return;
		}
	}

}
void HeapSort(int* array,int size)
{

	int end = size - 1;
	//����
	//1 �����һ����Ҷ�ӽڵ㣺���һ��Ҷ�ӵ�˫�� ��size-2��>> 1
	//2 �ӵ�����һ����Ҷ�ӽڵ㵽���ڵ��λ�ÿ�ʼ���µ���
	int root = (size - 2)>>1;
	for(root; root >= 0;root--)
	{
		AdjustDn(array,size,root);
	}
	//���ö�ɾ����˼���������
	while(end)
	{
		Swap(&array[0],&array[end]);
		AdjustDn(array,end,0);//XML
		end--;

	}

}*/

void AdjustDn(int* array,int size, int parent)//������������������������ݣ����������������Ҷ�ӽڵ�ĸ��������������Ҷ�ӽڵ��λ��
{
	//�ҵ���Ҫ������Ҷ�ӽڵ������ӽڵ�λ��
	//���ȱ�����ӵ�λ�ã���Ϊ�Һ��ӿ��ܲ����� �� child+1 > size ���Һ��Ӳ�����
	int child = 2 * parent + 1;
	while(child < size)
	{
	if( child + 1 < size&&array[child+1] > array[child])//Ҫ��֤�Һ��ӵĴ��� child+1<size
		child +=1;
	if(array[child] > array[parent])
	{
		Swap(&array[child],&array[parent]);
		parent = child;
		child = 2 * parent + 1;
	}
	else
		return;
	
	}
}
void HeapSort(int * array, int size)
{
	//����
	//�ҵ����һ����Ҷ�ӽڵ��λ�� �����һ����Ҷ�ӽڵ㵽�����µ���
	int root = (size-2)>>1;
	int end = size - 1;//���һ��Ԫ���±�

	for(root;root>= 0;root--)
	{
		AdjustDn(array,size,root);
	}
	//���� ���ö�ɾ����˼��
	while(end)
	{
		Swap(&array[0],&array[end]);
		AdjustDn(array,end,0);
		end--;
	}
}
//�������--->����
//С������--->����
/*int Partion(int* array,int left,int right)
{
	int begin = left;
	int end = right - 1;
	int key = array[end];
	while( begin < end)
	{
		while( begin < end && array[begin] <= key )
			   begin++;
		while( end > begin && array[end] >= key)//�Ӻ���ǰ��С�ڻ�׼ֵ���� 
				end--;
		

		if(begin < end)
			Swap(&array[begin],&array[end]);
	
	}
	Swap(&array[begin],&array[right-1]);
	return begin;
}
void QuickSort(int* array, int left, int right)
{
      int div = 0;

	  if(right - left > 1)
	{
	 div = Partion(array,left,right);
	 QuickSort(array,left,div);
	 QuickSort(array,div+1,right);	
	}

}*/
//����ҿ�[left,right)
int Centor(int* array,int left, int right)
{
		int centor = (left + right ) >> 1;
		if(array[left] < array[centor])
			Swap(&array[left],&array[centor]);
		if(array[left] < array[right - 1])
			Swap(&array[left],&array[right - 1]);
		if(array[centor] < array[right - 1]);
		Swap(&array[centor],&array[right - 1]);

		return centor;
}
int Partion(int* array, int left, int right)
{
	int begin = left;
	int end = right - 1;
	int key =0;
	int mid = Centor(array,left,right);
	Swap(&array[mid],&array[right - 1]);//XML  ���м�ֵ�����Ҳ�ֵ����
	key = array[end];

	while(begin < end)
	{
		while(begin < end && array[begin] <= key)//��ǰ������С�ڻ�׼ֵС���±�
	           begin++;
		while(begin < end && array[end] >= key)
			   end--;
		if(begin < end )
			Swap(&array[begin],&array[end]);
	}
	Swap(&array[begin],&array[right - 1]);
	return begin;
}
void QuickSort(int* array, int left, int right)
{
	int div = 0;//��׼ֵ�±�
	if(left < right)
	{
	 div = Partion(array,left,right);
	 QuickSort(array,left,div);
	 QuickSort(array,div+1,right);
	
	}

}
void QuickSortNor(int* array,int size)
{
	Stack s;
	int left = 0;
	int right = 0; 
	StackInit(&s);
	
	//�����������������ջ  ����ҿ�[0, size) [left,rignt)
	StackPush(&s, size);
	StackPush(&s, 0);

	while(!StackEmpty(&s))
	{
		left = StackTop(&s);
		StackPop(&s);
		right = StackTop(&s);
		StackPop(&s);

		if(right - left > 1)
		{
			int div = Partion(array,left,right);
			//div�ǻ�׼ֵ��λ��
			//��׼ֵ�����[left,div)
			//��׼ֵ���Ҳ�[div+1,right)

			StackPush(&s,right);
			StackPush(&s,div+1);

			StackPush(&s,div);
			StackPush(&s,left);

		}
	}

}
void TestSort()
{
	int array[] = {1,5,3,2,6,9,4,1,0};
	int size = sizeof(array)/sizeof(array[0]);
	Print(array,size);
	//InsertSort(array,size);
	//ShellSort(array,size);
	//SelectSort(array,size);
	//SelectSortOP(array,size);
	//BubbleSort(array,size);
	//HeapSort(array,size);
	// QuickSort(array,0,size);
	  QuickSortNor(array,size);
	Print(array,size);
	
}