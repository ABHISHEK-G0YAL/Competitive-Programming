// https://www.hackerrank.com/challenges/staircase/problem

#include <bits/stdc++.h>

using namespace std;

void staircase(int n) {
    // Complete this function
    for(int i=0;i<n;i++)
    {
        for(int s=1;s<n-i;s++)
            cout<<' ';
        for(int j=0;j<=i;j++)
            cout<<'#';
        cout<<'\n';
    }
}

int main() {
    int n;
    cin >> n;
    staircase(n);
    return 0;
}
