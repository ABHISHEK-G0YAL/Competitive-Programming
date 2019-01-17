#include <iostream>
using namespace std;

bool chk(string a,string b)
{
    int al=a.length(),bl=b.length();
    for(int i=0;i<bl;i++)
        if(a[i%al]!=b[i])
            return true;
    return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int x=1;x<=t;x++)
    {
    	string a;
    	cin>>a;
        int i;
        bool value=false;
        for(i=1;i<a.length();i++)
        {
            if(a[i]==a[0])
            {
                value=chk(a.substr(0,i),a.substr(i));
                break;
            }
        }
        if(value)
            cout<<"Case #"<<x<<": "<<a.substr(0,i)+a<<endl;
        else
            cout<<"Case #"<<x<<": "<<"Impossible"<<endl;
	}
	
    return 0;
}