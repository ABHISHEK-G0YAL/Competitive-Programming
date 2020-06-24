// https://codingcompetitions.withgoogle.com/codejam/round/00000000000000cb/00000000000079cb

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
    	int ve[(n+1)/2],vo[n/2];
    	for(int i=0;i<n;i++)
    	{
    	    if(i%2)
    		    fastscan(vo[i/2]);
            else
                fastscan(ve[i/2]);
    	}
    	sort(ve,ve+(n+1)/2);
    	sort(vo,vo+n/2);
		int i,v1,v2;
    	for(i=0;i<n-1;i++)
    	{
    	    if(i%2) {
    	        v1 = vo[i/2];
    	        v2 = ve[(i+1)/2];
    	    }
            else {
    	        v1 = ve[i/2];
    	        v2 = vo[(i+1)/2];
    	    }
    		if(v1>v2)
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