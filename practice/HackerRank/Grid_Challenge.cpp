// https://www.hackerrank.com/challenges/grid-challenge/problem

#include <bits/stdc++.h>

using namespace std;

bool cmp(string a, string b) {
    for(int i = 0; i < a.size(); i++)
        if(a[i] < b[i])
            return true;
    return false;
}
string gridChallenge(vector<string> grid) {
    for(auto &s : grid)
        sort(s.begin(), s.end());
    if(is_sorted(grid.begin(), grid.end(), cmp))
        return "YES";
    else
        return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<string> grid(n);

        for (int i = 0; i < n; i++) {
            string grid_item;
            getline(cin, grid_item);

            grid[i] = grid_item;
        }

        string result = gridChallenge(grid);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
