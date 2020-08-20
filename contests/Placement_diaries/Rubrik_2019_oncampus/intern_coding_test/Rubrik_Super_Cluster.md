# Rubrik Intern Test Q10 - Aug 6, 2019

The Super Cluster of Rubrik has N clusters and each cluster is represented by a number describing the total number of nodes in that cluster, which is also called degree of cluster. The degree of any cluster ranges from 0-9. However, the degree of some clusters are unknown and are represented by ?. A Super Cluster is said to be in a healthy state if the following property holds good. X % 13 = 5 where, X is the number formed by combining degrees of all clusters in the sequential order. Find the total number of possible combinations where Rubrik's Super Cluster is in a healthy state.

Since the answer can be enormous, print the count modulo 10^9 + 7

### **Input:**
First line contains a number T denoting the number of test cases.\
Next line contains a number N denoting the number of Clusters.\
Next line contains N space separated values denoting the Degree of Cluster (A[]).

### **Output:**
For each test case, Print the total number of possible combinations for a Healthy Super Cluster.

### **Constraints:**
1 <= T <= 100\
1 <= N <= 10^4\
0 <= A[] <= 9

### **Sample Input**
    2
    2
    ? 5
    3
    5 ? 7

### **Sample Output**
    1
    1

### **Sample Explanation**
**Test case 1**\
The possible combinations are\
?5 --> 05 15 25 35 45 55 65 75 85 95\
05 % 13 = 5

# Solution
### **C++**
```cpp
#include <iostream>
#include <vector>
#define mod 1000000007
#define ll long long

using namespace std;

void print(vector<vector<int> > nodes) {
    for(auto i : nodes) {
        for(auto m : i) {
            cout << m << " ";
        } cout << endl;
    } cout << endl;
}

int expMod13(int dig, int expo) {
    int E = 10;
    while(expo) {
        if(expo & 1) {
            dig *= E;
            dig %= 13;
        } E *= E;
        E %= 13;
        expo >>= 1;
    } return dig;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        char x;
        cin >> n;
        vector<vector<int> > nodes(n, vector<int>(13, 0));
        for(int i = 1; i <= n; i++) {
            cin >> x;
            if(x == '?') {
                for(int d = 0; d < 10; d++)
                    ++nodes[i - 1][expMod13(d, n - i)];
            } else {
                int d = x - '0';
                ++nodes[i - 1][expMod13(d, n - i)];
            }
        } print(nodes);
        while(n != 1) {
            vector<vector<int> > merged((n + 1) / 2, vector<int>(13, 0));
            for(int i = 0; i < n; i += 2) {
                for(int m1 = 0; m1 < 13; m1++) {
                    for(int m2 = 0; m2 < 13; m2++) {
                        if(i + 1 < n)
                            merged[i / 2][(m1 + m2) % 13] += nodes[i][m1] * nodes[i + 1][m2];
                        else
                            merged[i / 2] = nodes[i];
                    }
                } 
            } nodes = merged;
            n = nodes.size();
        }
        print(nodes);
    }
}
```