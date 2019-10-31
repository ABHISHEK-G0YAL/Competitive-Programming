#include <bits/stdc++.h>
#define MAX 200
using namespace std;

int main() {
    bool prime[MAX]={0};
    bool semiprime[MAX*MAX]={0};
    vector<int> primes;
    vector<int> semiprimes;
    for(int i=2;i<sqrt(MAX);i++) {
        if(!prime[i]) {
            for(int j=2;i*j<MAX;j++)
                prime[i*j]=1;
        }
    }
    for(int i=2;i<MAX;i++)
        if(!prime[i])
            primes.push_back(i);
    for(int i=0;i<primes.size();i++)
        for(int j=i+1;j<primes.size();j++)
            semiprime[primes[i]*primes[j]]=true;
    for(int i=0;i<MAX*MAX;i++)
        if(semiprime[i])
            semiprimes.push_back(i);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        bool ans=false;
        for(int i=0;i<semiprimes.size();i++) {
            if(n>semiprimes[i] && semiprime[n-semiprimes[i]]) {
                ans=true;
                break;
            }
        }
        if(ans)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
} 
