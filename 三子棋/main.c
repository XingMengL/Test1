#include <stdio.h>
#include <stdlib.h>
#include "game.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void menu()
{
	printf("#################\n"); 
	printf("##   ������   ###\n"); 
	printf("#1��play 2��exit#\n"); 
	printf("#################\n"); 	
	
}

int main() {
	
	int select = 0;
	
	do
	{
	    menu();
		
		printf("��ѡ��"); 
		
		scanf("%d",&select);
		
		switch(select)
		{
			case 1:
				game();
				break;
			case 2:
 				select = 0;				
				break;
			default: 
			printf("���������������");
			 break;			
			
		}
		
		
	}while(select);
	return 0;
}
