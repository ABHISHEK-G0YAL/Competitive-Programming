// https://www.hackerrank.com/challenges/c-tutorial-functions/problem

#include <iostream>
using namespace std;

int max_of_four(int a, int b, int c, int d) {
    int max=d;
    if(a>max) max=a;
    if(b>max) max=b;
    if(c>max) max=c;
    return max;
}
int main() {
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<max_of_four(a,b,c,d);
    return 0;
}

