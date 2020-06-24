#include <iostream>
using namespace std;
 
int main() {
	// your code goes here
	long long t,i,n,q;
	cin>>t;
	while(t--)
	{
	    cin>>n>>q;
	    long long d[n],x[q];
	    for(i=0;i<n;i++)
	        cin>>d[i];
	    for(i=0;i<q;i++)
	        cin>>x[i];
	    long long dd=1;
	    for(i=0;i<n;i++)
	    	if(dd<1000000000)
	        	dd=dd*d[i];
	    for(i=0;i<q;i++)
	        cout<<x[i]/dd<<" ";
	    cout<<endl;
	}
	return 0;
}    
