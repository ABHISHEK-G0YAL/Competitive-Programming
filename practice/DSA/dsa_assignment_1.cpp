#include <bits/stdc++.h>
using namespace std;


int sumArrItr(vector<int> v) {
    int sum = 0;
    for(auto i : v)
        sum += i;
    return sum;
}

int sumArrRec(vector<int> v, int i = 0) {
    if(i == v.size()) return 0;
    return v[i] + sumArrRec(v, i + 1);
}

int fact(int x) {
    if(x == 0) return 1;
    return x * fact(x - 1);
}

int power(int a, int b) {
    if(b == 0) return 1;
    int ans = power(a, b/2);
    if(b & 1) return a * ans * ans;
    else return ans * ans;
}

float eItr(int x) {
    float sum = 1;
    float t = x;
    for(int i = 2; i < 10; i++) {s
        sum += t;
        t *= x;
        t /= i;
    } return sum;
}

float eRecHelp(int x, float t = 1, int i = 1) {
    if(i == 10) return 0;
    return t * x / i + eRecHelp(x, t * x / i, i + 1);
}
float eRec(int x) {
    return 1 + eRecHelp(x);
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    cout << sumArrItr(v) << endl;
    cout << sumArrRec(v) << endl;
    int x;
    cin >> x;
    cout << fact(x) << endl;
    int a, b;
    cin >> a >> b;
    cout << power(a, b) << endl;
    cin >> x;
    cout << eItr(x) << endl;
    cout << eRec(x) << endl;
}