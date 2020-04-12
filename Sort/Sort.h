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

		 array[pre+1] = key;//插入  array[pre] < key
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
			maxPos = 0; //标记最大元素的下标
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
		//最右侧位置可能存储的是当前最小值，交换后minPos标记的不是最小值
		if(maxPos != end)
			Swap(&array[maxPos],&array[end]);
		//在交换后要及时的更新minPos的标记位置
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
	for(i = 0;i < size - 1;i++)//控制冒泡的趟数 size-1次
	{
		//具体的冒泡方式：依次用相邻的两个元素进行比较，将大的向后移动
		//j表示的数组的下标 ---> 表示前一个元素的下标
		/*for(j = 0;j < size - i -1;j++)//XML
		{
			if(array[j] > array[j+1])
				Swap(&array[j],&array[j+1]);
		}*/
		//j表示的数组的下标 ---> 表示后一个元素的下标
		for(j = 1; j < size - i; j++)//XML
			{
				if(array[j-1]>array[j])
				Swap(&array[j],&array[j-1]);
			}
	}
}
/*void AdjustDn(int* array, int size,int parent)
{
	//优先标记左孩子 
	int child = parent * 2 + 1;
	while(child < size )
	{
		//找到最大的孩子
		//child+1<size保证右孩子的存在
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
	//建堆
	//1 找最后一个非叶子节点：最后一个叶子的双亲 （size-2）>> 1
	//2 从倒数第一个非叶子节点到根节点的位置开始向下调整
	int root = (size - 2)>>1;
	for(root; root >= 0;root--)
	{
		AdjustDn(array,size,root);
	}
	//利用堆删除的思想进行排序
	while(end)
	{
		Swap(&array[0],&array[end]);
		AdjustDn(array,end,0);//XML
		end--;

	}

}*/

void AdjustDn(int* array,int size, int parent)//参数：所需调整二叉树的数据，所需调整二叉树非叶子节点的个数，所需调整非叶子节点的位置
{
	//找到需要调整非叶子节点的最大孩子节点位置
	//优先标记左孩子的位置，因为右孩子可能不存在 如 child+1 > size 则右孩子不存在
	int child = 2 * parent + 1;
	while(child < size)
	{
	if( child + 1 < size&&array[child+1] > array[child])//要保证右孩子的存在 child+1<size
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
	//建堆
	//找到最后一个非叶子节点的位置 从最后一个非叶子节点到根向下调整
	int root = (size-2)>>1;
	int end = size - 1;//最后一个元素下标

	for(root;root>= 0;root--)
	{
		AdjustDn(array,size,root);
	}
	//排序 利用堆删除的思想
	while(end)
	{
		Swap(&array[0],&array[end]);
		AdjustDn(array,end,0);
		end--;
	}
}
//大堆排序--->升序
//小堆排序--->降序
/*int Partion(int* array,int left,int right)
{
	int begin = left;
	int end = right - 1;
	int key = array[end];
	while( begin < end)
	{
		while( begin < end && array[begin] <= key )
			   begin++;
		while( end > begin && array[end] >= key)//从后往前找小于基准值的数 
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
//左闭右开[left,right)
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
	Swap(&array[mid],&array[right - 1]);//XML  将中间值与最右侧值交换
	key = array[end];

	while(begin < end)
	{
		while(begin < end && array[begin] <= key)//从前到后找小于基准值小的下标
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
	int div = 0;//基准值下标
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
	
	//将数据整体的区间入栈  左闭右开[0, size) [left,rignt)
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
			//div是基准值的位置
			//基准值的左侧[left,div)
			//基准值的右侧[div+1,right)

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