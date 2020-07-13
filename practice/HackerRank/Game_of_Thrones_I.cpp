// https://www.hackerrank.com/challenges/game-of-thrones/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the gameOfThrones function below.
string gameOfThrones(string s) {
    int fre[26]={}; int cnt_nt_even=0;
    for(int i=0;i<s.length();i++) fre[s[i]-'a']++;
    for(int i=0;i<26;i++) cnt_nt_even+=(fre[i]%2);
    if(cnt_nt_even<2) return "YES";
    else return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = gameOfThrones(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
