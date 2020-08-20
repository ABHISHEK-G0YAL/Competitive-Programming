// https://github.com/ABHISHEK-G0YAL/Competitive-Programming/blob/master/practice/Misc/Rubrik_Super_Cluster.md

#include <iostream>
#include <vector>
#define mod 1000000007
#define ll long long

using namespace std;

void print(vector<vector<int> > nodes) {
    for(auto i : nodes) {
        for(auto m : i) {
            cout << m << " ";
        } cout << endl;
    } cout << endl;
}

int expMod13(int dig, int expo) {
    int E = 10;
    while(expo) {
        if(expo & 1) {
            dig *= E;
            dig %= 13;
        } E *= E;
        E %= 13;
        expo >>= 1;
    } return dig;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        char x;
        cin >> n;
        vector<vector<int> > nodes(n, vector<int>(13, 0));
        for(int i = 1; i <= n; i++) {
            cin >> x;
            if(x == '?') {
                for(int d = 0; d < 10; d++)
                    ++nodes[i - 1][expMod13(d, n - i)];
            } else {
                int d = x - '0';
                ++nodes[i - 1][expMod13(d, n - i)];
            }
        } print(nodes);
        while(n != 1) {
            vector<vector<int> > merged((n + 1) / 2, vector<int>(13, 0));
            for(int i = 0; i < n; i += 2) {
                for(int m1 = 0; m1 < 13; m1++) {
                    for(int m2 = 0; m2 < 13; m2++) {
                        if(i + 1 < n)
                            merged[i / 2][(m1 + m2) % 13] += nodes[i][m1] * nodes[i + 1][m2];
                        else
                            merged[i / 2] = nodes[i];
                    }
                } 
            } nodes = merged;
            n = nodes.size();
        }
        print(nodes);
    }
}