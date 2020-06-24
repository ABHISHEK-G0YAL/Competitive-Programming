// http://codeforces.com/contest/1228/problem/A

#include<bits/stdc++.h>
using namespace std;

bool isUnique(int x)
{
	bool present[10];
	for(int i = 0 ; i < 10 ; i++)
	{
		present[i] = false;
	}
	while(x>0)
	{
		int digit = x%10;
		if( present[digit] )
		{
			return false;
		}
		present[digit] = true;
		x = x/10;
	}
	return true;
}

int main()
{
	int l, r;
	cin >> l >> r;
	int x = l;
	while( x <= r )
	{
		if( isUnique(x) )
		{
			cout << x << endl;
			return 0;
		}
		x++;
	}
	cout << -1 << endl;
	return 0;
}