#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int power(ll b,int p)
{
	if(p==0)return 1;
	if(p%2==0)
		return power((b*b)%mod,p/2);
	else
		return ((b%mod)*(power((b*b)%mod,p/2)%mod))%mod;
}

int main()
{
	int test,n,count,i;
	cin>>test;
	char inp[3][1000];
	int k=1;
	while(test--)
	{
		count=0;cin>>n;
		for( i=0;i<3;i++)
			for(int j=0;j<n;j++)
				cin>>inp[i][j];
		if(n%2!=0 || inp[0][0]=='#' || inp[2][n-1]=='#' || inp[1][0]=='#' || inp[1][n-1]=='#')
		{
			cout<<"Case #"<<k<<": "<<0<<endl;
			k++;continue;
		}
		for( i=1;i<n-1;i+=2)
		{
			if((inp[0][i]=='#' && inp[2][i]=='#')||(inp[0][i]=='#' && inp[2][i+1]=='#')||(inp[0][i+1]=='#' && inp[2][i]=='#')||(inp[0][i+1]=='#' && inp[2][i+1]=='#')||(inp[1][i]=='#' || inp[1][i+1]=='#'))
			{
				cout<<"Case #"<<k<<": "<<0<<endl;
				k++;
				break;
			}
			if(inp[0][i]=='.' && inp[2][i]=='.' && inp[0][i+1]=='.' && inp[2][i+1]=='.')
				count++;
		}
		if((inp[0][i]=='#' && inp[2][i]=='#')||(inp[0][i]=='#' && inp[2][i+1]=='#')||(inp[0][i+1]=='#' && inp[2][i]=='#')||(inp[0][i+1]=='#' && inp[2][i+1]=='#')||(inp[1][i]=='#' || inp[1][i+1]=='#'))
		{
			continue;
		}
		int ans=power(2,count);
		cout<<"Case #"<<k<<": "<<ans<<endl;
		k++;
	}
	return 0;
}
