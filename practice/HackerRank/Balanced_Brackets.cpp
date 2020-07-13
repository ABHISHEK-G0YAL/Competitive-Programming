// https://www.hackerrank.com/challenges/balanced-brackets/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) {
  stack<char> c;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '{' || s[i] == '(' || s[i] == '[')
      c.push(s[i]);
    else if (!c.empty() && s[i] - c.top() < 3)
      c.pop();
    else
      return "NO";
  }
  if (c.empty())
    return "YES";
  else
    return "NO";
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  int t;
  cin >> t;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int t_itr = 0; t_itr < t; t_itr++) {
    string s;
    getline(cin, s);

    string result = isBalanced(s);

    fout << result << "\n";
  }

  fout.close();

  return 0;
}
