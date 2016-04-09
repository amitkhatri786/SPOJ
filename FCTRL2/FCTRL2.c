#include<stdio.h>
#include<stdlib.h>
 
void factorial(int);
 
int main()
{
    int n=0;
    int testcase;
    scanf("%d",&testcase);
    while(testcase--)
    {
         scanf("%d",&n);
         factorial(n);
         printf("\n");
     }
    return(0);
}
 
void factorial(int n)
{
    static int a[100];
    //char *a;
    int i,t;
    int carry=0;
    int count=0;
    int len=0;
    if(n<=0)
    {
        printf("%d\n",1);
        exit(0);
    }
 
   // a = (int *) calloc (100,sizeof(int));
    a[0]=1;  
    for(i=2;i<=n;i++)
    {
        count=0;
        carry=0;
        while(count<=len)
        {
            t = a[count]*i+carry;
            carry = t/10;
            a[count] = t%10;
            count++;
        }
        if(carry!=0)
        {
            while(carry!=0)
            {
                a[count] = carry%10;
                carry = carry /10;
                count++;
             }
         }
        len = count-1;        
    }
    // printf("len= %d\n",len);
     for(i=len;i>=0;i--)
         printf("%d",a[i]);
    //free(a);
    //a=NULL; 
}
