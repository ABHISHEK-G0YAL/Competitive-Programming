/*
Can you code this challenge?

Title: Find the N-th Natural Number
Difficulty: Intermediate

The task is to find which natural number (or rather a digit between 0-9) is at the 1986th position. 
The number range is from 1 to 1000. 

Optionally find the number that the 0-9 digit is a part of.

Example:

Given number range from 1-20 (1234567891011121314151617181920) the digit at position 17 
would be '3' and it is a part of number '13'.
*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i,n,num,rev=0,x=0;
	printf("Enter the position of the digit you want to find\n");
	scanf("%d",&n);
	int dig[n];
	for(i=1;i<=n;i++)
	{
		num=(i*10)+1;
		while(num>0)
		{
			rev=(rev*10)+(num%10);
			num=num/10;
		}
		while(rev>1)
		{
			dig[x]=rev%10;
			rev=rev/10;
			++x;
			if(x==n)
			break;
		}
		rev=0;
		if(x==n)
		break;
	}
	printf("The digit at the position %d is %d\n",n,dig[n-1]);
	printf("Also the digit %d is part of number %d",dig[n-1],i);
}