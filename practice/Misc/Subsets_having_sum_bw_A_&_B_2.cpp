// Given an array of size n <= 18, a and b. WAP to 
// find number of subsets of array which contain a
// prime number and whose sum is between a and b

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int a, b, *arr;
    bool *isp;
    bool isPrime(int n) {
        if(n == 1)
            return false;
        int sqrt_n = sqrt(n);
        for(int i = 2; i <= sqrt_n; ++i)
            if(n % i == 0)
                return false;
        return true;
    }
    int solve(int n, int sum, int prime) {
        if(n == 0)
            return (prime and a <= sum and sum <= b) ? 1 : 0;
        return solve(n - 1, sum + arr[n - 1], prime or isp[n - 1]) + solve(n - 1, sum, prime);
    }
    int countSubsequence(int arr[], int n, int a, int b) {
        bool isp[n];
        for(int i = 0; i < n; i++)
            isp[i] = isPrime(arr[i]);
        this->a = a, this->b = b, this->arr = arr, this->isp = isp;
        return solve(n, 0, false);
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