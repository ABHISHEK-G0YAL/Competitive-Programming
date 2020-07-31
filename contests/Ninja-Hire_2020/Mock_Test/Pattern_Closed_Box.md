# Pattern: Closed Box

### Print the given pattern for the given number of rows.

#### Pattern for N=4
    ####
    *  *
    *  *
    ####

#### Input format:
    N (Total number of rows).

#### Constraints:
    N lies between [3,40]

#### Output format:
    Pattern in N lines

#### Sample Input 1:
    5

#### Sample Output 1:
    #####
    *   *
    *   *
    *   *
    #####

# Solution
```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    cout << string(n, '#') << endl;
    for(int i = 0; i < n - 2; i++)
    	cout << '*' << string(n - 2, ' ') << '*' << endl;
    cout << string(n, '#') << endl;
}
```