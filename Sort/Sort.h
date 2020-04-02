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

		 array[pre+1] = key;//²åÈë  array[pre] < key
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
	


void TestSort()
{
	int array[] = {1,5,3,2,6,9,4,1,0};
	int size = sizeof(array)/sizeof(array[0]);
	Print(array,size);
	//InsertSort(array,size);
	ShellSort(array,size);
	Print(array,size);
	
}