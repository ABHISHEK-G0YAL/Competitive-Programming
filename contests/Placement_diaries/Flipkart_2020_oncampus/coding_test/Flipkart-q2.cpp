#include <bits/stdc++.h>
using namespace std;

vector<int> vectorify(string s) {
    vector<int> ex;
    string t;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '-' or s[i] == '+' or s[i] == '*' or s[i] == '/') {
            t = s.substr(0, i);
            ex.push_back(stoi(t));
            ex.push_back(s[i]);
            s = s.substr(i + 1);
            i = 0;
        }
    }
    ex.push_back(stoi(s));
    return ex;
}

int eval(string e) {
    int n = e.length();
    for(int i = 0; i < n; i++) {
        if(e[i] == '+')
            return eval(e.substr(0, i)) + eval(e.substr(i+1));
        if(e[i] == '-')
            return eval(e.substr(0, i)) - eval(e.substr(i+1));
    }
    for(int i = 0; i < n; i++)
        if(e[i] == '/')
            return eval(e.substr(0, i)) / eval(e.substr(i+1));
    for(int i = 0; i < n; i++)
        if(e[i] == '*')
            return eval(e.substr(0, i)) * eval(e.substr(i+1));
    return stoi(e);
}

unordered_set<int> mem[30][30];
unordered_set<int> all_possible_answers(vector<int> &ex, int s, int e) {
    if(!mem[s][e].empty())
        return mem[s][e];
    if(s == e)
        return {ex[e]};
    unordered_set<int> a1, a2, a;
    for(int i = s; i < e; i+=2) {
        a1 = all_possible_answers(ex, s, i);
        a2 = all_possible_answers(ex, i+2, e);
        if(ex[i+1] == '+') {
            for(int i : a1)
                for(int j : a2)
                    a.insert(i+j);
        }
        else if(ex[i+1] == '-') {
            for(int i : a1)
                for(int j : a2)
                    a.insert(i-j);
        }
        else if(ex[i+1] == '*') {
            for(int i : a1)
                for(int j : a2)
                    a.insert(i*j);
        }
        else {
            for(int i : a1)
                for(int j : a2)
                    if(j != 0)
                        if(i % j == 0)
                            a.insert(i/j);
        }
    }
    return mem[s][e] = a;
}

int main() {
    string e;
    cin >> e;
    int correct_answer = eval(e);
    vector<int> ex = vectorify(e);
    int n;
    cin >> n;
    vector<int> answers(n);
    for(int &ans : answers)
        cin >> ans;
    unordered_set<int> possible_answers = all_possible_answers(ex, 0, ex.size() - 1);
    // for(int i : possible_answers) cout << i << " "; cout << endl;
    int score = 0;
    for(int ans : answers) {
        if(ans == correct_answer)
            score += 5;
        else
            if(possible_answers.find(ans) != possible_answers.end())
                score += 2;
    }
    cout << score << endl;
}

/*
30+5*3/5+11*3-2
6
64 32 20 94 40 25
*/