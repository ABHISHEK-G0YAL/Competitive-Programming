// https://www.hackerrank.com/challenges/reduced-string/problem
// Accepted

#include <bits/stdc++.h>

using namespace std;

// Complete the superReducedString function below.
string superReducedString(string s) {
    string sRS="";
    for(int i=0;i<s.length();i++) {
        if(!sRS.empty() && sRS.back()==s.at(i)) sRS.pop_back();
        else sRS.push_back(s.at(i));
    }
    if(sRS.empty()) sRS="Empty String";
    return sRS;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
