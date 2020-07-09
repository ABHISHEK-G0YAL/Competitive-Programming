// https://www.hackerrank.com/challenges/append-and-delete/problem
// Accepted

#include <bits/stdc++.h>

using namespace std;

string appendAndDelete(string s, string t, int k) {
    // Complete this function
    int i=0,lengths=s.length()+t.length();
    for(i=0;i<min(s.length(),t.length());i++)
        if(s[i]!=t[i])
            break;
    int operations =lengths - 2*i;
    if((k>=operations && (k-operations)%2==0) || (k>=lengths))
        return "Yes";
    else
        return "No";
}

int main() {
    string s;
    cin >> s;
    string t;
    cin >> t;
    int k;
    cin >> k;
    string result = appendAndDelete(s, t, k);
    cout << result << endl;
    return 0;
}
