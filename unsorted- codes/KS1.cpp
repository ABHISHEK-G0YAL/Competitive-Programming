#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];
        vector<pair<int, int> > parr;
        for(int i = 0; i < n; i++) {
            int xor_till_now = 0;
            for(int k = i; k < n; k++) {
                xor_till_now ^= a[k];
                if(xor_till_now == 0)
                    parr.push_back({i, k});
            }
        } int count = 0;
        for(auto p : parr)
            count += p.second - p.first;
        cout << count << endl;
    }
}