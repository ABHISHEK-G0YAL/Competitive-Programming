#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > takeMatInput() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > mat(n, vector<int>(m));
    for(auto &v : mat)
        for(auto &i : v)
            cin >> i;
    return mat;
}
int add(vector<vector<int> > matA, vector<vector<int> > matB) {
    
}
int main() {
    cout << "Assignment 1" << endl;
    cout << "Question 2" << endl;
    vector<vector<int> > matA = takeMatInput();
    vector<vector<int> > matB = takeMatInput();
    if(matA.size() != matB.size() or matA.front.size() != matB.front.size())
        cout << "Incompatible input matrices" << endl;
    else {
        cout << add(matA, matB) << endl;
        cout << sub(matA, matB) << endl;
    }
}