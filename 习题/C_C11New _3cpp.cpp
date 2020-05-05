/*3.在屏幕上打印杨辉三角。 
1 
1 1 
1 2 1 
1 3 3 1*/
#include <stdio.h>
void print_yang()
{
	int yang[10][10] = {0};
	int i, j;
	
	for(i = 0; i < 10; i++)
	  {
	 
	  	yang[i][0] = 1;
	  	yang[i][i] = 1; 
		  }
	for( i = 2; i < 10; i++)
	{
		for( j = 1; j < i; j++)
		    yang[i][j] = yang[i-1][j]+yang[i-1][j -1];
		    
		  }	  
	for(i = 0; i <10;i++)
	{	 
	for( j = 0; j <= i; j++)
	 {
	 	printf("%d",yang[i][j]);
	 }
        printf("\n");
	}

}

int main()
{
	print_yang();
	 
	
	return 0;
 } 
