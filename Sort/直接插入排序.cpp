#include <stdio.h>
/********************************************************************/
/* ��һ�������������ݽ��бȽ� ���� i = 1 ��end = 0 �ȽϽ���ʹ֮��������ÿһ��*/ 
/* ���ݶ���ֱ�Ӳ���һ������������У�����ֻ��Ҫ�ҵ���һ��С��key������Ԫ�ز��� */ 
/* �����ĺ���	array[end+1] = key�� end�ǵ�һ��С��key���±�                  */
/*******************************************************************************/ 
void InsertSort(int* array,int size)
{
	int i = 1;
	int key = 0;//������������ 
	int end = 0; 
	for( i ; i < size; i++)
	{
		key = array[i];
		end = i - 1;
		//�ҵ�һ��С��key������Ԫ�� 
		while(end >= 0 && key < array[end])
		{
			array[end+1] = array[end];//����ƶ� 
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
