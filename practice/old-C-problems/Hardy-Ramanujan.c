/*
Can you code this challenge?

Title: Hardy-Ramanujan Number
Difficulty: Intermediate

1729 is a Hardy-Ramanujan number. It is the smallest number 
representable in two ways as a sum of two cubes.

        1729 = 12^3 + 1^3
        Also, 1729 = 10^3+9^3

Your program should generate all numbers between 1 and n that 
can be expressed as the sum of two cubes in two or more ways.
*/

#include <stdio.h>
#include <math.h>
int main()
{
	int n,i,j,k,c=0;
	printf("Enter the number till which you want to print Hardy-Ramanujan Number\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=pow(i,1.0/3.0);j++)
		{
			for(k=j;k<=pow(i,1.0/3.0);k++)
			{
				if(pow(j,3)+pow(k,3)==i)
				++c;
			}
		}
		if(c>=2)
		printf("%d\t",i);
		c=0;
	}
}