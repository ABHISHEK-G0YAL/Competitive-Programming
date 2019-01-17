#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int t,n,m;
	cin>>t;
	while(t--)
	{
		vector <int> indexes;
		cin >> n >> m;
		int chef[n]={};
		//for(int i=0;i<n;i++)
		//	cout<<chef[i];
		int pairs[m][2];
		for(int i=0;i<m;i++)
			cin>>pairs[i][0]>>pairs[i][1];
		for(int i=m-1;i>=0;i--)
		{
			if(chef[pairs[i][0]]==0 && chef[pairs[i][1]]==0)
			{
				indexes.push_back(i);
				chef[pairs[i][0]]=1;
				chef[pairs[i][1]]=1;
			}
		}
		for(int i=indexes.size()-1;i>=0;i--)
			cout<<indexes[i]<<" ";
		cout<<endl;
	}
}
