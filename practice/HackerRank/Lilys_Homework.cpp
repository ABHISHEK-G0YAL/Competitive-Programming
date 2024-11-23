// https://www.hackerrank.com/challenges/lilys-homework/problem

#include <bits/stdc++.h>
using namespace std;

// Swaping forms Directed Cycling Graps
// Cycle Decomposition
int getMinSwaps(vector<int> &arr, bool desc = false) {
    vector<pair<int, int>> arr_ind;
    for (int i = 0; i < arr.size(); i++) {
        arr_ind.push_back({ arr[i], i });
    }
    if (desc) {
        sort(arr_ind.rbegin(), arr_ind.rend());
    } else {
        sort(arr_ind.begin(), arr_ind.end());
    }

    // Adjacency List
    vector<int> swap_to(arr.size());
    for (int i = 0; i < arr.size(); i++) {
        swap_to[arr_ind[i].second] = i;
    }
    // DFS in loop
    // Marking visited by setting swap_to[i] = i
    int mismatch = 0, cycle_count = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (swap_to[i] != i) {
            int j = i;
            while (swap_to[j] != j) {
                swap(j, swap_to[j]);
                ++mismatch;
            }
            ++cycle_count;
        }
    }
    return mismatch - cycle_count;
}


int lilysHomework(vector<int> &arr) {
    return min(
        getMinSwaps(arr),
        getMinSwaps(arr, true)
    );
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int &i : arr) {
        cin >> i;
    }
    cout << lilysHomework(arr) << endl;
}