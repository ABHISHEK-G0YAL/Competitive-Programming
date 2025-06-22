// https://www.spoj.com/problems/CKEWLK/

#include <iostream>
#define MOD 1000000007
using namespace std;

long powm(int n, int i) {
    if (i == 0) {
        return 1;
    }
    if (i % 2) {
        return (n * powm(n, i - 1)) % MOD;
    }
    long half = powm(n, i / 2);
    return (half * half) % MOD;
}

long F(int n, int m) {
    if (n <= 2) {
        return m;
    }
    return (powm(2, n - 2) * m) % MOD;
};

long C(int n, int m) {
    return (m + n + F(n, m)) % MOD;
}

int largestPrimeFactor(int n) {
    int largestFactor = 1;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            largestFactor = i;
            n /= i;
        }
    }
    return max(largestFactor, n);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, m, n;
    long sum = 0;
    cin >> t >> m;
    while (t--) {
        cin >> n;
        sum += largestPrimeFactor(C(n, m));
    }
    cout << "The President needs to pay " << sum << " dollar(s)";
    return 0;
}
