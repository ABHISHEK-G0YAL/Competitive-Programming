#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int fact(int x)
{
	int i;int fac=1;
	for(i=2;i<=x;i++)
	fac=fac*i;
	return fac;
}
int main()
{
    int n,t,i,j,chk,p=0,k;
    scanf("%d%d",&n,&t);
    if(n>2)
    {
    int l=(fact(n))/(fact(2)*fact(n-2));
    int a[n];int b[l];
    for(i=0;i<l;i++)
        b[i]=t;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            chk=a[i]+a[j];
            for(k=0;k<t;k++)
            {
                if(chk % 10==0)
                    b[p]=b[p]-1;
                chk=chk/10;
            }
            ++p;
        }
    }
    int largest=b[0];
    for(i=0;i<l;i++)
    {
        if (largest < b[i])
            largest = b[i];
    }
    int count=0;
    for(i=0;i<l;i++)
    {
        if (largest == b[i])
            ++count;
    }
    printf("%d\n%d",largest,count);
    return 0;
    }
}
