/*
Can you code this challenge?

Title: Happy Numbers
Difficulty: Beginner

A happy number is defined by the following process. Starting with 
any positive integer, replace the number by the sum of the squares 
of its digits, and repeat the process until the number equals 1 
(where it will stay), or it loops endlessly in a cycle which does 
not include 1. Those numbers for which this process ends in 1 are 
happy numbers, while those that do not end in 1 are unhappy numbers.
Find the first n happy numbers.
*/

#include <stdio.h>
#include <math.h>
void main()
{
	long int i,n,num,sum,dig,count,nopc;
	nopc=0;sum=0;
	printf("Till what value do you want the happy numbers to be printed ?\n");
	scanf("%d",&n);
	printf("\n");
	for(i=1;i<=n;i++)
	{
		num=i;
		for(count=1;count<=10;count++)
		{
			while(num>0)
			{
				dig=num%10;
				num=num/10;
				sum=sum+pow(dig,2);
			}
			if(sum==1)
			{break;}
			else
			{num=sum;sum=0;}
		}
		if(sum==1)
		{printf("%ld\t",i);++nopc;}
		sum=0;
	}
	printf("\n\nThe number of happy numbers till %d are %d",n,nopc);
}