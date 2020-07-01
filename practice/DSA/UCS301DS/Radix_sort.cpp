https://www.codechef.com/UCSD2020/problems/DSLA2

#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &v) {
    for(int &i : v)
        cout << i << " ";
    cout << endl;
}
void countSort(vector<int> &v, int e) { 
    int n = v.size(), p = 0;
    vector<int> c(10), temp(n);
    for(int &i : v)
        c[(i / e) % 10] += 1;
    reverse(c.begin(), c.end());
    for(int &i : c) {
        i += p;
        p = i;
    }
    reverse(c.begin(), c.end());
    reverse(v.begin(), v.end());
    for(int &i : v)
        temp[--c[(i / e) % 10]] = i;
    v = temp;
}
void radixsort(vector<int> &v) {
    int m = *max_element(v.begin(), v.end());
    for (int e = 1; m / e > 0; e *= 10) {
        countSort(v, e);
        print(v);
    }
} 
int main() {
    int n; cin >> n;
    vector<int> a(n);
    for(auto &i : a) cin >> i;
    radixsort(a);
}