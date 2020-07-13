// https://www.hackerrank.com/challenges/variable-sized-arrays/problem

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,q,x,i,j;
    cin>>n>>q;
    int **varr=new int*[n];
    for(i=0;i<n;i++) {
        cin>>x;
        *(varr+i)=new int[x];
        for(j=0;j<x;j++)
            cin>>*(*(varr+i)+j);
    }
    for(x=0;x<q;x++) {
        cin>>i>>j;
        cout<<*(*(varr+i)+j)<<endl;
    }
    return 0;
}

