// https://www.hackerrank.com/challenges/password-cracker/problem
// Processed

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
using namespace std;

bool comprator (string a ,string b, string c) {
    return (a.length() > b.length());
}

int main() { 
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int spaces[2010]={0};
        vector<pair<int,string> > a(n);
        string loginA;
        for(int i=0;i<n;i++) {
            cin>>a[i].second;
            a[i].first=a[i].second.length();
        }
        cin>>loginA;
        sort(a.rbegin(),a.rend());
        string chk=loginA;
        int i=0,j=0;
        while(i<n) {
            int x=chk.find(a[i].second);
            if(x<chk.length() && x>=0) {
                spaces[j]=x;
                ++j;
                for(int k=0;k<a[i].second.length();k++)
                    chk[k+x]='1';
            }
            else
                ++i;
        }
        int size=j;
        bool flag=true;
        sort(spaces,spaces+size);
        for(int i=0;i<chk.length();i++)
            if(chk[i]!='1')
                flag=false;
        if(flag) {
            j=1;
            for(int i=0;i<loginA.length();i++) {
                if(i==spaces[j] && j<size) {
                    ++j;
                    cout<<" ";
                }
                cout<<loginA[i];
            }
            cout<<endl;
        }
        else
            cout<<"WRONG PASSWORD"<<endl;
    }
    return 0;
}
