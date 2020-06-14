#include <bits/stdc++.h>
using namespace std;

random_device rd;
mt19937 eng(rd());
uniform_int_distribution<unsigned int> distr;

int random(int x, int y) {
    int range = y - x + 1;
    return (distr(eng) % range) + x;
}

int sum(vector<int> v) {
    int sum = 0;
    for(auto i : v)
        sum += i;
    return sum;
}
int main() {
    int n = random(3, 8), m = random(4, 8);
    vector<int> row, col;
    for(int i = 0; i < n; i++) row.push_back(random(0, m));
    for(int i = 0; i < m; i++) col.push_back(random(0, n));
    if(sum(row) == sum(col)) {
        cout << n << " " << m << "\n";
        for(auto i : row) cout << i << " "; cout << "\n";
        for(auto i : col) cout << i << " "; cout << "\n";
    } else main();
}