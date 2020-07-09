// https://www.hackerrank.com/challenges/lonely-integer/problem
// Accepted

#include <bits/stdc++.h>
using namespace std;

template <class type>
type input() {
    type x;
    cin>>x;
    return x;
}
int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    int n,a=0; cin>>n;
    while(n--) a^=input<int>();
    fout<<a<<endl;
    fout.close();
    return 0;
}
