// https://www.hackerrank.com/challenges/the-hurdle-race/problem
// Accepted

#include <bits/stdc++.h>

using namespace std;

int hurdleRace(int k, vector <int> height) {
    // Complete this function
    int max=0;
    for(int i=0;i<height.size();i++)
        if(height[i]>max)
            max=height[i];
    return (max>k?max-k:0);
}

int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<int> height(n);
    for(int height_i = 0; height_i < n; height_i++){
       cin >> height[height_i];
    }
    int result = hurdleRace(k, height);
    cout << result << endl;
    return 0;
}
