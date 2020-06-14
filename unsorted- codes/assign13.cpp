#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "Assignment 1\n" << endl;
    cout << "Question 3" << endl;
    int n1, m1;
    cin >> n1 >> m1;
    vector<vector<int> > matA(n1, vector<int>(m1));
    for(auto &v : matA) {
        for(auto &i : v) {
            cin >> i;
        }
    }
    int n2, m2;
    cin >> n2 >> m2;
    vector<vector<int> > matB(n2, vector<int>(m2));
    for(auto &v : matA) {
        for(auto &i : v) {
            cin >> i;
        }
    }
    if(m1 == n2) {
        cout << mul(matA, matB) << endl;
    }
    else {
        cout << "Incompatible input matrices" << endl;
    }
}