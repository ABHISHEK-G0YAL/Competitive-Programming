// https://www.codechef.com/OCT18B/problems/BBRICKS
// wrong answer

#include<bits/stdc++.h> 
#define mod 1000000007
using namespace std; 

int nCrModp(int n, int r, int p) {
    int C[r+1]={}; 
    C[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = min(i, r); j > 0; j--)
            C[j] = (C[j] + C[j-1])%p; 
    } 
    return C[r]; 
}
  
// Driver program 
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        if(k>n)
            cout<<0<<endl;
        else
            cout<<nCrModp(2*n,k,mod)-(((3*n)-2)*nCrModp((2*n)-2,k-2,mod))<<endl;
    }
}