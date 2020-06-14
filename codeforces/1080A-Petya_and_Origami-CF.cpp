#include <bits/stdc++.h>
using namespace std;

int main() {
    double n,k;
    cin>>n>>k;
    long long red=n*2,green=n*5,blue=n*8;
    cout<<(long long)(ceil(red/k)+ceil(green/k)+ceil(blue/k))<<endl;
}