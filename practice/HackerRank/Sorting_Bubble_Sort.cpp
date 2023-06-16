// https://www.hackerrank.com/challenges/ctci-bubble-sort/problem/

#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'countSwaps' function below.
 *
 * The function accepts INTEGER_ARRAY a as parameter.
 */

void countSwaps(vector<int> &a) {
    int n = a.size(), swap_count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                ++swap_count;
            }
        }
    }
    cout << "Array is sorted in " << swap_count << " swaps." << endl;
    cout << "First Element: " << a[0] << endl;
    cout << "Last Element: " << a[n - 1] << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    countSwaps(a);
    return 0;
}
