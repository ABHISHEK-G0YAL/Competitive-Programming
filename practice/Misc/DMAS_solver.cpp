#include <bits/stdc++.h>
using namespace std;

int eval(string e) {
    int n = e.length();
    for(int i = 0; i < n; i++) {
        if(e[i] == '+')
            return eval(e.substr(0, i)) + eval(e.substr(i+1));
        if(e[i] == '-')
            return eval(e.substr(0, i)) - eval(e.substr(i+1));
    }
    for(int i = 0; i < n; i++)
        if(e[i] == '/')
            return eval(e.substr(0, i)) / eval(e.substr(i+1));
    for(int i = 0; i < n; i++)
        if(e[i] == '*')
            return eval(e.substr(0, i)) * eval(e.substr(i+1));
    return stoi(e);
}

int main() {
    string s;
    cin >> s;
    cout << eval(s) << endl;
}