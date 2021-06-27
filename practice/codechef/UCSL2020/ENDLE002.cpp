// https://www.codechef.com/UCSL2020/problems/ENDLE002

#include <iostream>
#include <vector>
using namespace std;

class connection {
public:
    bool up, down, left, right;
};

vector<int> path;
vector<vector<bool>> visited;

void print_path(vector<vector<connection>> &grid, int i = 0, int j = 0) {
    int m = grid.size(), n = grid[0].size();
    if(i < 0 or j < 0 or i >= m or j >= n or visited[i][j])
        return;
    if(i * n + j + 1 == m * n) {
        for(int &i : path)
            cout << i << ' ';
        cout << m * n << endl;
        return;
    }
    path.push_back(i * n + j + 1);
    visited[i][j] = true;
    if(grid[i][j].up)
        print_path(grid, i - 1, j);
    if(grid[i][j].right)
        print_path(grid, i, j + 1);
    if(grid[i][j].down)
        print_path(grid, i + 1, j);
    if(grid[i][j].left)
        print_path(grid, i, j - 1);
    visited[i][j] = false;
    path.pop_back();
    return;
}

int main() {
    int m, n, pixel_no, r, c;
    cin >> m >> n;
    // connection grid[m][n];
    vector<vector<connection>> grid(m, vector<connection>(n));
    visited = vector<vector<bool>>(m, vector<bool>(n, false));
    for(int i = 0; i < m * n; i++) {
        cin >> pixel_no;
        pixel_no -= 1;
        r = pixel_no / n;
        c = pixel_no % n;
        cin >> grid[r][c].up >> grid[r][c].right >> grid[r][c].down >> grid[r][c].left;
    }
    print_path(grid);
}