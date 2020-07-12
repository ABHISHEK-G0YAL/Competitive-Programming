// https://www.hackerrank.com/challenges/mandragora/problem
// Accepted

#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<string> split_string(string);

// Complete the mandragora function below.
long mandragora(vector<ll> h) {
    ll n=h.size();
    sort(h.rbegin(),h.rend());
    ll e,max=h[0]*n;
    for(ll i=1;i<n;i++) {
        h[i]+=h[i-1];
        e=h[i]*(n-i);
        if(e>max)
            max=e;
    }
    return max;
}
int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string H_temp_temp;
        getline(cin, H_temp_temp);

        vector<string> H_temp = split_string(H_temp_temp);

        vector<ll> H(n);

        for (int i = 0; i < n; i++) {
            int H_item = stoi(H_temp[i]);

            H[i] = H_item;
        }

        long result = mandragora(H);

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
