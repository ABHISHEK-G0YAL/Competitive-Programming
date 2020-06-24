// https://www.codechef.com/SNCK1B19/problems/CHFAR/
// By Bansal

#include<iostream>
using namespace std;
int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int k,n,count=0,u;
		cin>>n>>k;
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			if(a[i]==1)
			{
				count++;
			}
		}
		if(count==n)
		{
			cout<<"YES\n";
			goto label;
		}
		else
		{
		  u=n-count;
		  if(k>=u)
		  {
		  	cout<<"YES\n";
		  }
		  else
		  {
		  	cout<<"NO\n";
		  }
		}
	  label:;		
	}
	
	return 0;
	
} 
