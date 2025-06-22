# Similar strings

Ninja got a binary string S (binary string is a string that only consists of zeros and ones) from one of his friends. As we all know that Ninja loves binary strings and zeros, so he wants to create another string P (of the same length as S) which is similar to S.

A string P is said similar to string S if and only if, for every I and J ( 1<=I<=J<=|S|) the length of longest non-decreasing subsequence of both substrings P\[I.....J\] and S\[I.....J\] are equal to each other.

A subsequence of a string is a string formed by deleting some of its character’s( possibly none).

Since ninja also loves zeros, so he wants to choose the string P such that it satisfies the above condition and contains the maximum number of zeros in it.

Formally you have to output a string P that is of same length of S and similar to S and contains the maximum number of zeros.

### Input format:
    First line contains the integer T (number of test cases) (1<= T < =10^5). 
    Next t lines will contain the string s (1=< |s| <= 10^5).
    Sum of length of string S over all test cases will not exceed 10^6.

### Output format
    For every test case, print the string P in newline. 

### Sample input 1:
    2
    100
    111

### Sample Output 1:
    100
    000

### Explanation:
    In test case 1 we don’t need to change anything.
    In test case 2 we have chosen “000” because we want the maximum number of zeros (as the similarity condition also holds for the “111” or “001” or “011” but we need the one with maximum zeros and that is “000”

# Solution
```cpp
#include<bits/stdc++.h>
using namespace std;
int main() {
    int t, n, sum, i;
    cin >> t;
    while(t--) {
       	string str;
        cin >> str;
    	n = str.length();
    	sum = 0;
   		for(i = n - 1; i >= 0; i--) {
            if(str[i] == '0')
                sum += 1;
            else if(sum)
                sum -= 1;
            else
                str[i] = '0';
        }
    	cout << str << endl;
    }
}
```