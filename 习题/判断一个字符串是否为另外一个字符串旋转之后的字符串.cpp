/*2.�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ����� 
���磺����s1 =AABCD��s2 = BCDAA������1 
����s1=abcd��s2=ACBD������0. 

AABCD����һ���ַ��õ�ABCDA 
AABCD���������ַ��õ�BCDAA 

AABCD����һ���ַ��õ�DAABC */

#include <stdio.h>
#include <string.h>
int LeftRevolve(char str[], int num,int i,char str2[])
{
	char *p = &str[0];
	char *q = &str[1];
	int count  = num;
       while(i)
       {
       	while(count)
       	{
       		
    	*p ^=  *q;
	  	*q ^=  *p; 
	  	*p ^=  *q; 
	  	
	  	
	  	p++;
		q++;
		count--;
		   }
    int ret  = strcmp(str,str2); 
	  if(ret == 0)
	  {
	  	return 1;
	  }
	  else{
	  	return 0;
	  }
       	p = str;
       	q = str+1;
       	count = num;
       	i--; 
       	
	   }
	printf("%s",str);
	
}
int Judge()
{
	
	
}
int main()
{
	char s1[] = "ABCD";
	char s2[] = "BCDA";
	printf("s1 = %s\n",s1);
	printf("s2 = %s\n",s2); 
	int num = sizeof(s1)/sizeof(s1[0]) - 1;//������\0��; 
    int ret = LeftRevolve(s1, num - 1, num, s2);
	               // num - 1�� ABCD -> BCDA 3�ν���
				   // num��  ABCD -> ABCD ����������� 
    printf("%d",ret);	
	
	return 0;
}
