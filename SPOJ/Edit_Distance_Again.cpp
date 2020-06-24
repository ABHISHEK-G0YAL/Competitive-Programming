// https://www.spoj.com/problems/EDIT/

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string s;
	int c1,c2;
	while(cin>>s)
	{
		c1=0;
		c2=0;
		for(int i=0;i<s.length();i++)
		{
			if(i%2==0)
			{
				if(s[i]>90)
				++c1;
				else
				++c2;
			}
			else
			{
				if(s[i]>90)
				++c2;
				else
				++c1;
			}
		}
		cout<<min(c1,c2)<<endl;
	}
	return 0;
}