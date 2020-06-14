#include <stdio.h>
int chkprime(int p)
{
	int i=0,j;
	for(j=2;j<p;j++)
	{
		if(p%j==0)
		{
			i++;break;
		}
	}
	return (i==0?1:0);
}
int main()
{
	int i;
	for(i=1;i<=100000;i++)
	{
		if(chkprime(i)==1)
		printf("%d\t",i);
	}
}
