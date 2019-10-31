#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> a(n);
        int max = -1, maxi, min = 1000, mini, ind = 0;
        for(auto &i : a) {
            cin >> i;
            if(i > max) {
                max = i;
                maxi = ind;
            }
            if(i < min) {
                min = i;
                mini = ind;
            }
            ind++;
        }
        if(mini < maxi) {
            cout << min << " " << max << endl;
        }
        else {
            cout << max << " " << min << endl;
        }
    }
}