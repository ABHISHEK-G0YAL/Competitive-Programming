#include <stdio.h>
int main()
{
	int a[]={0,1,2,3,4};
	int *p[]={a,a+1,a+2,a+3,a+4};
	printf("%u %u %d\n",p,*p,*(*p));
	return 0;
}
