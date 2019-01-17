#include <iostream>
using namespace std;
int main()
{
	int t,n,a,b,freqA,freqB;
	double prob;
	cin>>t;
	while(t--)
	{
		freqA=0;
		freqB=0;
		cin>>n>>a>>b;
		int x[n];
		for(int i=0;i<n;i++)
		{
			cin>>x[i];
			if(x[i]==a)
				freqA++;
			if(x[i]==b)
				freqB++;
		}
		prob=(double)freqA*(double)freqB/(double)(n*n);
		cout<<fixed<<prob<<endl;
	}
}
