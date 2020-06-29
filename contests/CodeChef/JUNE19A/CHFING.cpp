// https://www.codechef.com/JUNE19A/problems/CHFING

#include <iostream>
#define ull unsigned long long
#define mod 1000000007
using namespace std;

ull getUnreachableVals(ull n,ull k) {
    ull decFactor=n-1;
    ull lastTerm=k>n?k-n:0;
    ull nTerms=lastTerm/decFactor+1;
    ull decAmt=decFactor*(nTerms-1);
    ull firstTerm=lastTerm-decAmt;
    ull firstLast=firstTerm+lastTerm;
    if(firstLast%2) nTerms/=2;
    else firstLast/=2;
    ull sumAP=((firstLast%mod)*(nTerms%mod))%mod;
    return (k-1+sumAP)%mod;
}
int main() {
    int t; cin>>t;
    while(t--) {
        ull n,k;
        cin>>n>>k;
        cout<<getUnreachableVals(n,k)<<endl;
    }
}