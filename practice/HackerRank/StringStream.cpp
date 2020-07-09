// https://www.hackerrank.com/challenges/c-tutorial-stringstream/problem
// Accepted

#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
    int integer; char ch;
    vector<int> integers;
    stringstream ss(str);
    while(ss>>integer) {
        integers.push_back(integer);
        ss>>ch;
    }
    return integers;
}

int main() {
    string str;
    cin>>str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++)
        cout << integers[i] << "\n";
    return 0;
}

