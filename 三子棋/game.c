#include "game.h"
 
void Showboard(char board[][COL],int row,int col)
{
	printf("   1 | 2| 3|\n");
	printf("---------------\n");
	int i = 0;
	for(;i <row; i++)
	{
		int j = 0;
		printf("%d |", i+1);
		for(;j <col;j++)
		{
			printf("%c |",board[i][j]);
		}
	printf("\n");
	printf("------------\n");
	}
	
}
static int Isfull(char board[][COL], int row, int col)
{
	int i = 0;
	for(; i < row; i++)
	{
		int j  = 0;
		for(; j < col; j++)
		{
			if (board[i][j]==' ')
			{
				return 0;
			}
		}
	}
}
char Judge(char board[][COL],int row,int col)
{
    int i = 0; 
    int j =0;
	for (i = 0; i < row; i++){
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][1] == board[i][2] && board[i][1] != ' '){
			return board[i][1];
		}
	}//HANG
	for (j = 0; j < col; j++){
		if (board[0][j] == board[1][j] && board[0][j] == board[2][j] && board[1][j] == board[2][j] && board[1][j] != ' '){
			return board[1][j];
		}
	}//LIE
	//主对角线
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[1][1] == board[2][2] && board[1][1] != ' '){
		return board[1][1];
	}
	//副对角线
	if (board[0][2] == board[1][1] && board[0][2] == board[2][1] && board[1][1] == board[2][1] && board[1][1] != ' '){
		return board[1][1];
	}
	if(Isfull( board, row, col))
	{
		
		return 'E';
	}
	
	return 'F';
}

void ComputerMove(char board[][COL],int row,int col)
{   
       while(1)
       {
       	int x = rand()%3;
       	int y = rand()%3;
       	
       	if(board[x][y]==' ')
       	{
       		board[x][y] =computer;
       		break;
		   }
       	
	   }
	  	
}
void game()
{
    char board[ROW][COL];
	
    memset(board, ' ', sizeof(board));
    
    char win = ' ';
	
	int x = 0;
	int y = 0;
	srand((unsigned long)time(NULL));
	 
    
    do
    {
    	Showboard(board,ROW,COL);
		
	    printf("请输入你的落子位置：<x y>#");
    
    
	scanf("%d %d",&x, &y);
	   
    if(x <= 0 || x > 3 || y <= 0 || y > 3)
    {
    	printf("坐标有误，重新输入\n");
    	continue; 
	}
	if(board[x-1][y-1] != ' ')
    {
       printf("该位置占用，重新输入\n");
	   continue;				
	}
	board[x-1][y-1] = player;
    
	win = Judge(board ,ROW, COL);// X代表赢了 O代表输了  E 代表平局 F代表还没有下完	
	
	if(win != 'F'){
		break;
	}
	
	ComputerMove(board ,ROW, COL);
	
	 win = Judge(board ,ROW, COL);// X代表赢了 O代表输了  E 代表平局 F代表还没有下完	
	
		if(win != 'F')
		{
		  break;
	    }
		
	
	
	}while(1);
	Showboard(board,ROW,COL);
	
	if(win == player)
	{
		printf("你赢了\n");
	}
    else if(win == computer)
	 {
	  printf("电脑赢了\n"); 	
	 }    
    else 
    printf("平局\n"); 
  

}
