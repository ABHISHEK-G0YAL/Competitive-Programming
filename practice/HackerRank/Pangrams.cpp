// https://www.hackerrank.com/challenges/pangrams/problem
// Accepted

#include <bits/stdc++.h>
using namespace std;

string pangrams(string s) {
    bool present_alph[26]={};
    for(int i=0;i<s.length();i++) {
        if('A'<=s[i] && s[i]<='Z')
            present_alph[s[i]-'A']=true;
        else present_alph[s[i]-'a']=true; 
    } for(int i=0;i<26;i++)
        if(!present_alph[i])
            return "not pangram";
    return "pangram";
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    string s;
    getline(cin, s);
    string result = pangrams(s);
    fout << result << "\n";
    fout.close();
    return 0;
}
