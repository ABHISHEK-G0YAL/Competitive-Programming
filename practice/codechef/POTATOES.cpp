// https://www.codechef.com/problems/POTATOES

#include <iostream>
#include <math.h>

using namespace std;

bool prime(int x)
{
	if(x%2==0)
	return false;
	for(int i=3;i<=sqrt(x);i+=2)
	if(x%i==0)
	return false;
	return true;
}
int main()
{
	int t,a,b,c;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		for(c=1;;c++)
		{
			if(prime(a+b+c))
			{
				cout<<c<<endl;
				break;
			}
		}
	}
}