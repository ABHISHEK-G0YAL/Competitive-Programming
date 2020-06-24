// https://www.codechef.com/problems/SPAMCLAS

#include <bits/stdc++.h>
using namespace std;
int main()
{
	int i,t,n,minx,maxx,spammer,non_spammer,input;
	cin>>t;
	while(t--)
	{
		cin>>n>>minx>>maxx;
		int w[n],b[n];
		for(i=0;i<n;i++)
			cin>>w[i]>>b[i];
		int wnet=1,bnet=0;
		for(i=0;i<n;i++)
			wnet=wnet*w[i];
		for(i=0;i<n;i++)
			bnet=(bnet*w[i])+b[i];
		spammer=0;non_spammer=0;
		while(minx<=maxx)
		{
			input=minx;
				input=(input*wnet)+bnet;
			if(input%2==0)
				++non_spammer;
			else
				++spammer;
			++minx;
		}
		cout<<non_spammer<<" "<<spammer<<endl;
	}
}