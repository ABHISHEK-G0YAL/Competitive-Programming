#include <iostream>
using namespace std;

int main() {
    int t, ones;
    string s;
    cin >> t;
    while(t--) {
        cin >> s;
        ones = 0;
        for(auto i : s) ones += (i - '0');
        cout << (ones % 2 ? "WIN" : "LOSE") << endl;
    }
}