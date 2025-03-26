// https://www.hackerrank.com/contests/university-codesprint-4/challenges/unique-art/problem
// Terminated due to timeout

#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the student function below.
 */
int student(int begin,int end,vector<int> t) {
    // Return the number of paintings that this student will appreciate.
    unordered_map<int, int> hm;
    int i,j,c=0;
    for(i=begin-1;i<end;i++)
    hm[t[i]]++;
    for(i=begin-1;i<end;i++)
        if(hm[t[i]]==1)
            ++c;
    return c;
}


int main() {
    int n;
    cin >> n;
    vector<int> t(n);
    for (int &i : t) {
        cin >> i;
    }
    int q, l, r;
    cin >> q;
    while (q--) {
        cin >> l >> r;
        cout << student(l, r, t) << "\n";
    }
    return 0;
}