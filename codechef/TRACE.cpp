#include <iostream>
using namespace std;

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int m[n][n];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin>>m[i][j];
        int sum[2*n-1]={};
        // for(int i = 0; i < 2*n-1; i++)
        //     cout<<sum[i]<<" ";
        for(int i = 0; i < n; i++)
        {
            int x=i,y=0;
            while(x<n && y<n)
            {
                sum[n-1-i]+=m[x][y];
                if(i!=0)
                    sum[n-1+i]+=m[y][x];
                ++x;
                ++y;
            }
        }
        int max=0;
        for(int i = 0; i < 2*n-1; i++)
            if(sum[i]>max)
                max=sum[i];
        cout<<max<<endl;
    }
    return 0;
}