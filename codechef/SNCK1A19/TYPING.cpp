// By Bansal
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{  int p;
		int sum=0,sum1;
		int n;
		cin>>n;
		string s[n];
		for(int i=0;i<n;i++)
		{  sum=sum+2;
		p=0; 
		cin>>s[i];
		sum1=2;
		    for(int k=i-1;k>=0;k--)
		    {
		    	if(s[i]==s[k])
		    	{   
		    		p++;
		    		goto label;
				}
			}
			label:;
			for(int j=1;j<s[i].length();j++)
			{
			
					if(s[i][j]=='d'||s[i][j]=='f')
					{
						if(s[i][j-1]=='d'||s[i][j-1]=='f')
						{
							sum=sum+4;
							sum1=sum1+4;
						}
						else 
						{
							
						
						sum=sum+2;
						sum1=sum1+2;
					}
				}
					if(s[i][j]=='j'||s[i][j]=='k')
					{
						if(s[i][j-1]=='j'||s[i][j-1]=='k')
						{
							sum=sum+4;
							sum1=sum1+4;
						}
						else 
						{
							
						
						sum=sum+2;
						sum1=sum1+2;
					}
					}
				}
				if(p==1)
				{
					sum=sum-(0.5*sum1);
				}
				
			}
			
	
		cout<<sum<<"\n";
		
		
	}

	return 0;
} 
