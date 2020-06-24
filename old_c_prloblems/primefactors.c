#include <stdio.h>
int chkprime(int p)
{
	int i=0,j;
	for(j=2;j<p;j++)
	if(p%j==0 && ++i)
	break;
	return (i==0?1:0);
}
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=n;i>1;i--)
	{
		if((chkprime(i)==1) && ((n%i)==0))
		printf("%d\n",i);
	}
}