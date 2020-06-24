/*
Write a program to print n fortunate numbers.
https://en.m.wikipedia.org/wiki/Fortunate_number
*/

#include <stdio.h>
int chkprime(int p)
{
	int i=0,j;
	for(j=2;j<p;j++)
	{
		if(p%j==0)
		{
			i++;
			break;
		}
	}
	return (i==0?1:0);
}
int main()
{
	long int i,j,N,count,primorial,x;
	printf("Enter the number of fortunate numbers to print\n");
	scanf("%ld",&N);
	for(i=1;i<=N;i++)
	{
		count=1,primorial=1,x=1;
		while(count<=i)
		{
			if(chkprime(++x)==1)
			{
				primorial=primorial*x;
				++count;
			}
		}
		for(j=2;j>0;++j)
		{
			if(chkprime(primorial+j)==1)
			{
				printf("%ld\t",j);
				break;
			}
		}
	}	
}