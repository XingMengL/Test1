/*3.���ʵ�֣� 
һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ� 
���ҳ�������֡���ʹ��λ���㣩*/
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
