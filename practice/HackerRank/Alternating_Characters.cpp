// https://www.hackerrank.com/challenges/alternating-characters/problem
// Accepted

#include <bits/stdc++.h>

using namespace std;

// Complete the alternatingCharacters function below.
int alternatingCharacters(string s) {
    int deletions_required=0;
    for(int i=1;i<s.length();i++) 
        if(s[i]==s[i-1]) ++deletions_required;
    return deletions_required;
}
int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);
        int result = alternatingCharacters(s);
        fout << result << "\n";
    }
    fout.close();
    return 0;
}
