// https://www.hackerrank.com/challenges/sherlock-and-squares/problem

#include <bits/stdc++.h>

using namespace std;

int squares(int a, int b) {
    // Complete this function
    int i=ceil(sqrt(a));
    int j=sqrt(b);
    return j-i+1;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int a;
        int b;
        cin >> a >> b;
        int result = squares(a, b);
        cout << result << endl;
    }
    return 0;
}
