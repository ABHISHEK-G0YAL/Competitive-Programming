# F7 Championship

### The fictional World Championship of Formula 7 Drivers 2019 was characterized by exciting races and frequent shifts of driver positions on the leaderboard. Pradeep has missed most of it because he was training for olympiads in informatics. Now, looking at the leaderboard, Pradeep has a simple question for you: "How many drivers participating in this Championship still had a chance to become Formula 7 World Champion at the start of the final race?” The World Champion is, of course, the driver with the largest point total at the end (after the final race).

### There are N drivers participating in the Championship. They are all assigned points after each race, including the final one. The winner of the race is awarded N points, the runner-up gets N - 1 points, and so on until the last driver, who gets 1 point. Two drivers cannot finish a race in the same spot.

### Write a program to calculate, based on the total number of points that each driver has earned before the final race, how many drivers still have a chance to have the largest total after the final race and thus win the Championship. If more than one driver has the same maximum point total, they are all awarded the World Champion title

#### Input Format:

    The first line of input contains the positive integer N, the number of drivers participating in the Championship.
    Each of the following N lines contains a single integer Bi, the number of points that a driver has before the final race.

#### Constraints:

    3 ≤ N ≤ 300000
    0 ≤ Bi ≤ 2000000 (i = 1, ..., N)

#### Output Format:

    The first and only line of output should contain the requested number of drivers that can still win

#### Sample Input 1:

    3
    8
    10
    9 

#### Sample Output 1:

    3

#### Sample Input 2:

    5
    15
    14
    15
    12
    14

#### Sample Output 2:

    4

# Solution

```cpp
#include<bits/stdc++.h>
using namespace std;

bool canWin(vector<int> v, int p) {
    int n = v.size();
    int s = n - 1;
    v[p] += n;
    for(int i = 0; i < n; i++)
        if(p != i)
            v[i] += s--;
    int mx = 0;
    for(int &i : v)
        mx = max(mx, i);
    return v[p] >= mx;
}

int main() {
    int n, cnt = 0;
    cin >> n;
    vector<int> v(n);
    for(int &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    int s = 0, e = n - 1, m;
    while(s != e) {
        m = (s + e) / 2;
        if(canWin(v, m))
            e = m;
        else
            s = m + 1;
    }
    cout << n - e << endl;
}
```