/*3.编程实现： 
一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。 
请找出这个数字。（使用位运算）*/
#include <stdio.h>

int difr(int *p)
{
    
	int ret = p[0];
	int  i = 0;
    for(i = 0; i < 7; i++)
    {
    	printf("%d ",p[i]);
	}
     
    for(i = 1; i < 7; i++)
    {
    	ret ^= p[i]  ?
    
	}
     
     return ret;
}

int main()
{
	int a[] = { 1, 1, 2, 2 ,3 ,3 ,4};
	
	int *p = a;
	int ret = difr(p);
	printf("\n");
	printf("%d",ret);
	
	
}
