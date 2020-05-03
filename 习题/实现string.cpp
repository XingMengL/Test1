/*1.ʵ��strcpy 
2.ʵ��strcat 
3.ʵ��strstr 
4.ʵ��strchr 
5.ʵ��strcmp 
6.ʵ��memcpy 
7.ʵ��memmove*/ 
#include <stdio.h>
#include <string.h>
#include <assert.h>
char *my_strcpy(char *dest, const char * str)
{
	assert(dest);
	assert(str);
	char *ret = dest;
	while((*dest++ = *str++))
	{
		;
	}
	return ret;
}
char *my_strcat(char *dest, const char *str)
{
	assert(dest);
	assert(str);
	char *ret = dest;
	while(*dest)
	{
	   dest++;
	}
	while((*dest++ = *str++))
	{
		;
	}
    return ret;	
}
char *my_strstr(char *str1,  char *str2) 
{
	assert(str1);
	assert(str2);
	
	 char *cp = str1;
	 char *s1 = NULL;
	 char *substr = str2;
	 
	 if(*str2=='\0')
	{
		return NULL;
	}
	 
	 while(*cp)
	 {
	 	s1 = cp;
	 	substr = str2;
	 	while(*s1 && *substr &&(*s1 == *substr))
		 {
		 	s1++;
		 	substr++;
				  }	
		  if(*substr =='\0')
		  {
		  	return cp;
			   } 
			   cp++;	
	 }

}
int main()
{
	 char *str1 = "abcd";
	char str2[20]="xyzabcdxxxx";
	
	//printf("%s\n",my_strcpy(str2,str1));
//	printf("%s\n",my_strcat(str2,str1));
	printf("%s\n",my_strstr(str2,str1));
	
	
	return 0;
 } 
