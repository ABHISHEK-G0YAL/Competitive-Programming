#include <bits/stdc++.h>
using namespace std;
void weirdSubtraction(long long a,long long b)
{
	if(a==0 || b==0)
	cout<<a<<' '<<b;
	else if(a>=(2*b))
	weirdSubtraction(a%(2*b),b);
	else if(b>=(2*a))
	weirdSubtraction(a,b%(2*a));
	else
	cout<<a<<' '<<b;
}
int main()
{
	long long a,b;
	cin>>a>>b;
	weirdSubtraction(a,b);
}