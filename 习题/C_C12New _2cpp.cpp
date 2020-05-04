/*2.不使用（a+b）/2这种方式，求两个数的平均值。 */

#include <stdio.h>

int main()
{
	int a = 10;
	int b = 20;
	
	int avarage = ( a + b) >> 1;
	
	printf("%d", avarage);
	
	
	return 0;
}
