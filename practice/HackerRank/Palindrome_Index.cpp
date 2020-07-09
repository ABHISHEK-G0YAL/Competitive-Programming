// https://www.hackerrank.com/challenges/palindrome-index/problem
// Accepted

#include <bits/stdc++.h>
using namespace std;

int isPalindrome(string s) {
    int n=s.length();
    for(int i=0;i<n/2;i++)
        if(s[i]!=s[n-i-1])
            return i;
    return -1;
}
int palindromeIndex(string s1) {
    string s2=s1;
    int n=s1.length();
    int ind=isPalindrome(s1);
    if(ind<0) return -1;
    s1.erase(ind,1);
    s2.erase(n-1-ind,1);
    int ind1=isPalindrome(s1);
    int ind2=isPalindrome(s2);
    if(ind1<0) return ind;
    else if(ind2<0) return n-1-ind;
    else return -1;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = palindromeIndex(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
