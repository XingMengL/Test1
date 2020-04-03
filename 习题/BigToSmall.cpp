  1 #include <stdio.h>
  2 
  3 void BigToSmall(int*a,int*b,int*c)
  4 {
  5   int temp = 0;
  6   if(*a<*b)
  7   {
  8     temp = *b;
  9     *b = *a;
 10     *a = temp;
 11   }
 12   if(*b<*c)
 13   {
 14     temp = *c;
 15     *c = *b;
 16     *b = temp;
 17   }
 18   if(*a<*b)
 19   {
 20     temp = *a;
 21     *a = *b;
 22     *b = temp;                                                                                                   
 23   }
 24   printf("%d %d %d\n",*a,*b,*c);
 25 
 26 }
 27 int main()
 28 {
 29   int a = 10;
 30   int b = 20;
 31   int c = 30;
 32  BigToSmall(&a,&b,&c);
 33 
 34   return 0;
 35 }

