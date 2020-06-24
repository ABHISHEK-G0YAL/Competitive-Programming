// https://www.codechef.com/problems/JOHNY

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int t,k,n,f;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<int> song_lengths(n);
		for(int i=0;i<n;i++)
			cin>>song_lengths[i];
		cin>>k;
		f=song_lengths[k-1];
		sort(song_lengths.begin(),song_lengths.end());
		for(int i=0;i<n;i++)
		{
			if(song_lengths[i]==f)
			{
				cout<<i+1<<endl;
				break;
			}
		}
	}
}