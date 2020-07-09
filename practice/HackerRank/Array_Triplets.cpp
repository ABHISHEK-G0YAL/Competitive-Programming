// https://www.hackerrank.com/contests/university-codesprint-5/challenges/array-triplets/problem
// Terminated due to timeout

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

void allSubsets(int n,vector<int> &a,ll &sm,vector<int> &powerset,int set=0){
    if(n==0) {
        if(set!=0) {
            ll sum=0;
            for(int i=0;i<a.size();i++)
                if((set & (1<<i)) != 0)
                    sum+=a[i];
            if(sum == sm)
                powerset.pb(set);
        }
        return;
    }
    allSubsets(n-1,a,sm,powerset,set);
    allSubsets(n-1,a,sm,powerset,set+(1<<(n-1)));
}

// Complete the solve function below.
int solve(vector<int> a){
    ll n=a.size(),sm=0,triplets=0;
    for(int i=0;i<n;i++)
        sm+=a[i];
    if(sm % 3 == 0)
        sm/=3;
    else
        return 0;
    vector<int> powerset;
    allSubsets(n,a,sm,powerset);
    for(auto i=powerset.begin();i!=powerset.end();i++)
        for(auto j=i+1;j!=powerset.end();j++)
            if(((*i)&(*j))==0)
                triplets+=2;
    return triplets;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ofstream fout(getenv("OUTPUT_PATH"));
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin>>a[i];
    int result = solve(a);
    fout << result << "\n";
    fout.close();

    return 0;
}
