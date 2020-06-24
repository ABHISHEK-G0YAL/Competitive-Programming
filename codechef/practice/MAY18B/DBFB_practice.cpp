#include <iostream>
using namespace std;
int main()
{
	const int mod =1000000007;
	long long fib[100000],result;
	fib[0]=0;
	fib[1]=1;
	for(int i=2;i<100000;i++)
		fib[i]=(fib[i-1]+fib[i-2])%mod;
	long long t,m,n;
	cin>>t;
	while(t--)
	{
		cin>>m>>n;
		long long a[m],b[m];
		long long a_sum=0,b_sum=0;
		for(int i=0;i<m;i++)
			cin>>a[i];
		for(int i=0;i<m;i++)
			cin>>b[i];
		for(int i=0;i<m;i++)
			a_sum=(a_sum+a[i])%mod;
		for(int i=0;i<m;i++)
			b_sum=(b_sum+b[i])%mod;
		result=((fib[n-2]*a_sum)%mod+(fib[n-1]*b_sum)%mod)%mod;
		cout<<(result*m)%mod<<endl;
	}
}