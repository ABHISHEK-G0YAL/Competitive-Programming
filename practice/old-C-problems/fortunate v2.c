/*
Write a program to print n fortunate numbers.
https://en.m.wikipedia.org/wiki/Fortunate_number
*/

#include <stdio.h>
int chkprime(long long int p)
{
	long long int i=0,j;
	for(j=2;j<p;j++)
	if(p%j==0 && ++i)
	break;
	return (i==0?1:0);
}
int main()
{
	long long int i,j,N,primorial=1,x=1;
	printf("Enter the number of fortunate numbers to print\n");
	scanf("%lld",&N);
	for(i=1;i<=N;i++)
	{
		loop1:;
		if(chkprime(++x)==1)
		primorial=primorial*x;
		else
		goto loop1;
		j=x;loop2:++j;
		if(chkprime(j)==1 && chkprime(primorial+j)==1)
		printf("%lld\t",j);
		else
		goto loop2;
	}
}