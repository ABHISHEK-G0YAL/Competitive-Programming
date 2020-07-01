// https://www.codechef.com/SATA2019/problems/SAT101

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    string s;
    cin >> t;
    while(t--) {
        cin >> s;
        vector<vector<int> > map(26);
        for(int i = 0; i < s.length(); i++)
            map[s[i] - 'a'].push_back(i);
        int max = -1;
        char ch = '*';
        for(int i = 0; i < 26; i++) {
            if(!map[i].empty() and ((map[i].back() - map[i].front()) > max)) {
                max = map[i].back() - map[i].front();
                ch = i + 'a';
            }
        }
        cout << ch << " " << max << endl;
    }
}