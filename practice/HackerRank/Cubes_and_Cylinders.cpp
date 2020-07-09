// https://www.hackerrank.com/contests/university-codesprint-4/challenges/cubes-and-cylinders/problem
// Wrong Answer

#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int i,j,n,m,count=0;
	cin >> n >> m;
	int s[n],k[n],r[m],c[m];
	for(i=0;i<n;i++)
		cin>>s[i];
	for(i=0;i<n;i++)
		cin>>k[i];
	for(i=0;i<m;i++)
		cin>>r[i];
	for(i=0;i<m;i++)
		cin>>c[i];
	i=-1;I:++i;if(i>=n) goto exit;
	j=-1;J:++j;if(j>=m) goto I;
	if(s[i]<=1.41421356237F*r[j] && c[j]!=0)
	{
		while(k[i]!=0 && c[j]!=0)
		{  
			k[i]=k[i]-1;
			c[j]=c[j]-1;
			++count;   
		}   
	}
	if(k[i]==0 && c[j]==0)
	goto I;
	if(k[i]==0)
	goto I;
	if(c[j]==0)
	goto J;
	exit:;
	cout<<count;
	return 0;
}	
