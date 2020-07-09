// https://www.hackerrank.com/challenges/30-review-loop/problem
// Accepted

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int i,t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
        for(i=0;i<str.length();i+=2)
            cout << str[i];
        cout << " ";
        for(i=1;i<str.length();i+=2)
            cout << str[i];
        cout << "\n";
    }
    return 0;
}
