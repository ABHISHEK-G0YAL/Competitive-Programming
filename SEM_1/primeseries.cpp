#include <iostream>
using namespace std;
int main()
{
	int n,i,j,f;
	f=0;
	cin>>n;
	for(i=2;i<=n;i++)
	{
		for(j=2;j<i;j++)
		if(i%j==0)
		f=1;
		if(f==0)
		cout<<j<<"\t";
		f=0;
	}
}
