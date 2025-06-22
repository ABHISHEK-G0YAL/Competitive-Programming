// https://www.hackerrank.com/challenges/password-cracker/problem

#include <bits/stdc++.h>
using namespace std;

unordered_map<string_view, string> memo;
string checkPassword(unordered_set<string_view> &pass_set, string_view loginAttempt) {
    if (loginAttempt.empty()) {
        return "";
    }
    if (memo.find(loginAttempt) != memo.end()) {
        return memo[loginAttempt];
    }
    string verified;
    for (int i = 1; i <= loginAttempt.size(); i++) {
        if (pass_set.find(loginAttempt.substr(0, i)) != pass_set.end()) {
            verified = checkPassword(pass_set, loginAttempt.substr(i));
            if (verified != "WRONG PASSWORD") {
                return memo[loginAttempt] = verified.empty() ?
                    string(loginAttempt.substr(0, i)) :
                    string(loginAttempt.substr(0, i)) + " " + verified;
            }
        }
    }
    return memo[loginAttempt] = "WRONG PASSWORD";
}

string checkPassword(vector<string> &passwords, string loginAttempt) {
    unordered_set<string_view> pass_set(passwords.begin(), passwords.end());
    memo.clear();
    return checkPassword(pass_set, loginAttempt);
}

string checkPasswordDP(vector<string> &passwords, string loginAttempt) {
    unordered_set<string_view> pass_set(passwords.begin(), passwords.end());
    int L = loginAttempt.size();
    vector<string> dp(L + 1, "WRONG PASSWORD"); // DP table
    dp[0] = ""; // Base case: empty string matches empty prefix

    for (int i = 1; i <= L; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] != "WRONG PASSWORD"
                && pass_set.find(loginAttempt.substr(j, i - j)) != pass_set.end()) {
                dp[i] = dp[j].empty() ?
                    string(loginAttempt.substr(j, i - j)) :
                    dp[j] + " " + string(loginAttempt.substr(j, i - j));
                break;
            }
        }
    }
    return dp[L];
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