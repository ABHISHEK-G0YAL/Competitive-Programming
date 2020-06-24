// http://codeforces.com/contest/1223/problem/B

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while( t-- )
	{
		string a, b;
		cin >> a >> b;
		bool present1[26], present2[26];
		for(int i = 0 ; i < 26; i++)
		{
			present1[i] = false;
			present2[i] = false;
		}
		for(int i = 0 ; i < a.size(); i++)
		{
			int index1 = a[i] - 'a';
			int index2 = b[i] - 'a';
			present1[index1] = true;
			present2[index2] = true;
		}
		int i;
		for( i = 0 ; i < 26 ; i++)
		{
			if( present1[i] && present2[i] )
			{
				cout << "YES" << endl;
				break;
			}
		}
		if(i == 26)
			cout << "NO" << endl;
	}
}