// https://www.hackerrank.com/challenges/camelcase/problem
// Accepted

#include <bits/stdc++.h>

using namespace std;

// Complete the camelcase function below.
int camelcase(string s) {
    int count=1;
    for(int i=1;i<s.length();i++)
        if(s[i]<='Z') count++;
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = camelcase(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
