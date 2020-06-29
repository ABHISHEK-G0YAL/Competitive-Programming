// https://www.codechef.com/JUNE19A/problems/SNCK99/
// 0.204 submission max is 1.00

#include <bits/stdc++.h>
using namespace std;

random_device rd;
mt19937_64 eng(rd());
uniform_int_distribution<char> distr;

bool randomBool() {
    return distr(eng)<64;
}

int main() {
    int n,m,x;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>x;
    for(int i=0;i<m;i++) cin>>x;
    for(int i=0;i<m;i++) cin>>x>>x;
    cout<<-1<<endl;
    for(int i=0;i<n;i++) cout<<(randomBool()?'G':'C');
    cout<<endl;
}

// old
// #include <iostream>
// using namespace std;

// int main() {
//     int n,m,x;
//     cin>>n>>m;
//     for(int i=0;i<n;i++) cin>>x;
//     for(int i=0;i<m;i++) cin>>x;
//     for(int i=0;i<m;i++) cin>>x>>x;
//     cout<<-1<<endl;
//     for(int i=0;i<n;i++) cout<<((i%4<2)?'G':'C');
//     cout<<endl;
// }