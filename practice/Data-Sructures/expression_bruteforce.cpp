// WAP to find expression whose result is 100 using four 7s and one 1
// works in linux

#include <bits/stdc++.h>
using namespace std;

vector<char> ops = {'+', '-', '-', '*', '/', '/'};

void print(list<pair<double, string> > li) {
    for(auto i : li)
        cout << '(' << i.second << " = " << i.first << "), ";
    cout << "size= " << li.size() << endl;
}

void solve(list<pair<double, string> > &li, double x) {
    if(li.size() == 1) {
        pair<double, string> s = *li.begin();
        if(s.first == x)
            cout << s.second << " = " << s.first << endl;
        return;
    }
    set<pair<pair<double, string>, pair<double, string> > > history;
    for(auto pa = li.begin(); pa != li.end(); pa++) {
        for(auto pb = next(pa); pb != li.end(); pb++) {
            pair<double, string> a = *pa;
            pair<double, string> b = *pb;
            if(history.count({a, b}))
                continue;
            pb = li.erase(pb);
            pa = li.erase(pa);
            for(char op : ops) {
                if(op == '+')
                    pb = li.insert(pb, {a.first + b.first, "(" + a.second + " " + op + " " + b.second + ")"});
                else if(op == '-')
                    pb = li.insert(pb, {a.first - b.first, "(" + a.second + " " + op + " " + b.second + ")"});
                else if(op == '*')
                    pb = li.insert(pb, {a.first * b.first, "(" + a.second + " " + op + " " + b.second + ")"});
                else
                    pb = li.insert(pb, {a.first / b.first, "(" + a.second + " " + op + " " + b.second + ")"});
                solve(li, x);
                swap(a, b);
                pb = li.erase(pb);
            }
            pa = li.insert(pa, a);
            pb = li.insert(pb, b);
            history.insert({a, b});
        }
    }
}

int main() {
    list<pair<double, string> > li;
    vector<int> v = {7, 7, 7, 7, 1};
    // vector<int> v = {1, 2, 3, 4};
    for(auto i : v)
        li.push_back({i, to_string(i)});
    double x = 100;
    solve(li, x);
}

// output in WSL
// buntu@OMEN:/mnt/d/kubu$ g++ opBruteforce.cpp
// buntu@OMEN:/mnt/d/kubu$ ./a.out
// ((7 + (1 / 7)) * (7 + 7)) = 100
// ((7 + (1 / 7)) * (7 + 7)) = 100
// ((7 + (1 / 7)) * (7 + 7)) = 100