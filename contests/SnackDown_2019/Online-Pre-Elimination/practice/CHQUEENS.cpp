// https://www.codechef.com/SNCKPE19/problems/CHQUEENS/
// wrong answer

#include <iostream>
#define P2(a) (a*(a-1))
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,m,x,y,s=0,k=0;
        cin>>n>>m>>x>>y;
        if(n>m) {
            swap(n,m);
            swap(x,y);
        }
        s=s+((n-1)*P2(m));
        s=s+((m-1)*P2(n));
        for(int i=2;i<=n;i++) {
            s=s+(4*P2(i));
        }
        s=s+((2*((m-n)-1))*P2(n));
        s=s+P2(x-1);
        s=s+P2(n-x);
        s=s+P2(y-1);
        s=s+P2(m-y);
        cout << s << endl;
    }
}