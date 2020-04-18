 #include "string.h"
#include "stdio.h"

#define  Maxstack 100
typedef  char DataType;
//#include "SeqStack.h"
 
typedef struct
{
	DataType stack[Maxstack];
	int top;
}Seqstack;                           /*����ṹ��*/

void Stackinitiate(Seqstack *S)      /*��ʼ��*/
{
	S->top=0;
}

int Stacknotempty(Seqstack S)        /*�жϷǿշ�*/
{
	if(S.top<=0)return 0;
	else return 1;
}
 
int Stackpush(Seqstack *S , DataType x)      /*��ջ*/
{
	if(S->top>=Maxstack)
  	{
		printf("��ջ�����޷����룡\n");
		return 0;
	}
	else
	{
		S->stack[S->top]=x;
		S->top++;
		return 1;
	}
}

int Stackpop(Seqstack *S , DataType *d)     /*��ջ*/
{
	if(S->top<=0)
 	{
		printf("��ջ�ѿ�������Ԫ�س�ջ��\n");
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
		printf("��ջ�ѿգ�\n");
		return 0;
	}
	else
	{
		*d = S.stack[S.top-1];
		return 1;
	}
}

void Expiscorrect(char exp[Maxstack] )      /*�ж���n���ַ��ĵ��ַ���exp���������Ƿ������ȷ*/
{
	Seqstack mystack;
	int i;
	char c;

	Stackinitiate(&mystack);
        for (i=0 ; exp[i] != '\0' ; i++)
	{
		if ( ( exp[i] == '(' ) || ( exp[i] == '[' ) )
			Stackpush(&mystack , exp[i] );       /*��ջ*/
		else if ( exp[i] == ')' && Stacknotempty(mystack) && Stacktop(mystack , &c)
                	&& c == '(')
			Stackpop ( &mystack , &c );
		else if ( exp[i] == ')' && Stacknotempty(mystack) && Stacktop(mystack , &c) 
			&& c != '(' )
			{
				printf("�˴�����ƥ�䲻�Ϸ���\n");
				return;
			}
		else if ( exp[i] == ']' && Stacknotempty(mystack) && Stacktop(mystack , &c)
			&& c =='[')
			Stackpop(&mystack , &c);
		else if ( exp[i] == ']' && Stacknotempty(mystack) && Stacktop(mystack , &c)
			&& c != '[')
			{
				printf("�˴�����ƥ�䲻�Ϸ���\n");
				return;
			}
		else if( ( exp[i] ==')' ) || ( exp[i] == ']' ) && !Stacknotempty(mystack) )
		{
			printf("�˴�����ƥ�䲻�Ϸ���\n");
			return;
		}
 	}
	if ( Stacknotempty(mystack) )
		printf("�˴�����ƥ�䲻�Ϸ���\n");
	else
		printf("ƥ�䣡\n");
}

int main()
{
	char str[Maxstack];
	printf("������Ҫƥ������ŵ�����:\n");	
	gets(str);
	Expiscorrect(str);

}


