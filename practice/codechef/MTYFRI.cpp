// https://www.codechef.com/MAY18A/problems/MTYFRI

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, k, summ, sumt;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        int n1 = (n + 1) / 2, n2 = n / 2;
        int m[n1], t[n2];
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0)
                cin >> m[i / 2];
            else
                cin >> t[i / 2];
        }
        sort(m, m + n1, greater<int>());
        sort(t, t + n2);
        for(int i = 0; i < k and i < n2; i++)
            if(m[i] > t[i])
                swap(m[i], t[i]);
        summ = accumulate(m, m + n1, 0);
        sumt = accumulate(t, t + n2, 0);
        if(sumt > summ)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}