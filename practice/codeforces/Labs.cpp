// http://codeforces.com/contest/1236/problem/C

#include<bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<vector<int> > arr(n, vector<int> (n));
    int num = n * n;
    bool down = true;
    for(int j = 0; j < n; j++, down = !down)
        for(int i = down ? 0 : n -1; i >= 0 and i < n; i += down ? 1 : -1)
            arr[i][j] = num--;
    for(auto ar : arr) {
        for(auto i : ar)
            cout << i << " ";
        cout << endl;
    }
}