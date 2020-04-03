  1 #include <stdio.h>
  2 
  3 void swap(int* a,int* b)
  4 {
  5  int temp = *a;
  6   *a = *b;
  7   *b = temp;
  8   printf("a=%d b=%d\n",*a ,*b);
  9 
 10 }
 11 
 12 int main()
 13 {
 14   int a = 10;
 15   int b = 20;
 16   printf("a=%d b=%d\n",a ,b);
 17   swap(&a,&b);
 18   a = a ^ b;
 19   b = a ^ b;
 20   a = a ^ b;
 21   printf("a=%d b=%d\n",a ,b);                                                                                    
 22   return 0;
 23 }
~

