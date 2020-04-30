/*2.判断一个字符串是否为另外一个字符串旋转之后的字符串。 
例如：给定s1 =AABCD和s2 = BCDAA，返回1 
给定s1=abcd和s2=ACBD，返回0. 

AABCD左旋一个字符得到ABCDA 
AABCD左旋两个字符得到BCDAA 

AABCD右旋一个字符得到DAABC */

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
	int num = sizeof(s1)/sizeof(s1[0]) - 1;//包含‘\0’; 
    int ret = LeftRevolve(s1, num - 1, num, s2);
	               // num - 1： ABCD -> BCDA 3次交换
				   // num：  ABCD -> ABCD 考虑所有情况 
    printf("%d",ret);	
	
	return 0;
}
