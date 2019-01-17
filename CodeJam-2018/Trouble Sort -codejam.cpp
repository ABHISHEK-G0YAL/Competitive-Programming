#include <bits/stdc++.h>
using namespace std;
#define swap(a,b) {int temp; temp=a; a=b; b=temp;}

void fastscan(int &number)
{
    bool negative = false;
    register int c;
    number = 0;
    c = getchar();
    if (c=='-')
    {
        negative = true;
        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
    if (negative)
        number *= -1;
}
int main()
{
    int t,n;
    fastscan(t);
    for(int x=1;x<=t;x++)
    {
    	fastscan(n);
    	int v[n];
    	for(int i=0;i<n;i++)
    		fastscan(v[i]);
    	for(int i=0;i<n;i++)
    	{
    		bool flag=true;
    		for(int j=0;j<n-2;j++)
    		{
    			if(v[j]>v[j+2])
    			{
    				swap(v[j],v[j+2])
    				flag=false;
				}
			}
			if(flag)
			break;
		}
		int i;
    	for(i=0;i<n-1;i++)
    	{
    		if(v[i]>v[i+1])
    		{
    			cout<<"Case #"<<x<<": "<<i<<endl;
    			break;
			}
		}
    	if(i>=n-1)
    		cout<<"Case #"<<x<<": OK"<<endl;
	}
    return 0;
}
