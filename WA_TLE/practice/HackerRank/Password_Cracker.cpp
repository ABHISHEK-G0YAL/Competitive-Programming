// https://www.hackerrank.com/challenges/password-cracker/problem
// Time Limit Exceded

#include <bits/stdc++.h>
using namespace std;

string checkPassword(unordered_set<string_view> &pass_set, string_view loginAttempt) {
    if (loginAttempt.empty()) {
        return "";
    }
    string verified;
    for (int i = 1; i <= loginAttempt.size(); i++) {
        if (pass_set.find(loginAttempt.substr(0, i)) != pass_set.end()) {
            verified = checkPassword(pass_set, loginAttempt.substr(i));
            if (verified != "WRONG PASSWORD") {
                return verified.empty() ?
                    string(loginAttempt.substr(0, i)) :
                    string(loginAttempt.substr(0, i)) + " " + verified;
            }
        }
    }
    return "WRONG PASSWORD";
}

string checkPassword(vector<string> &passwords, string loginAttempt) {
    unordered_set<string_view> pass_set(passwords.begin(), passwords.end());
    return checkPassword(pass_set, loginAttempt);
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<string> passwords(n);
        for (auto &password : passwords) {
            cin >> password;
        }
        string loginAttempt;
        cin >> loginAttempt;
        cout << checkPassword(passwords, loginAttempt) << endl;
    }
    return 0;
}