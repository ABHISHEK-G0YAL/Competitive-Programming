// https://www.codechef.com/ACMIND18/problems/ROBOGAME

#include<bits/stdc++.h> 
#define mod 1000000007
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        int n=s.length();
        bool p[n]={0};
        bool flag=true;
        for(int i=0;i<n;i++) {
            if(s[i]=='.')
                continue;
            else {
                int k=s[i]-'0';
                int l=(i-k>0)?i-k:0;
                int r=(i+k<n)?i+k:n-1;
                for(int j=l;j<=r;j++) {
                    if(!p[j])
                        p[j]=true;
                    else {
                        flag=false;
                        break;
                    }
                }
                if(!flag)
                    break;
            }
        }
        if(flag)
            cout<<"safe"<<endl;
        else
            cout<<"unsafe"<<endl;
    }
    return 0;
}