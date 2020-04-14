#include "stdio.h"
int c(int m,int n)
 {
     
      if(m==1||m==n)
      
     return 1;
      
	  else 
	  
	   return c(m-1,n-1)+m*c(m,n-1);
 	
 }
 int main()
{
	FILE *fp1,*fp2;
	
	fp1=fopen("input,txt","r");
	
	fp2=fopen("output,txt","w");
	 
	int n,m,sum=0;
	
	fscanf(fp1,"%d",&n);
    
	 if(n<1)
		 printf("ÊäÈë´íÎó");
	
	else{
	
	for(m=1;m<=n;m++)
	
		sum+=c(m,n);
		
	 } 
	
	fprintf(fp2,"%d",sum);
	
	fclose(fp1);
	fclose(fp2); 
 } 
 
