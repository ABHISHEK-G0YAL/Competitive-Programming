// https://www.hackerrank.com/challenges/counting-valleys/problem

#include <bits/stdc++.h>

using namespace std;

int countingValleys(int n, string s) {
    // Complete this function
    int level=0,count=0;
    bool flagold=false,flagnew;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='U')
            ++level;
        else
            --level;
        if(level<0)
            flagnew=true;
        else
            flagnew=false;
        if(flagold!=flagnew)
            ++count;
        flagold=flagnew;
    }
    return count/2;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int result = countingValleys(n, s);
    cout << result << endl;
    return 0;
}
