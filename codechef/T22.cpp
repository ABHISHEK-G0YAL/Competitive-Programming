// https://www.codechef.com/problems/T22

#include <iostream>
using namespace std;

int main()
{
    int primes[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    bool sieve[101]={false};
    for(int i=0;i<25;i++)
        sieve[primes[i]]=true;
    int t;
    cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int a[n],min=10001,minp=10001;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]<min)
                min=a[i];
            if(sieve[a[i]] && a[i]<minp)
                minp=a[i];
        }
        if(min==1 && minp!=10001)
            cout<<minp<<endl;
        else
            cout<<"-1"<<endl;
    }
}