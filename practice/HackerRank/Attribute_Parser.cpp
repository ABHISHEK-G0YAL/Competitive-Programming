// https://www.hackerrank.com/challenges/attribute-parser/problem
// Accepted

#include<bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

void getAttrib(string s, deque<string> &attrib) {
    s = s.substr(1, s.length() - 2);
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == ' ') {
            attrib.push_back(s.substr(0, i));
            s = s.substr(i + 1);
            i = 0;
        }
    }
    attrib.push_back(s);
}
unordered_map<string, string> db;
void parse(vector<string> &hrml) {
    string query;
    stack<string> prev;
    for(auto &s : hrml) {
        if(s[1] == '/') {
            query = prev.top();
            prev.pop();
        }
        else {
            prev.push(query);
            if(!query.empty())
                query += ".";
            deque<string> attrib;
            getAttrib(s, attrib);
            query += attrib.front();
            attrib.pop_front();
            bool val = false;
            prev.push(query);
            for(auto &a : attrib) {
                if(a == "=")
                    val = true;
                else if(!val)
                    query += "~" + a;
                else {
                    db[query] = a.substr(1, a.length() - 2);
                    query = prev.top();
                    val = false;
                }
            }
            prev.pop();
        }
    }
}
int main() {
    int n, q;
    cin >> n >> q;
    vector<string> hrml(n);
    string stupidEmptyLine;
    getline(cin, stupidEmptyLine);
    for(auto &s : hrml)
        getline(cin, s);
    parse(hrml);
    string query;
    while (q--) {
        cin >> query;
        if(db[query].empty())
            cout << "Not Found!" << endl;
        else
            cout << db[query] << endl;
    }
    return 0;
}
