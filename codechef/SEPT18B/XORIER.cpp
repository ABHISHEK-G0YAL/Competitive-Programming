#include <bits/stdc++.h> 
#define MAX 1000001
using namespace std;

int arr[MAX]={0};

long long choose2(long long x){
    return (x*(x-1))/2;
}

main()
{
    int t,n,x;
    long long zeroes=0,ones=0,ans;
    cin>>t;
    while(t--){
        cin>>n;
        while(n--){
            cin>>x;
            ++arr[x];
            if(x & 1)
                ++ones;
            else
                ++zeroes;
        }
        ans=choose2(ones) + choose2(zeroes);
        for(int i = 1; i < MAX; i++) {
            ans-=choose2(arr[i]);                       //  subtract pairs which xor to 0 and
            if((i^2)>i)                                 //  subtract pairs which xor to 2 as,
                ans-=(arr[i]*arr[i^2]);                 //  0 & 2 can't be sum of any two prime numbers.
        }
        cout<<ans<<endl;    
        memset(arr, 0, sizeof(arr));
        zeroes=0;
        ones=0;
    }
    return 0;
}