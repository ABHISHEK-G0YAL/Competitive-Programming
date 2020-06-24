#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,x,count=0;
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            if(x%m==0)
                ++count;
        }
        cout<<int(pow(2,count)-1)<<endl;
    }
    return 0;
}

// Old Version

// #include <bits/stdc++.h>
// using namespace std;

// int Count;

// void nGoodSubSeq(int a[],int m,int &maxSum,int i=0,int sum=0)
// {
//     //cout<<sum<<endl;
//     if(i==1001)
//     {
//         if(sum%m==0 && sum!=0 && sum!=maxSum)
//             ++Count;
//     }
//     else
//     {
//         for(int b=0;b<=a[i];b++)
//             nGoodSubSeq(a,m,maxSum,i+1,sum+(b*i));
//     }
// }
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         int n,m,x,maxSum=0;
//         cin>>n>>m;
//         int a[1001]={0};
//         for(int i=0;i<n;i++)
//         {
//             cin>>x;
//             maxSum+=x;
//             ++a[x];
//         }
//         Count=0;
//         nGoodSubSeq(a,m,maxSum);
//         cout<<Count<<endl;
//     }
//     return 0;
// }

// Older Version

// #include <bits/stdc++.h>
// using namespace std;

// int Count;

// void nGoodSubSeq(int a[],int n,int m,int sum=0)
// {
//     //cout<<sum<<endl;
//     if(n==0)
//     {
//         if(sum%m==0 && sum!=0)
//             ++Count;
//     }
//     else
//     {
//         nGoodSubSeq(a+1,n-1,m,sum);
//         nGoodSubSeq(a+1,n-1,m,sum+a[0]);
//     }
// }
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         int n,m;
//         cin>>n>>m;
//         int a[n];
//         int totalSum=0;
//         for(int i=0;i<n;i++)
//         {
//             cin>>a[i];
//             totalSum+=a[i];
//         }
//         if(totalSum%m==0)
//             Count=-1;
//         else
//             Count=0;
//         nGoodSubSeq(a,n,m);
//         cout<<Count<<endl;
//     }
//     return 0;
// }