// https://www.codechef.com/SNCK1B19/problems/SNCKYEAR/

// By Bansal
#include<iostream>
using namespace std;
int main()
{	int t;
	cin>>t;
	while(t--)
	{
		
		int N;
		cin>>N;
		if(N==2010||N==2015||N==2016||N==2017||N==2019)
			cout<<"HOSTED\n";
		else
		cout<<"NOT HOSTED\n";
		
	}
	return 0;
}