// https://www.hackerrank.com/challenges/30-running-time-and-complexity/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int chkprime(int p)
{
	int i=0,j;
    if(p%2==0 && p>2)
        return 0;
	for(j=3;j<=sqrt(p);j+=2)
	if(p%j==0 && ++i)
	break;
	return (i==0?(p==1?0:1):0);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(chkprime(n))
            printf("Prime\n");
        else
            printf("Not prime\n");
    }
    return 0;
}
