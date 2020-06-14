#include <stdio.h>
void main()
{
	int i,j,n,k=2,p;
	printf("Enter the number of lucky numbers to print");
	scanf("%d",&n);
	int a[20*n],b[6*n];
	for(i=0;i<20*n;i++)
	a[i]=i;
	for(i=1;i<=n;i++)
	{
		p=i;
		if(i!=1)
		k=a[i];
		for(j=i;j<20*n;j++)
		{
			if(j%k!=0)
			{
				a[p]=a[j];
				++p;
			}
			if(a[j]==0)
			break;
		}
		a[p]=0;
		printf("%d\t",a[i]);
	}
}
/*
Write a program to print n lucky numbers.
https://en.m.wikipedia.org/wiki/Lucky_number
*/
