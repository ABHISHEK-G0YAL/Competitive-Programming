// https://www.hackerrank.com/challenges/bomber-man/problem
// Accepted

#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);
vector<string> bomberMan(int n,vector<string> grid) {
    string s(grid[0].length(),'O');
    vector<string> full(grid.size(),s);
    vector<string> grid1(full),grid3(full);
    for(int i=0;i<grid.size();i++) {
        for(int j=0;j<grid[0].size();j++) {
            if(grid[i][j]=='O') {
                grid3[i][j]='.';
                if(i+1 < grid.size()) grid3[i+1][j]='.';
                if(j+1 < grid[0].size()) grid3[i][j+1]='.';
                if(i > 0) grid3[i-1][j]='.';
                if(j > 0) grid3[i][j-1]='.';
            }
        }
    }
    for(int i=0;i<grid.size();i++) {
        for(int j=0;j<grid[0].size();j++) {
            if(grid3[i][j]=='O') {
                grid1[i][j]='.';
                if(i+1 < grid.size()) grid1[i+1][j]='.';
                if(j+1 < grid[0].size()) grid1[i][j+1]='.';
                if(i > 0) grid1[i-1][j]='.';
                if(j > 0) grid1[i][j-1]='.';
            }
        }
    }
    if(n==1) return grid;
    if(n%4==3) return grid3;
    if(n%4==1) return grid1;
    return full;
}
int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    string rcn_temp;
    getline(cin, rcn_temp);
    vector<string> rcn = split_string(rcn_temp);
    int r = stoi(rcn[0]);
    int c = stoi(rcn[1]);
    int n = stoi(rcn[2]);
    vector<string> grid(r);
    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);
        grid[i] = grid_item;
    }
    vector<string> result = bomberMan(n, grid);
    for (int i = 0; i < result.size(); i++) {
        fout << result[i];
        if (i != result.size() - 1) {
            fout << "\n";
        }
    }
    fout << "\n";
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
