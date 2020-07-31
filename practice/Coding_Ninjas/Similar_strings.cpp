// https://github.com/ABHISHEK-G0YAL/Competitive-Programming/blob/master/practice/Coding_Ninjas/Similar_strings.md

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