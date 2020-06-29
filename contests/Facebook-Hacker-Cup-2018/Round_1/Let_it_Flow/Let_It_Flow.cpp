// https://www.facebook.com/hackercup/problem/180494849326631/
// Incorrect Submission

#include <iostream>
#define ull unsigned long long
#define ui unsigned long long
#define mod 1000000007
using namespace std;

ui expo(ull x,ui y)
{
    ull res = 1;  
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % mod;
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % mod;
    }
    return res;
}

int main()
{
    int t;
    cin>>t;
    for(int x=1;x<=t;x++)
    {
        int n;
        cin>>n;
        char g[3][n];
        for(int i=0;i<3;i++)
            for(int j=0;j<n;j++)
                cin>>g[i][j];
        if(n%2==1 || g[0][0]=='#' || g[1][0]=='#' || g[1][n-1]=='#' || g[2][n-1]=='#')
        {
            cout<<"Case #"<<x<<": 0"<<endl;
            continue;
        }
        int power=0;
        bool flag=true;
        for(int j=1;j<n-1;j+=2)
        {
            bool obstacle1,obstacle3;
            if(g[1][j]=='#' || g[1][j+1]=='#')
            {
                cout<<"Case #"<<x<<": 0"<<endl;
                flag=false;
                break;
            }
            obstacle1 = g[0][j]=='#' || g[0][j+1]=='#';
            obstacle3 = g[2][j]=='#' || g[2][j+1]=='#';
            if(obstacle1 && obstacle3)
            {
                cout<<"Case #"<<x<<": 0"<<endl;
                flag=false;
                break;
            }
            if(!obstacle1 && !obstacle3) power+=1;
        }
        if(flag)
            cout<<"Case #"<<x<<": "<<expo(2,power)<<endl;
    }
    return 0;
}
