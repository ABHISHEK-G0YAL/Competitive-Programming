#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        float a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        int pens = int(ceil(a / c));
        int pencils = int(ceil(b / d));
        if(pens + pencils <= e)
            cout << pens << " " << pencils << endl;
        else
            cout << -1 << endl;
    }
}