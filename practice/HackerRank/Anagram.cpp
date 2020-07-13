// https://www.hackerrank.com/challenges/anagram/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the anagram function below.
int anagram(string s) {
    int m=0,n=s.length();
    if(n%2) return -1;
    int s1[26]={},s2[26]={};
    for(int i=0;i<n/2;i++) {
        ++s1[s[i]-'a'];
        ++s2[s[n/2+i]-'a'];
    } for(int i=0;i<26;i++)
        m+=min(s1[i],s2[i]);
    return n/2-m;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = anagram(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
