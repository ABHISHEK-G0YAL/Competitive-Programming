#include <stdio.h>
#include <math.h>
int main()
{
	int i,num,dig,c;char r[7]="IXCMVLD";
	printf("Enter the number b/w 1-4000 to be converted to Roman Numeral\n");
	scanf("%d",&num);
	num=(num>4000)?4000:num;
	while(num>0)
	{
		c=log10(num);
		dig=num/pow(10,c);
		if(dig<=3)
		{
			for(i=1;i<=dig;i++)
			printf("%c",r[c]);
		}
		else if(dig==4)
		printf("%c%c",r[c],r[c+4]);
		else if(dig<=8)
		{
			printf("%c",r[c+4]);
			for(i=6;i<=dig;i++)
			printf("%c",r[c]);
		}
		else if(dig==9)
		printf("%c%c",r[c],r[c+1]);
		num=num%(int)pow(10,c);
	}
}
/*
Can you code this challenge?

Title: Roman Number Generator
Difficulty: Intermediate

Develop a program that accepts an integer and outputs the Roman Number equivalent of that number.
numbers can be b/w 1 and 4000.

Examples:

4 - IV
12 - XII
20 - XX
*/
