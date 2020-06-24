#include <bits/stdc++.h>
using namespace std;
bool contains(string a,string b)
{
    int i=0,j=0;
    while(true)
    {
        if(i>a.length()-1)
            return true;
        else if(j>b.length()-1)
            return false;
        else if(a[i]==b[j])
            ++i && ++j;
        else if(i==0)
            ++j;
        else
            i=0;
    }
}

int main() {
    string a,b;
    while(cin>>a>>b)
        cout<<contains(a,b)<<endl;
    return 0;
}
