// https://www.hackerrank.com/challenges/organizing-containers-of-balls/problem

#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Complete the organizingContainers function below.
string organizingContainers(vector<vector<int>> container) {
    vector<ll> row_sums,column_sums;
    for(int i=0;i<container.size();i++) {
        ll row_sum=0,col_sum=0;
        for(int j=0;j<container.size();j++) {
            row_sum+=container[i][j];
            col_sum+=container[j][i];
        } row_sums.push_back(row_sum);
        column_sums.push_back(col_sum);
    } sort(row_sums.begin(),row_sums.end());
    sort(column_sums.begin(),column_sums.end());
    if(row_sums==column_sums)
        return "Possible";
    else return "Impossible";
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        vector<vector<int>> container(n);
        for (int i = 0; i < n; i++) {
            container[i].resize(n);
            for (int j = 0; j < n; j++) {
                cin >> container[i][j];
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        string result = organizingContainers(container);
        fout << result << "\n";
    }
    fout.close();
    return 0;
}
