#include <stdio.h>
#include <string.h>

void CharSort(int* array,char* str,int size)
{    
	int i = 0;
	for(i = 0; i < size; i++)
	{
		array[str[i]]++;//字符出现的次数
	}
}
void Print(int* array, int size)
{
	int i = 0;
	for(i = 0; i < 255; i++)
	{
		while(array[i]--)
			printf("%c",i);
	
	}
	printf("\n");

}
int main()
{
	int array1[255]={0};
	char* str = "dbcdsfgdfga";
	int size = strlen(str);
	CharSort(array1,str,size);
	Print(array1,size);
	return 0;
}