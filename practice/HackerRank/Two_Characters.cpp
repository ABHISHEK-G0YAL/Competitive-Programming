// https://www.hackerrank.com/challenges/two-characters/problem
// Accepted

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

bool isValid(string s) {
    for(int i=1;i<s.length();i++)
        if(s[i-1]==s[i]) return false;
    if(s.length()==1) return false;
    return true;
}
int alternate(string s) {
    int max=0;
    for(char a='a';a<='z';a++) {
        for(char b=a+1;b<='z';b++) {
            string e;
            for(int i=0;i<s.length();i++)
                if(s[i]==a || s[i]==b) e+=s[i];
            if(isValid(e) && e.length()>max) max=e.length();
        }
    } return max;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string l_temp;
    getline(cin, l_temp);

    int l = stoi(ltrim(rtrim(l_temp)));

    string s;
    getline(cin, s);

    int result = alternate(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
