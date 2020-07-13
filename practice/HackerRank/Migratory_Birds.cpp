// https://www.hackerrank.com/challenges/migratory-birds/problem

#include <bits/stdc++.h>

using namespace std;

int migratoryBirds(int n, vector <int> ar) {
    // Complete this function
    int count[6]={0,0,0,0,0,0};
    for(int i=0;i<n;i++)
        ++count[ar[i]];
    int bird=1;
    for(int i=2;i<6;i++)
        if(count[bird]<count[i])
            bird=i;
    return bird;
}

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    int result = migratoryBirds(n, ar);
    cout << result << endl;
    return 0;
}
