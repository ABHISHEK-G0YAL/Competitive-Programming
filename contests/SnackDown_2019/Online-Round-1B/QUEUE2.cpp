// https://www.codechef.com/SNCK1B19/problems/QUEUE2/
// By Bansal

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int N,M,K,L,i,j,p;
	while(t--)
	{  long long min=100000000000;
		cin>>N>>M>>K>>L;
		long long a[N+1];
		long long b[N+1];
		for(i=0;i<N;i++)
		{
			cin>>a[i];
		}
		a[N]=K;
		sort(a,a+N+1);
		p=M;
		for(j=0;j<N+1;j++)
		{
			b[j]=p*L+L-a[j];
			p=p+1;
		}
		for(long int k=0;k<N+1;k++)
		{
			if(b[k]<min)
			{
				min=b[k];
				
			}
		}
		cout<<min<<"\n";		
	}
	return 0;
}