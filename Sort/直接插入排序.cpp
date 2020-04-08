#include <stdio.h>
/********************************************************************/
/* 第一次先用两个数据进行比较 所以 i = 1 ，end = 0 比较交换使之有序，所以每一个*/ 
/* 数据都是直接插入一个有序的数组中，所以只需要找到第一个小于key的数组元素并插 */ 
/* 入它的后面	array[end+1] = key； end是第一个小于key的下标                  */
/*******************************************************************************/ 
void InsertSort(int* array,int size)
{
	int i = 1;
	int key = 0;//保存插入的数据 
	int end = 0; 
	for( i ; i < size; i++)
	{
		key = array[i];
		end = i - 1;
		//找第一个小于key的数组元素 
		while(end >= 0 && key < array[end])
		{
			array[end+1] = array[end];//向后移动 
			end--; 
			
		}
		
		array[end+1] = key;
	}
}
void Print(int * array, int size)
{
	int i = 0;
	for(i;i<size;i++)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
}
int main()
{
	
	int array[] = {1,5,3,2,6,9,4,1,0};
	int size = sizeof(array)/sizeof(array[0]);
	Print(array,size);
	InsertSort(array,size);
	Print(array,size);
	
	return 0;
 } 
