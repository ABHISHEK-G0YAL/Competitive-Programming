#include <stdio.h>
#include <math.h>
int main()
{
	int i,n,s=0,t,t1;
	scanf("%d",&t1);
	while(t1--)
	{
		s=0;
		scanf("%i",&n);
		for(i=1;i<=sqrt(n);i++)
		{
			if(n % i == 0)
			{
				if(i % 2 == 1)
				s = s + i;
				t = n/i;
				if(t % 2 == 1 && t!=i)
				s=s+t;
			}
		}
		printf("%d\n",s);
	}
}
