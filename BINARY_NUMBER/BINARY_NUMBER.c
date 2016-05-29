#include<stdio.h>

int main()
{
	char a[20]={0};
	fun(a,0,3);
	return(0);
}

int fun(char a[10],int index,int n)
{
	if(index > n-1 )
		printf("%s\n",a);
	else
	{
		a[index]='0';
		fun(a,index+1,n);
		a[index]='1';
		fun(a,index+1,n);
	}
}
