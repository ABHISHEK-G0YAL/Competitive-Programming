// https://www.hackerrank.com/challenges/making-anagrams/problem
// Accepted

#include <bits/stdc++.h>

using namespace std;

// Complete the makingAnagrams function below.
int makingAnagrams(string s1, string s2) {
    int m=0,c1[26]={},c2[26]={};
    for(int i=0;i<s1.length();i++) ++c1[s1[i]-'a'];
    for(int i=0;i<s2.length();i++) ++c2[s2[i]-'a'];
    for(int i=0;i<26;i++) m+=min(c1[i],c2[i]);
    return s1.length()+s2.length()-2*m;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = makingAnagrams(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
