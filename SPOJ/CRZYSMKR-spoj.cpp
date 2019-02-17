#include <iostream>
using namespace std;

int main() {
	int t;
	long long n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<(11-(8*(n%11))%11)%11<<endl;
	}
	return 0;
}