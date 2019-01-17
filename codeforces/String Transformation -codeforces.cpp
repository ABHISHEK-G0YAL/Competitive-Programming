#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s; int count=0; char search='z';
	cin >> s;
	for(int i=s.length()-1;i>=0;i--)
	{
		if(s[i]<=search && search>='a'){
			s[i]=search;
			--search;
			++count;
		}
	}
	if(count==26)
	cout << s;
	else
	cout << -1;
}
