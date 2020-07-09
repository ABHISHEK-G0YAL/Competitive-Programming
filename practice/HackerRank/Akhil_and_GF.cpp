// https://www.hackerrank.com/challenges/akhil-and-gf/problem
// Wrong Answer

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the solve function below.
int solve(long n, int m) {
    int num = 1;
    vector<int> initial, loop;
    for (int i = 0; i <= log10(m); i++) {
        initial.push_back(num);
        // cout << "i" << num << " ";
        num = (num * 10 + 1) % m;
    }
    loop.push_back(num);
    // cout << "l" << num << " ";
    num = (num * 10 + 1) % m;
    while (num != loop[0]) {
        loop.push_back(num);
        // cout << "l" << num << " ";
        num = (num * 10 + 1) % m;
    }
    // cout << endl;
    if (n <= initial.size())
        return initial[n - 1];
    else
        return loop[(n - initial.size() - 1) % loop.size()];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        long n = stol(nm[0]);

        int m = stoi(nm[1]);

        int result = solve(n, m);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
