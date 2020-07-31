// https://github.com/ABHISHEK-G0YAL/Competitive-Programming/blob/master/practice/Coding_Ninjas/Single_character.md

#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  
    int t, mp[26], mx, mxc, i;
    string s;
    char c;
    cin >> t;
    while(t--) {
        memset(mp, 0, sizeof(mp));
        cin >> s;
        for(c : s)
            mp[c - 'a'] += 1;
        mx = 0;
        mxc = -1;
        for(i = 0; i < 26; i++) {
            if(mp[i] > mx) {
                mx = mp[i];
                mxc = i;
            }
        }
        while(mx--)
            cout << char(mxc + 'a');
        cout << endl;
    }
    return 0;
}