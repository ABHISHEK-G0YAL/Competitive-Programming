#include <iostream>
using namespace std;

int main() {
    int t, a, b, c;
    cin >> t;
    while(t--) {
        cin >> a >> b >> c;
        int stones = 0;
        if(2 * b <= c)
            stones += 3 * b;
        else {
            stones += (c - (c & 1));
            c = c & 1;
            b -= stones / 2;
            stones += stones / 2;
            if(2 * a <= b)
                stones += 3 * a;
            else
                stones += ((b - (b & 1)) * 3) / 2;
        }
        cout << stones << endl;
    }
}