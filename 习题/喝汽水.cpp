/*2.����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ�� 
��20Ԫ�����Զ�����ˮ�� 
���ʵ�֡�*/

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


