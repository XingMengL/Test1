#pragma once

#include <stdio.h>
#include <windows.h>

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

		 array[pre+1] = key;// ����  array[pre] < key
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

void TestSort()
{
	int array[] = {1,5,3,2,6,9,4,1,0};
	int size = sizeof(array)/sizeof(array[0]);
	Print(array,size);
	//InsertSort(array,size);
	//ShellSort(array,size);
	//SelectSort(array,size);
	//SelectSortOP(array,size);
	BubbleSort(array,size);

	Print(array,size);
	
}
