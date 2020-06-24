// https://www.spoj.com/problems/EXPECT/

#include <iostream>
using namespace std;

int main() {
	int x;
	cin>>x;
	if(x==42)
	{
		cout<<x<<endl;
		return 0;
	}
	cout<<x<<endl;
	main();
}