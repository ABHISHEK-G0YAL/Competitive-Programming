// http://codeforces.com/contest/1023/problem/B

#include <iostream>
using namespace std;
 
int main() {
    long long n,k;
    cin>>n>>k;
    cout<<max(0LL,(k-1)/2-max(0LL,k-n-1))<<endl;
}

// old accepted

// #include <iostream>
// using namespace std;

// int main() {
//     long long n,k;
//     cin>>n>>k;
//     if(k<=n)
//         cout<<(k-1)/2<<endl;
//     else
//         cout<<max(0LL,((k+1)/2)-(k-n))<<endl;
// }