// https://www.hackerrank.com/challenges/repeated-string/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    long count_a=0,n_strings,part_s;
    for(int i=0;i<s.length();i++)
        if(s[i]=='a')
            ++count_a;
    n_strings=n/s.length();
    part_s=n%s.length();
    count_a*=n_strings;
    for(int i=0;i<part_s;i++)
        if(s[i]=='a')
            ++count_a;
    return count_a;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
