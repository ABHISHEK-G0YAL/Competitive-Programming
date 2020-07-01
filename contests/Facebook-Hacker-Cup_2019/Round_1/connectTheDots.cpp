// https://www.facebook.com/hackercup/problem/2390352741015547/
// incomplete code

#include <bits\stdc++.h>
#define MAX 800005
#define ll long long
using namespace std;
class coordinate {
public:
    ll x=0, y=0;
}; coordinate dot[MAX];
int main() {
    ll t, n, h, v;
    coordinate a, b, c, d;
    cin >> t;
    for(ll x = 1; x <= t; x++) {
        cin >> n >> h >> v;
        cin >> dot[0].x >> dot[1].x >> a.x >> b.x >> c.x >> d.x;
        cin >> dot[0].y >> dot[1].y >> a.y >> b.y >> c.y >> d.y;
        dot[0].x %= d.x; dot[1].x %= d.x; a.x %= d.x; b.x %= d.x; c.x %= d.x;
        dot[0].y %= d.y; dot[1].y %= d.y; a.y %= d.y; b.y %= d.y; c.y %= d.y;
        for(ll i = 2; i < n; i++) {
            dot[i].x = (((a.x * dot[i-2].x) % d.x) + ((b.x * dot[i-1].x) % d.x) + c.x) % d.x;
            dot[i].y = (((a.y * dot[i-2].y) % d.y) + ((b.y * dot[i-1].y) % d.y) + c.y) % d.y;
        } sort(dot, dot + n);
        for(ll i = 0; i < n; i++) {
			cout<<dot[i].x<<" "<<dot[i].y<<endl;
		}
	}
}