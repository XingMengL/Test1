/*2.喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水， 
给20元，可以多少汽水。 
编程实现。*/

#include <stdio.h>
int buy(int money)
{
	int bot = 0;
	
	while(money != 1)
	{
				

		if (money % 2 == 1)

		{	

			bot += money/2;		

			money = money / 2 + 1;		

		}

		else

		{

			bot += money / 2;

			money = money / 2;		

		}
		
	}
	return bot;
}
int main()
{
	
	int x = 20;
	int ret = buy(x);
	printf("%d\n", ret);
	
	return 0;
 } 


