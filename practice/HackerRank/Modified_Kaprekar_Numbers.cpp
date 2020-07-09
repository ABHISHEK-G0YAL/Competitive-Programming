// https://www.hackerrank.com/challenges/kaprekar-numbers/problem
// Accepted

#include <bits/stdc++.h>

using namespace std;

vector <int> kaprekarNumbers(int p, int q) {
    // Complete this function
    vector <int> modifiedkaprekarnumbers;
    long square;int d;
    for(int i=p;i<=q;i++)
    {
        square=pow(i,2);
        //cout<<square<<" ";
        d=log10(square)+1;
        //cout<<d<<" ";
        //cout<<(square/(int)pow(10,d/2))<<" ";
        if(i==((square/(int)pow(10,(d+1)/2))+(square%(int)pow(10,(d+1)/2))))
            modifiedkaprekarnumbers.push_back(i);
    }
    if(modifiedkaprekarnumbers.size()==0)
        cout<<"INVALID RANGE";
    return modifiedkaprekarnumbers;
}

int main() {
    int p;
    cin >> p;
    int q;
    cin >> q;
    vector <int> result = kaprekarNumbers(p, q);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? " " : "");
    }
    cout << endl;


    return 0;
}
