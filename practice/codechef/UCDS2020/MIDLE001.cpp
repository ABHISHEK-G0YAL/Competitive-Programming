// https://www.codechef.com/UCDS2020/problems/MIDLE001/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    unordered_map<char, int> freq;
    for(char c : s)
        ++freq[c];
    unordered_map<char, bool> printed;
    vector<pair<char, int> > to_print;
    for(char c : s)
        if(!printed[c]++)
            to_print.push_back({c, freq[c]});
    for(auto &p : to_print)
        cout << p.first << " " << p.second << " ";
    cout << endl;
    int n, x, starting, ending;
    cin >> n;
    while(n--) {
        cin >> x;
        for(int i = 0; i < to_print.size(); i++)
            if(to_print[i].second == x)
                ending = i;
        for(int i = to_print.size() - 1; i >= 0; i--)
            if(to_print[i].second == x)
                starting = i;
        deque<pair<char, int> > start, middle, end;
        for(int i = 0; i < to_print.size(); i++) {
            if(i >= starting and i <= ending) {
                if(to_print[i].second < x)
                    start.push_front(to_print[i]);
                else if(to_print[i].second > x)
                    end.push_back(to_print[i]);
                else
                    middle.push_back(to_print[i]);
            }
            else
                middle.push_back(to_print[i]);
        }
        to_print = {};
        for(auto &p : start)
            to_print.push_back(p);
        for(auto &p : middle)
            to_print.push_back(p);
        for(auto &p : end)
            to_print.push_back(p);
        for(auto &p : to_print)
            cout << p.first << " " << p.second << " ";
        cout << endl;
    }
}