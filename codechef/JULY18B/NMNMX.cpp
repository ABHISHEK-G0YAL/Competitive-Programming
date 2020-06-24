#include <iostream>
#include <algorithm>
#define mod 1000000007
#define mod1 1000000006
#define nMAX 5001
#define ull unsigned long long
#define ui unsigned int
using namespace std;


ull C[nMAX][nMAX]={};

ui pow(ull x,ui y)
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

void constructPascalTriangle()
{
    for (ui i=0;i<nMAX;i++)
    {
        for (ui j=0;j<=i;j++)
        {
            if (j==0 || j==i)
                C[i][j] = 1;
            else
                C[i][j] = (C[i-1][j-1] + C[i-1][j])%mod1;
        }
    }
}

int main()
{
    constructPascalTriangle();
    // cout<<C[50][25];
    // for (ui i=0;i<11;i++){
    //     for (ui j=0;j<=i;j++)
    //         cout<<C[i][j]<<" ";cout<<endl;}
    ui t;
    cin>>t;
    while(t--)
    {
        ui n,k;
        cin>>n>>k;
        ui a[n];
        ui p[n]={};
        for(ui i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        ull product=1;
        for(ui i=1;i<=(n-1)/2;i++)
        {
        	ui power=0;
            for(ui j=1;j<=min(k-2,i);j++)
                power=(power  +  (C[i][j] * C[n-1-i][k-1-j]) % mod1)%mod1;
            // cout<<a[i]<<" : "<<power<<endl;
            // if(n-1-i != i)
            //     cout<<a[n-1-i]<<" : "<<power<<endl;
            product=(product*pow(a[i],power))%mod;
            if(n-1-i != i)
            	product=(product*pow(a[n-1-i],power))%mod;
        }
        cout<<product<<endl;
    }
}
// Older Version (20 points)

//     while(t--)
//     {
//         ui n,k;
//         cin>>n>>k;
//         ui a[n];
//         ui p[n]={};
//         for(ui i=0;i<n;i++)
//             cin>>a[i];
//         sort(a,a+n);
//         ui min=0,max=k-1,e=k-3,r=k-3,maxMin=n-k;
//         while(min<=maxMin)
//         {
//             // uul power=C[e][r];
//             // cout<<power<<endl;
//             for(ui i=min+1;i<max;i++)
//                 p[i]=(p[i]+C[e][r])%mod1;
//             ++max;
//             ++e;
//             if(max==n)
//             {
//                 ++min;
//                 max=min+k-1;
//                 e=k-3;
//             }
//         }
//         // for(ui i=0;i<n;i++)
//         //     if(p[i]!=0)
//         //         cout<<a[i]<<" : "<<p[i]<<endl;
//         ull product=1;
//         for(ui i=0;i<n;i++)
//             if(p[i]!=0)
//                 product=(product*pow(a[i],p[i]))%mod;
//         cout<<product<<endl;
//     }