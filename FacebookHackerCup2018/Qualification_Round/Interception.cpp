#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int x=1;x<=t;x++)
	{
        int n,coff;
		cin>>n;
		for(int i=0;i<=n;i++)
			cin>>coff;
		if(n%2==0)
			cout<<"Case #"<<x<<": 0"<<endl;
		else
			cout<<"Case #"<<x<<": 1\n0.0"<<endl;
	}
	return 0;
}