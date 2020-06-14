#include <bits/stdc++.h>
using namespace std;

random_device rd;
mt19937 eng(rd());
uniform_int_distribution<unsigned int> distr;

int random(int x, int y) {
    int range = y - x + 1;
    return (distr(eng) % range) + x;
}

int main() {
    int t1 = random(5, 8);
    int t2 = random(12, 25);
    int t3 = random(12, 33);
    int t4 = random(12, 33);
    cout << t1 + t2 + t3 + t4 + 1 << endl;
    while(t1--) {
        int n = random(1, 12);
        cout << n << endl;
        int num = random(1, 20);
        while(n--)
            cout << num << " ";
        cout << endl;
    }
    while(t2--) {
        int n = random(1, 12);
        cout << n << endl;
        while(n--)
            cout << random(1, 100) << " ";
        cout << endl;
    }
    while(t3--) {
        int n = random(1, 12);
        cout << n << endl;
        while(n--)
            cout << random(1, 1000) << " ";
        cout << endl;
    }
    while(t4--) {
        int n = random(1, 12);
        cout << n << endl;
        while(n--)
            cout << random(1, 1000000) << " ";
        cout << endl;
    }
    int n = random(1, 12);
    cout << n << endl;
    while(n--)
        cout << 2 << " ";
    cout << endl;
}
