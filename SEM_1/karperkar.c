#include <stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	long int a,b,i,m,c,x,y;
	printf("please enter the range in which you want to print karpekar numbers\n");
	scanf("%ld%ld",&a,&b);
	printf("1\t");
	for(i=a;i<=b;i++)
	{
		for(c=1;c<log10(i*i)+1;c++)
		{
			x=(i*i)/pow(10,c);y=(i*i)%(long int)pow(10,c);
			m=x+y;
			if(m==i&&x>0&&y>0)
			printf("%ld \t",i);
		}
	}
}
/*
Can you code this challenge?

Title: Kaprekar numbers
Difficulty: Intermediate

In mathematics, a Kaprekar number for a given base is a 
non-negative integer, the representation of whose square 
in that base can be split into two parts that add up to 
the original number again. For instance, 45 is a Kaprekar 
number, because 452 = 2025 and 20+25 = 45. The Kaprekar 
numbers are named after D. R. Kaprekar. Your program will 
receive two integers per line telling you the start and 
end of the range to scan, inclusively. Example: '1 50'. 
Your program should emit the Kaprekar numbers in that range. 
From the example: 45 is the Kaprekar number in that range. 
For your program focus only on base 10 numbers. 

For added complexity, see if you can make it work in arbitrary bases.
*/
