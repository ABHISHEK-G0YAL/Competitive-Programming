/*
Can you code this challenge?

Title: Pascal's Triangle
Difficulty: Intermediate

Create a program to print the Pascal's Triangle representation for a number N where N is an integer specified by the user.

For more info on Pascal's Triangle, look here: https://en.m.wikipedia.org/wiki/Pascal's_triangle
*/

#include <stdio.h>
int fact(int x)
{
	int i;long long int fac=1;
	for(i=2;i<=x;i++)
	fac=fac*i;
	return fac;
}
int main()
{
	printf("Enter the number of Row(s) for Pascal triangle\n");
	int r,n,s,N;
	scanf("%d",&N);
	for(n=0;n<N;n++)
	{
		for(s=1;s<N-n;s++)
		printf("    ");
		for(r=0;r<=n;r++)
		printf("%4d    ",fact(n)/(fact(r)*fact(n-r)));
		printf("\n");
	}
}