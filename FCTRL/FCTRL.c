#include<stdio.h>
 
int main()
{
   int testcase=0;
   int n;
   int sum=0;
   scanf("%d",&testcase);
   while(testcase--) 
   {
       scanf("%d",&n);
       sum=0;
       while(n)
       {
           sum=sum+n/5;
           n=n/5;
       }
       printf("%d\n",sum);
   }
   return(0);
}    
