// https://www.hackerrank.com/challenges/3d-surface-area/problem

#include <bits/stdc++.h>

using namespace std;
int f(int x)
{
    if(x>0)
        return x;
    else
        return 0;
}
int main() {
    int H,W;
    cin >> H >> W;
    int area=2*H*W;
    int a[H][W];
    for(int i=0;i<H;i++)
        for(int j=0;j<W;j++)
            cin>>a[i][j];
    for(int i=0;i<H;i++)
        for(int j=0;j<W;j++)
            area=area + f(a[i][j]-((i==0)?0:a[i-1][j])) + f(a[i][j]-((j==0)?0:a[i][j-1])) + f(a[i][j]-((i+1==H)?0:a[i+1][j])) + f(a[i][j]-((j+1==W)?0:a[i][j+1]));
    cout << area << endl;
    return 0;
}
