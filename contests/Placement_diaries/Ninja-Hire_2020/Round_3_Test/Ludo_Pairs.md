# Ludo Pairs

To bring a smile on the faces of colleagues at Coding Ninjas, young Ninja came up with a plan. He decided to organise a ludo tournament. To pair up the players, he gave everyone a ludo number. This ludo number was decided on the basis of their past experience in the ludo game. He took a prime number P and only paired those players whose sum of numbers is divisible by P.

Since, Ninja is busy with other things. He needs a little help from you. He wants you to check if it is possible to divide the players into N/2 pairs.

### Input Format
    The first line of input contains an integer T, that denotes the value of number of test cases.
    In each of the following T test cases, the first line of input contains N, that denotes the number of players playing the game. The following line contains N space separated integers, that denotes the ludo numbers of the players. The following line contains an integer P, that denotes the prime number

### Constraints
    T lies in the range: [1, 10]
    N lies in the range: [1, 100000]
    N is even
    Ludo numbers lie in the range: [-1000,000,000, 1000,000,000]. Ludo numbers can be negative as well.
    P is any prime number from all the prime numbers in the range: [1, 1000].
    Time Limit: 1 second

### Output format
    For each test case, print true if it is possible to divide the players into N/2 pairs and false otherwise.

### Sample Input 1
    1
    8
    1 4 32 17 20 57 69 59
    7

### Sample Output 1
    true

### Explanation
    This is one of possible ways in which the players can be divided into N/2 pairs: (1, 20), (4, 17), (59, 32), (57, 69)

### Sample Input 2
    1
    2
    -1 1
    5

### Sample Output 2
    true

# Solution
```cpp
#include<bits/stdc++.h>
using namespace std;
int main() {
    int t, n, ncs[1005], i, j;
    long long int p;
    cin >> t;
    while(t--) {
        memset(ncs, 0, 4020);
        cin >> n;
        vector<long long int> v(n);
        for(auto &x : v)
            cin >> x;
        cin >> p;
        for(auto &x : v)
            ++ncs[(x + p * 1000000000) % p];
        bool tru = (ncs[0] % 2 == 0);
        i = 1, j = p - 1;
        while(i < j)
            tru &= (ncs[i++] == ncs[j--]);
        if(i == j)
            tru &= (ncs[i] % 2 == 0);
        cout << (tru ? "true" : "false") << endl;
    }
}
```