### Jacklin, a math teacher at MathWorld, is preparing to administer a test to her class. The students will evaluate an equation that consists of "+", "-" and "*" operators. She will award a grade of '5' for a correct answer and a grade of '2' for a partially-correct answer featuring a mistake in the application of the BODMAS rule. If a student's answer is wholly incorrect, the student will receive a grade of '0'.
<br>

### Write an algorithm to help Jacklin find the total class score for the given question, assuming every student has answered the question.
<br>

## Input
* The first line of the input consists of a string S, representing the equation to be evaluated.
* The second line consists of an integer N, representing the total number of students.
* The last line consists of N space-separated integers - arr1, arr2, .....arrN, representing the answers given by the students.

## Output
* Print an integer representing the total class score for the given equation.

## Constraints
* 0 <= N <= 1000
* 1 <= len <= 30; where len is the length of S
* -10^9 <= arr1, arr2, .....arrN <= 10^9

## Note
* The string is the combination of number and operators +, - and *.
* A string always begins and ends with a number.
* No two operators occur consecutively in the equation.

## Example

### Input:
    5*4-3*2
    4
    -10 10 14 90

### Output:
    9


## Explanation:
* Step 1: According to BODMAS,<br>
Correct answer = 14<br>
Partially-correct answers = -10, 10, 34
* Step 2: Grades awarded to the students by the teacher = 2, 2, 5, 0
* Step 3: So, total grades for the class is 2+2+5 So, the output is 9.
<br>
<br>
<br>

# Solution
### C++
```cpp
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
```