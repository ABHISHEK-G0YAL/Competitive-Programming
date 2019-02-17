// v3 accepted

#include <iostream>
using namespace std;

int main() {
    long long n,k;
    cin>>n>>k;
    cout<<max(0LL,(k-1)/2-max(0LL,k-n-1))<<endl;
}

// v1 accepted

// #include <iostream>
// using namespace std;

// int main() {
//     long long n,k;
//     cin>>n>>k;
//     if(k<=n)
//         cout<<(k-1)/2<<endl;
//     else
//         cout<<max(0LL,((k-1)/2)-(k-n-1))<<endl;
// }

// v0 accepted

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