// https://www.hackerrank.com/challenges/separate-the-numbers/problem
// Accepted

#include <bits/stdc++.h>
using namespace std;

bool isBeautiful(string s,long x) { string e;
    while(e.length()<s.length()) e+=to_string(x++);
    if(s==e) return true;
    return false;
}

void separateNumbers(string s) {
    for(int a=1;a<=s.length()/2;a++) {
        long x=stol(s.substr(0,a));
        if(isBeautiful(s,x)) {
            cout<<"YES "<<x<<endl;
            return;
        }
    } cout<<"NO"<<endl;
}

int main() {
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        separateNumbers(s);
    }

    return 0;
}
