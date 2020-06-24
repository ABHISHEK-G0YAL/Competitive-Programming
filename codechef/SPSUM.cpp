#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n,m,sum=0,x,y;
		cin>>n>>m;
		sum=n*(n+1)/2;
		if((sum+m)%2==0)
		{
			x=(sum+m)/2;
			y=sum-x;
			if(y<0 || __gcd(x,y)!=1)
				cout<<"No"<<endl;
			else
				cout<<"Yes"<<endl;
		}
		else
			cout<<"No"<<endl;
	}
	return 0;
} 
