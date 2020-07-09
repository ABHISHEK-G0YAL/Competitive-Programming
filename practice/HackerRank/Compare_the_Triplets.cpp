// https://www.hackerrank.com/challenges/compare-the-triplets/problem
// Accepted

#include <bits/stdc++.h>

using namespace std;

vector < int > solve(int a0, int a1, int a2, int b0, int b1, int b2){
    // Complete this function
    vector <int> result(2);
    if(a0>b0)
        result[0]+=1;
    else if(b0>a0)
        result[1]+=1;
    if(a1>b1)
        result[0]+=1;
    else if(b1>a1)
        result[1]+=1;
    if(a2>b2)
        result[0]+=1;
    else if(b2>a2)
        result[1]+=1;
    return result;
}

int main() {
    int a0;
    int a1;
    int a2;
    cin >> a0 >> a1 >> a2;
    int b0;
    int b1;
    int b2;
    cin >> b0 >> b1 >> b2;
    vector < int > result = solve(a0, a1, a2, b0, b1, b2);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? " " : "");
    }
    cout << endl;
    

    return 0;
}
