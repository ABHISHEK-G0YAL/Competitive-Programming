// https://www.codechef.com/problems/ZUBTRCNT

#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	for(int j=1;j<=t;j++)
	{
		int l,k,sum=0;
		cin >> l >> k;
		for(int i=l-k+1;i>0;i--)
			sum=sum+i;
		cout<<"Case "<<j<<": "<<sum<<endl;
	}
}