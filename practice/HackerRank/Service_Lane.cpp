// https://www.hackerrank.com/challenges/service-lane/problem
// Accepted

#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n,t,i,j,min;
    cin>>n>>t;
    int width[n];
    for(int i=0;i<n;i++)
        cin>>width[i];
    while(t--)
    {
        cin>>i>>j;
        min=width[j];
        for(int a=i;a<j;a++)
            if(width[a]<min)
                min=width[a];
        cout<<min<<endl;
    }
    
}

