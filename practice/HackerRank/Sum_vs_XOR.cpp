// https://www.hackerrank.com/challenges/sum-vs-xor/problem
// Accepted

#include <bits/stdc++.h>
using namespace std;
int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    long n,result=0; cin>>n;
    while(n) {
        if(!(n&1)) result+=1;
        n=n>>1;
    } fout<<(1L<<result)<<endl;
    fout.close();
    return 0;
}
