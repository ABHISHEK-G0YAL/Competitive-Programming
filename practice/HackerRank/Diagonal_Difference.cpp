// https://www.hackerrank.com/challenges/diagonal-difference/problem
// Accepted

#include <bits/stdc++.h>

using namespace std;

int diagonalDifference(vector < vector<int> > a) {
    // Complete this function
    int diff=0;
    for(int i=0;i<a.size();i++)
        diff=diff+(a[i][i]-a[a.size()-1-i][i]);
                   return abs(diff);
}

int main() {
    int n;
    cin >> n;
    vector< vector<int> > a(n,vector<int>(n));
    for(int a_i = 0;a_i < n;a_i++){
       for(int a_j = 0;a_j < n;a_j++){
          cin >> a[a_i][a_j];
       }
    }
    int result = diagonalDifference(a);
    cout << result << endl;
    return 0;
}
