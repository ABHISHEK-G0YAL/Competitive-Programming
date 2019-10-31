#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n],b[n][n];
        for(int i = 0; i < n; i++)
        cin>>a[i];
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                b[i][((i*n)+j)%n]=a[i]+a[j];
            }
        }
    }
    return 0;
}