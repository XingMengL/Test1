/*5.ʵ��һ���������ж�һ�����ǲ���������*/

#include <stdio.h>
#include "math.h"

int su(int i)
{
	int b;
	
	for( b = 2; b <= sqrt(i); b++)
	{
		if( i % b == 0)
		{
			return 0;                                                                                                                                                     1
    	}

	}
    return 1;	
}
int main()
{
	
     int a;
     
     scanf("%d", &a);
	 
	   if (su(a))
    {
        printf("%d��һ��������\n",a);
    }
    else
        printf("%d����һ������!\n",a);
	
	return 0;
}
