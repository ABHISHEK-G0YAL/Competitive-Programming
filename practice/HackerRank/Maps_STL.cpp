// https://www.hackerrank.com/challenges/cpp-maps/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    map<string,int> marksheet;
    string name;
    int n,type,marks;
    cin>>n; while(n--) {
        cin>>type;
        if(type==1) {
            cin>>name>>marks;
            marksheet[name]+=marks;
        } else if(type==2) {
            cin>>name;
            marksheet.erase(name);
        } else {
            cin>>name;
            cout<<marksheet[name]<<endl;
        }
    } return 0;
}
