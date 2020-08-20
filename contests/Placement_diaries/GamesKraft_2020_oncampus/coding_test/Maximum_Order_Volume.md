# 2. Maximum Order Volume

During the day, a supermarket will receive calls from customers who want to place orders. The supermarket manager knows in advance the number of calls that will be attempted, the start time, duration and order volume for each call. Only one call can be in progress at any one time, and if a call is not answered, the 2 caller will not call back. The manager must choose which calls to service in order to 3 maximize order volume. Determine that maximum order volume. 

### **Example**
    start = [10, 5, 15, 18, 30]
    duration = [30, 12, 20, 35, 35]
    volume = [50, 51, 20, 25, 10]

#### **The above data as a table:**

| Caller | Start time | Duration | Order volume |
|:------:|:----------:|:--------:|:------------:|
|    1   |     10     |    30    |      50      |
|    2   |      5     |    12    |      51      |
|    3   |     15     |    20    |      20      |
|    4   |     18     |    35    |      25      |
|    5   |     30     |    35    |      10      |

The first call will start at time = 10, and last until time = 40.\
The second call will start at time = 5, and last until time = 17.\
The third call will start at time = 15, and last until time = 35.\
The fourth call will start at time = 18, and last until time = 53.\
The fifth call will start at time = 30, and last until time = 65. 

The first call completely overlaps the second and third calls, and partially overlaps the fourth and fifth calls. Choosing calls that do not overlap, answering the 2nd and 4th calls will lead to the maximum total order volume of 51 + 25 = 76.

### **Function Description**
Complete the function *phoneCalls* in the editor below.

*phoneCalls* has the following parameter(s):

    int start[n]: the start times of each call
    int duration[n]: the durations of each call
    int volume[n]: the volumes of each order
 
### **Returns**
    int: the maximum possible volume of orders that can be received.

### **Constraints**
* 1 <= n <= 10^5
* 1  <= start[i] <= 10^9
* 1 <= duration[i] <= 10^9
* 1 <= volume[i] <= 10^3

### **Sample Case 0**
Sample Input For Custom Testing

    STDIN      Function
    _____      ________
    3       -> start[] size n = 3
    1       -> start[] = [ 1, 2, 4 ]
    2
    4
    3       -> duration[] size n = 3
    2       -> duration[] = [ 2, 2, 1 ]
    2
    1
    3       -> volume[] size n = 3
    1       -> volume[] = [ 1, 2, 3 ]
    2
    3
    
### **Sample Output**
    4

### **Explanation**
The calls happen in the intervals\
[1,3]\
[2,4]\
[4,5]\
The first and third calls together make up the order volume 4, and their intervals do not intersect.\
The first and second calls intersect, as do the second and third calls. Only one call from either of these pairs can be serviced. The most efficient calls to answer are the first and third with a total volume of 4.


# Solution
### **C++ [ recursion + memoisation ] O(n²)**
```cpp
#include <iostream>
using namespace std;

bool cmp_customer_by_end(customer c1, customer c2) {
    return c1.end <= c2.end;
}

class customer {
public:
    int start, duration, end, order_s;
    customer() {}
    customer(int s, int d, int o) {
        start = s;
        duration = d;
        end = s + d;
        order_s = o;
    }
};

unordered_map<int, unordered_map<int, int>> mem;
int solve(vector<customer> &cs, int i = 0, int last = 0) {
    if(i == int(cs.size()))
        return 0;
    if(mem.find(i) != mem.end() and mem[i].find(last) != mem[i].end())
        return mem[i][last];
    int a1 = 0, a2 = 0;
    if(last < cs[i].start)
        a1 = cs[i].order_s + solve(cs, i + 1, cs[i].end);
    a2 = solve(cs, i + 1, last);
    return mem[i][last] = max(a1, a2);
}

int order(vector<int> s, vector<int> d, vector<int> o) {
    mem.clear();
    int n = s.size();
    vector<customer> cs(n);
    for(int i = 0; i < n; ++i)
        cs[i] = customer(s[i], d[i], o[i]);
    sort(cs.begin(), cs.end(), cmp_customer_by_end);
    return solve(cs);
}
```