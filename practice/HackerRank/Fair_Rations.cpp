// https://www.hackerrank.com/challenges/fair-rations/problem
// Accepted

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the fairRations function below.
void fairRations(vector<int> b)
{
    int count=0,i;
    for(i=0;i<b.size()-1;i++)
    {
        if(b[i]%2==0)
            continue;
        b[i]+=1;
        b[i+1]+=1;
        count+=2;
    }
    if(b[i]%2==0)
        cout<<count;
    else
        cout<<"NO";
}

int main()
{
    int n;
    cin>>n;
    vector<int> b(n);
    for(int i=0;i<n;i++)
        cin>>b[i];
    fairRations(b);
    return 0;
}
    
