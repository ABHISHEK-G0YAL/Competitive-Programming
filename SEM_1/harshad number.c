#include <stdio.h>
void main()
{
	int n,sum,a,count=0,z,i=1;
	printf("Enter the number of Harshad Numbers to print.\n");
	scanf("%d",&n);
	while(count<=n)
	{
		sum=0;a=i;
		while(a > 0)
		{
			sum=sum+(a % 10);
			a=a/10;
		}
		z = i % sum;
		if(z==0)
		{
			printf("%d\t",i);
			++count;
		}
		++i;
	}
}
/*
Write a program to print n Harshad Numbers.
https://en.m.wikipedia.org/wiki/Harshad_number
*/
