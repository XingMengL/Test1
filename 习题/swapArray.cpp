#include <stdio.h>
 
 void swapArray(int* array1,int* array2,int size)
 {
   int temp = 0;
   for(int i = 0;i<size;i++)
   {
       temp = array1[i];
       array1[i] = array2[i];
       array2[i] = temp;
 
   }
 }
 void  Print(int* array,int size)
 {
   
   for(int i = 0;i<size;i++)
   {
     printf("%d",array[i]);
   }
   printf("\n");
 }
 int main()
 {
   int array1[]={1,2,3,4,5,6};
   int array2[]={6,5,4,3,2,1};                                             
   int size = sizeof(array1)/sizeof(array1[0]);
   Print(array1,size);
   Print(array2,size);
  swapArray(array1,array2,size); 
 
   return 0;
 }
