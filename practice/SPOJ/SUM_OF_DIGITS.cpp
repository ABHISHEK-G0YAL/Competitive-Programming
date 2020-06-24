// https://www.spoj.com/problems/ALCATRAZ1/

#include <iostream>
using namespace std;

int main() {
	int t,sum;
	string n;
	cin>>t;
	while(t--)
	{
		sum=0;
		cin>>n;
		for(int i=0;i<n.length();i++)
			sum+=n[i]-'0';
		cout<<sum<<endl;
	}
	return 0;
}