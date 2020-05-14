/*5.实现一个函数，判断一个数是不是素数。*/

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
        printf("%d是一个素数！\n",a);
    }
    else
        printf("%d不是一个素数!\n",a);
	
	return 0;
}
