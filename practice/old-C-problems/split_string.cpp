#include<bits/stdc++.h>
using namespace std;

// splits string to vector of words
int split(string &str, vector<string> &strs)
{
    size_t pos = str.find(' ');
    size_t initialPos = 0;
    strs.clear();

    while( pos != string::npos ) {
        strs.push_back( str.substr( initialPos, pos - initialPos ) );
        initialPos = pos + 1;
        pos = str.find( ' ', initialPos );
    }
    strs.push_back( str.substr( initialPos, min( pos, str.size() ) - initialPos + 1 ) );
}

int main()
{
    vector<string> v;
    string str= "This is a test";
    cout<<str<<endl;
    split(str , v);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<endl;

    return 0;
}