// https://www.codechef.com/JAN20B/problems/BRKBKS

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <chrono>
#include <limits>
#include <bitset>
#include <sstream>
#include <utility>
#include <numeric>
#include <iterator>
#include <functional>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define mod 1000000007
#define inf 2147480000
#define linf 9223372036800000000
#define PI 3.1415926535897932384626433832795
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define contains(c,x) ((c).find(x) != (c).end())
#define acontains(c,x) (find(all(c),x) != (c).end())
#define watch(x) cout << (#x) << " is " << (x) << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
const double pi = acos(-1.0);

int main() {
    fastio;
    int t, n, s, w[3];
    cin >> t;
    while(t--) {
        cin >> s >> w[0] >> w[1] >> w[2];
        int cnt = 1, width = 0;
        for(int i = 0; i < 3; i++) {
            width += w[i];
            if(width > s) {
                cnt += 1;
                width = w[i];
            }
        }
        cout << cnt << endl;
    }
    return 0;
}