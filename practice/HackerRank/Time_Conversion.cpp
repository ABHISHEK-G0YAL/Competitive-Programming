// https://www.hackerrank.com/challenges/time-conversion/problem

#include <bits/stdc++.h>

using namespace std;

void timeConversion(int h, int m, int s, char ss[2]) {
    // Complete this function
    if(ss[0]=='A' && h==12)
    printf("%02d:%02d:%02d",0,m,s);
    else if(ss[0]=='A')
    printf("%02d:%02d:%02d",h,m,s);
    else if(ss[0]=='P' && h==12)
    printf("%02d:%02d:%02d",h,m,s);
    else if(ss[0]=='P')
    printf("%02d:%02d:%02d",h+12,m,s);
}

int main() {
    int h,m,s;char ss[2];
    scanf("%2d:%2d:%2d%2s",&h,&m,&s,ss);
    timeConversion(h,m,s,ss);
    return 0;
}
