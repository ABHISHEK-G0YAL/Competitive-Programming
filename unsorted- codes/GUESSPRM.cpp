#include <bits/stdc++.h>
#define MAX 31624LL
#define MAX2 22362LL
using namespace std;

vector<bool> sieve(MAX, true);
vector<int> prime;

void init_sieve() {
    for(int i = 2; i <= sqrt(MAX); i++)
        if(sieve[i] == true)
            for(int j = i * i; j < MAX; j += i)
                sieve[j] = false;
    for(int i = 2; i < MAX; i++)
        if(sieve[i]) prime.push_back(i);
}
void prime_factor(long long num, vector<int> &factor, int mod) {
    int i = 0;
    while(i < prime.size() and num != 1 and prime[i] <= sqrt(num)) {
        if(num % prime[i] == 0) {
            num /= prime[i];
            if(factor.empty() or factor.back() != prime[i])
                if(prime[i] > mod)
                    factor.push_back(prime[i]);
        } else i++;
    }
    if(num != 1)
        if(factor.empty() or factor.back() != num)
            if(num > mod)
                factor.push_back(num);
}
int main() {
    init_sieve();
    int t; cin >> t;
    while(t--) {
        int mod;
        string ans;
        cout << 1 << " " << MAX << endl;
        cin >> mod;
        vector<int> factor;
        prime_factor(MAX * MAX - mod, factor, mod);
        if(factor.size() == 1) {
            cout << 2 << " " << factor[0] << endl;
            cin >> ans;
            continue;
        } cout << 1 << " " << MAX2 << endl;
        cin >> mod;
        vector<int> factor2;
        prime_factor(MAX2 * MAX2 - mod, factor2, mod);
        vector<int> common(5);
        set_intersection(factor.begin(), factor.end(), factor2.begin(), factor2.end(), common.begin());
        cout << 2 << " " << common[0] << endl;
        cin >> ans;
        if(ans != "Yes") break;
    }
}