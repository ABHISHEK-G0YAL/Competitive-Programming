// https://www.hackerrank.com/challenges/chocolate-feast/problem
// Accepted

#include <bits/stdc++.h>
using namespace std;

int chocolateFeast(int n, int c, int m) {
    int chocolates=n/c;
    int choco_offer=0;
    int wrapers=chocolates;
    while(wrapers>=m) {
        choco_offer+=(wrapers/m);
        wrapers%=m;
        wrapers+=choco_offer;
        chocolates+=choco_offer;
        choco_offer=0;
    } return chocolates;
}
int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    int t,n,c,m;
    cin>>t;
    while(t--) {
        cin>>n>>c>>m;
        int result=chocolateFeast(n,c,m);
        fout<<result<<"\n";
    }
    fout.close();
    return 0;
}
