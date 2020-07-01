// Given an array of size n <= 18, a and b. WAP 
// to find number of subsets of array whose sum
// is between a and b

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int a, b, *arr;
    int solve(int n, int sum) {
        if(n == 0)
            return (a <= sum and sum <= b) ? 1 : 0;
        return solve(n - 1, sum + arr[n - 1]) + solve(n - 1, sum);
    }
    int countSubsequence(int arr[], int n, int a, int b) {
        this->a = a, this->b = b, this->arr = arr;
        return solve(n, 0);
    }
};

int main() {
    int n, a, b;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> a >> b;
    Solution s;
    cout << s.countSubsequence(arr, n, a, b) << endl;
}