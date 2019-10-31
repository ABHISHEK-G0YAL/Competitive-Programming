#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#define ui unsigned int
using namespace std;

int main() {
    ui t; cin >> t;
    for(ui x=1; x<=t; x++) {
        ui n; cin >> n;
        vector<string> word(n);
        for(ui i=0; i<n; i++) {
            cin >> word[i];
            reverse(word[i].begin(),word[i].end());
        } sort(word.begin(),word.end());
        for(ui i=0; i<n; i++) cout<<word[i]<<endl;
        vector<string> accent_suffix;
        for(ui i=0; i < n-1; i+=2) {
            ui j = 0;
            string t="";
            while (word[i][j] == word[i+1][j]) {
                t+=word[i][j];
                j++;
            }
            // cout<<t<<endl;
            bool added = false;
            while(t.size() > 0) {
                if(accent_suffix.size() == 0) {
                    accent_suffix.push_back(t);
                    added = true;
                    // cout<<t<<endl;
                    break;
                }
                for (ui i = 0; i < accent_suffix.size(); i++) {
                    if(t == accent_suffix[i]) break;
                    if(i == (accent_suffix.size() - 1)) {
                        accent_suffix.push_back(t);
                        added = true;
                        // cout<<t<<endl;
                        break;
                    }
                }
                if(!added) t.pop_back();
                else break;
            }
            if(!added) i-=1;
        }
        cout<<"Case #"<<x<<": "<<accent_suffix.size()*2<<endl;
    }
}