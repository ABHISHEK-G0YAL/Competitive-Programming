// https://www.hackerrank.com/challenges/string-construction/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the stringConstruction function below.
int stringConstruction(string s) {
    int d=0;bool c1[26]={};
    for(int i=0;i<s.length();i++) c1[s[i]-'a']=true;
    for(int i=0;i<26;i++) d+=c1[i];
    return d;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = stringConstruction(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
