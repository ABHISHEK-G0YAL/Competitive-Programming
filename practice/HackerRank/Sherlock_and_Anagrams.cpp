// https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem

#include <bits/stdc++.h>
using namespace std;

int sherlockAndAnagrams(string s) {
    unordered_map<string, int> mp;
    for (int l = 1; l <= s.length(); l++) {
        for (int i = 0; i < s.length() + 1 - l; i++) {
            string ss = s.substr(i, l);
            sort(ss.begin(), ss.end());
            mp[ss] += 1;
        }
    }
    int pairs = 0;
    for (auto &[k, v] : mp) {
        pairs += (v * (v - 1)) / 2;
    }
    return pairs;
}

int sherlockAndAnagrams2(string s) {
    unordered_map<string, int> mp;
    for (int i = 0; i < s.length(); i++) {
        vector<int> f(26, 0);
        for (int j = i; j < s.length(); j++) {
            ++f[s[j] - 'a'];
            string key = "";
            for(int &x : f) {
                key += to_string(x) + "#";
            }
            mp[key] += 1;
        }
    }
    int pairs = 0;
    for (auto &[k, v] : mp) {
        pairs += (v * (v - 1)) / 2;
    }
    return pairs;
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        cout << sherlockAndAnagrams2(s) << endl;
    }
    return 0;
}
