#include<stdio.h>
#include<math.h>
int main()
{
	float x,s,n,e;
	e=2.71828183;
	for(x=2.4;x>=0;x=x-0.05)
	{
		for(s=0;s<pow(e,x);s=s+0.05)
		{
			printf(" ");
		}
		printf("*\n");
	}
return 0;
}
