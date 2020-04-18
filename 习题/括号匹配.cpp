 #include "string.h"
#include "stdio.h"

#define  Maxstack 100
typedef  char DataType;
//#include "SeqStack.h"
 
typedef struct
{
	DataType stack[Maxstack];
	int top;
}Seqstack;                           /*定义结构体*/

void Stackinitiate(Seqstack *S)      /*初始化*/
{
	S->top=0;
}

int Stacknotempty(Seqstack S)        /*判断非空否*/
{
	if(S.top<=0)return 0;
	else return 1;
}
 
int Stackpush(Seqstack *S , DataType x)      /*入栈*/
{
	if(S->top>=Maxstack)
  	{
		printf("堆栈已满无法插入！\n");
		return 0;
	}
	else
	{
		S->stack[S->top]=x;
		S->top++;
		return 1;
	}
}

int Stackpop(Seqstack *S , DataType *d)     /*出栈*/
{
	if(S->top<=0)
 	{
		printf("堆栈已空无数据元素出栈！\n");
		return 0;
	}
	else
	{
		S->top--;
		*d=S->stack[S->top];
		return 1;
	}
}

int Stacktop(Seqstack S , DataType *d)
{
	if(S.top<=0)
	{
		printf("堆栈已空！\n");
		return 0;
	}
	else
	{
		*d = S.stack[S.top-1];
		return 1;
	}
}

void Expiscorrect(char exp[Maxstack] )      /*判断有n个字符的的字符串exp左、右括号是否配对正确*/
{
	Seqstack mystack;
	int i;
	char c;

	Stackinitiate(&mystack);
        for (i=0 ; exp[i] != '\0' ; i++)
	{
		if ( ( exp[i] == '(' ) || ( exp[i] == '[' ) )
			Stackpush(&mystack , exp[i] );       /*入栈*/
		else if ( exp[i] == ')' && Stacknotempty(mystack) && Stacktop(mystack , &c)
                	&& c == '(')
			Stackpop ( &mystack , &c );
		else if ( exp[i] == ')' && Stacknotempty(mystack) && Stacktop(mystack , &c) 
			&& c != '(' )
			{
				printf("此串括号匹配不合法！\n");
				return;
			}
		else if ( exp[i] == ']' && Stacknotempty(mystack) && Stacktop(mystack , &c)
			&& c =='[')
			Stackpop(&mystack , &c);
		else if ( exp[i] == ']' && Stacknotempty(mystack) && Stacktop(mystack , &c)
			&& c != '[')
			{
				printf("此串括号匹配不合法！\n");
				return;
			}
		else if( ( exp[i] ==')' ) || ( exp[i] == ']' ) && !Stacknotempty(mystack) )
		{
			printf("此串括号匹配不合法！\n");
			return;
		}
 	}
	if ( Stacknotempty(mystack) )
		printf("此串括号匹配不合法！\n");
	else
		printf("匹配！\n");
}

int main()
{
	char str[Maxstack];
	printf("请输入要匹配的括号的序列:\n");	
	gets(str);
	Expiscorrect(str);

}


