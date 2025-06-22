# Split array

Ninja is given 2N positive integers and he wants to make two arrays out of it. He denotes the two arrays by the symbol: A and B. Each array should be of size N. Ninja has to divide these integers in such a way that after sorting A and B they should become identical to each other.

For example, let's assume Ninja got these integers = {1,2,1,6,4,2,4,6}. He can make A={1,4,2,6} and B={2,1,6,4} and after sorting A and B, both will be identical.

### Input format:
    The first line of input will contain an integer T, that will denote the value of number of test cases.
    Each test case will consist of two lines, first line of each test case will contain an integer N.
    Second line of each test case will contain 2N space separated positive integers.

### Constraints:
    1<=T<=10^5
    1<=N<=2*10^5
    1<=arr[i]<=100000, for all i in the range: [1,2N]. In other words, the value of positive integers is between 1 and 100000.
    The sum of N over all test cases does not exceed 2*10^5.
    Time Limit: 1 second

### Output format:
    For each test case, print “YES” (without quotes) if it is possible to create A and B, else print “NO” (without quotes) in a new line.
    Note: Output is case sensitive. Therefore, printing “yes” ,”no”,”Yes” ,”No” etc will give you wrong answer.

### Sample Input 1:
    4
    3
    1 2 3 4 5 6
    2 
    2 2 2 2
    3
    3 3 4 4 5 5
    4     
    1 1 1 1 1 1 1 1

### Sample Output 1:
    NO
    YES
    YES
    YES

# Solution
```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, x;
    cin >> t;
    while(t--) {
        unordered_map<int, int> mp;
        cin >> n;
        n *= 2;
        while(n--) {
            cin >> x;
            ++mp[x];
        }
        int yes = true;
        for(auto &p : mp)
            yes &= (p.second % 2 == 0);
        cout << (yes ? "YES" : "NO") << endl;
    }
    return 0;
}
```