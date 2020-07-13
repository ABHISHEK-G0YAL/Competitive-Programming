// https://www.hackerrank.com/challenges/minimum-distances/problem

#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    int n,x;
    cin >> n;
    vector<vector<int> > hash(MAX) ;
    for(int i=0;i<n;i++) {
        cin>>x;
        hash[x].push_back(i);
    }
    int min=INT_MAX;
    for(int i=0;i<MAX;i++)
        for(int j=1;j<hash[i].size();j++)
            if(hash[i][j]-hash[i][j-1]<min)
                min=hash[i][j]-hash[i][j-1];
    fout<<(min==INT_MAX?-1:min)<<"\n";
    fout.close();
    return 0;
}
