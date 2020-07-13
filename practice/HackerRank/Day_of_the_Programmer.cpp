// https://www.hackerrank.com/challenges/day-of-the-programmer/problem

#include <bits/stdc++.h>

using namespace std;

void solve(int year){
    // Complete this function
    if(year==1918)
        cout<<"26.09.1918";
    else if((year<1918 && year%4==0) || (year>1918 && (year%400==0 ||(year%100!=0 && year%4==0))))
        cout<<"12.09."<<year;
    else
        cout<<"13.09."<<year;
}

int main() {
    int year;
    cin >> year;
    solve(year);
    return 0;
}
