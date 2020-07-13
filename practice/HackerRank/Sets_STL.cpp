// https://www.hackerrank.com/challenges/cpp-sets/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int n,type,val;
    cin >> n;
    set<int> s;
    while(n--) {
        cin>>type>>val;
        if(type==1) s.insert(val);
        else if(type==2) s.erase(val);
        else {
            set<int>::iterator it=s.find(val);
            if(it==s.end()) cout<<"No"<<endl;
            else cout<<"Yes"<<endl;
        }
    }
    return 0;
}



