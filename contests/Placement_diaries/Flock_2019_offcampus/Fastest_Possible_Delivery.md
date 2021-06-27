# Fastest Possible Delivery 

Hari is a Food Delivery guy and he has to pick food from restaurant R and deliver it to home H. Distance of H from R is D. 

When Hari reached at the restaurant R, he checked and found that his motorbike has P units of petrol left. Now, there are N fuel stations on the path from R to H and he may use these fuel stations to get petrol for his motorbike if any need arises. 

These N fuel stations are at distance D(1), D(2), D(3), ........, D(N) units from the restaurant R and these N fuel stations have P(1), P(2), P(3), ........, P(N) units of petrol. Hari's motorbike tank is large enough to store any quantity of petrol. if Hari stops at any fuel station to get petrol, it takes K minutes. 

If at any point of time, there is no petrol in Hari's motorbike, he will have to drag his motorbike on foot to nearest fuel station or his delivery location. If Hari drags his motorbike on foot, he takes 5 minutes to cover 1 unit distance and if he drives the motorbike, he takes 1 minute to cover 1 unit distance. Hari may drag his motorbike on foot even if there is petrol in motorbike to minimise the delivery time. 

Now, Hari has to deliver this order in minimum amount of time. Find the minimum possible time required to deliver the order.

### Input:
- First line will contain 4 integers denoting N, D, P and K.
- Next line will contain N integers denoting D(1), D(2), D(3), ......, D(N)
- Next line will contain N integers denoting P(1), P(2), P(3), ......, P(N)

### Output:
Output a single integer denoting the minimum possible time required to deliver the order.

### Constraints:
- 1 <= N <= 50 
- 1 <= D <= 5000 
- 0 <= P <= 100 
- 1 <= K <= 100 
- 1 <= D(i) - 1 <= D(i) <= D 
- 1 <= P(i) <= 100

### Sample
#### Input
```
3 10 1 3
3 5 9
6 1 2
```
#### Output
```
24
```

### Solution
#### C++
```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 5000 + 5;
#define ll long long int
ll pet[N];
ll val[N];
ll n, d, p, k;

ll dp[N][N];

ll go(int pos, ll petrol){
    if(pos == d) return 0;
    ll &ans = dp[pos][petrol];
    if(ans != -1) return ans;
    ans = numeric_limits<int>::max();
    ans = min(ans, go(pos + 1, max(0LL, petrol - 1)) + ((petrol == 0) ? 5 : 1));
    if(pet[pos]){
       ans = min(ans, go(pos + 1, max(0LL, petrol) + pet[pos] - 1) + 1 + k);
    }
    return ans;
}

int main(){
    cin >> n >> d >> p >> k;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        pet[x] = 1;
    }
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        val[i] = x;
    }
    int pt = 0;
    for(int i = 0; i < 5001; i++){
        if(pet[i]){
            pet[i] = val[pt++];
        }
    }
    memset(dp, -1, sizeof dp);
    cout << go(0, p);
}
```