# **Editorial**


##### **PROBLEM LINK:**

**[Contest](https://hack.codingblocks.com/contests/c/967/2347)**

**[Practice](https://hack.codingblocks.com/practice/p/406/2347)**

**Author: [Abhishek Goyal](https://www.hackerrank.com/Abhishek_G0YAL)**

**Editorialist: [Abhishek Goyal](https://www.hackerrank.com/Abhishek_G0YAL)**


##### **DIFFICULTY:**

Hard.


##### **PREREQUISITES:**

Dynamic programming, Backtracking.


##### **PROBLEM:**

Given the number of blocks to be coloured in each row and column. Find the number of ways to color the wall.


##### **Basic Naive Solution :**

A very basic solution to the problem is to bruteforce and count all the valid combinations. But the efficiency of this solution will be very bad. There are total **N x M** blocks. Each of which can be either a **0** or a **1**. This makes the time complexity of this solution to be **O(2<sup>N x M</sup>)**. This solution will roughly work till **N = 5** with only one test case. Here is this solution in **C++**.


##### **Code :**
    #include <bits/stdc++.h>
    using namespace std;

    int sum(vector<int> v) {
        int sum = 0;
        for(auto i : v)
            sum += i;
        return sum;
    }
    void print_wall(vector<string> wall) {
        for(auto i : wall) {
            for(auto j : i)
                cout << j << " ";
            cout << endl;
        }
    }
    void paint(vector<string> &wall, vector<int> &row, vector<int> &col, int &cnt, vector<string> &fvp, int block = 0) {
        int n = wall.size(), m = wall[0].size();
        int i = block / m, j = block % m;
        if(sum(row) + sum(col) == 0) {
            ++cnt;
            if(cnt == 1)
                fvp = wall;
            return;
        } if(block == n * m) return;
        paint(wall, row, col, cnt, fvp, block + 1);
        if(row[i] > 0 && col[j] > 0) {
            wall[i][j] = '1';
            row[i]--;
            col[j]--;
            paint(wall, row, col, cnt, fvp, block + 1);
            wall[i][j] = '0';
            row[i]++;
            col[j]++;
        }
    }
    int main() {
        int n, m, t;
        cin >> t;
        while(t--) {
            cin >> n >> m;
            vector<int> row(n), col(m);
            for(int i = 0; i < n; i++)
                cin >> row[i];
            for(int i = 0; i < m; i++)
                cin >> col[i];
            vector<string> wall(n, string(m, '0'));
            vector<string> first_valid_paint;
            int cnt_valid_paint = 0;
            paint(wall, row, col, cnt_valid_paint, first_valid_paint);
            if(cnt_valid_paint == 1)
                print_wall(first_valid_paint);
            else if(cnt_valid_paint == 0)
                cout << "No Possible Way\n";
            else
                cout << cnt_valid_paint << "\n";
        }
    }
##### **A Better Solution using Dynamic Programing :**

A better approach to the problem will be to solve it rowwise instead of solving it blockwise. We can do the work for a row and use the function recursively to do the work for other rows instead of doing it for just a block and calling the function to do it for all other blocks.

To implement this, we can first create a 2D DP array. **DP[x][y]** of this array stores a list of Binary Strings that have **y / x** bits set. For example, If **x = 3** & **y = 2** the DP Array will contain the **List - {“011”, “101”, “110”}** that is a list of all possible 3 sized binary strings that have 2 bits set. 

Creating this 2D array is very simple. First we can fill base case that is when **y = 0** , the number of set bits in a **x** bit number is **0**. So **DP[x][0] = {“00...00”}**, that is a **x** length string with all **‘0’**s. We can find all combinations of length **x** with **y** bits set by prefixing **‘0’** to all combinations of length **x - 1** with **y** bits set and **‘1’** to all combinations of length **x - 1** with **n - 1** bits set. 

After creating the DP array we can use backtracking to construct the solution rowwise. You must be thinking that how does this DP array help us in backtracking. But as you know we have a matrix of **N x M** size. So we have **N** rows of **M** size and we also know how much blocks are to be painted in each row. We can use this DP array to get **DP[M][R<sub>i</sub>]** that is list of binary strings of size **M** which will have **R<sub>i</sub>** bits set, in other words we have a list of all possible states of row of **M** size with **R<sub>i</sub>** blocks painted. We will use them one by one and call the function for the next row to be filled while checking that we do not exceed the number of blocks to be painted in each column. When the current row that we would be working on equals **N**, we will know that we have arrived at a valid solution. Here is this solution implemented in **C++**.


##### **Code :**
    #include <bits/stdc++.h>
    using namespace std;
    
    vector<string> DP[16][16];
    void nSetBits() {
        int k = 15;
        string str = "";
        for (int i = 0; i <= k; i++) {
            DP[i][0].push_back(str);
            str = str + char(0);
        }
        // DP[k][n] will store all k-bit numbers
        // with n-bits set
        for (int i = 1; i <= k; i++) {
            for (int n = 1; n <= i; n++) {
                for (string str : DP[i - 1][n])
                    DP[i][n].push_back(char(0) + str);
                for (string str : DP[i - 1][n - 1])
                    DP[i][n].push_back(char(1) + str);
            }
        }
    }
    int sum(vector<int> v) {
        int sum = 0;
        for(auto i : v)
            sum += i;
        return sum;
    }
    void print_wall(vector<string> wall) {
        for(auto i : wall) {
            for(int j : i)
                cout << j << " ";
            cout << "\n";
        }
    }
    void paint(vector<string> &wall, vector<int> &row, vector<int> &col, int &cnt, vector<string> &fvp, int i = 0) {
      // i is the current row
        int n = row.size(), m = col.size();
        if(i == n) {
            if(sum(row) + sum(col) == 0) {
                ++cnt;
                if(cnt == 1)
                    fvp = wall;
            } return;
        } int row_i = row[i];
        for(auto s : DP[m][row_i]) {
            row[i] = 0;
            wall[i] = s;
            vector<int> init_col(col);
            bool s_valid = true;
            for(int i = 0; i < col.size(); i++) {
                if(s[i]) {
                    if(col[i] > 0)
                        col[i]--;
                    else {
                        s_valid = false;
                        break;
                    }
                }
            }
            if(s_valid)
                paint(wall, row, col, cnt, fvp, i + 1);
            col = init_col;
            row[i] = row_i;
        }
    }
    int main() {
        nSetBits();
        int n, m, t;
        cin >> t;
        while(t--) {
            cin >> n >> m;
            vector<int> row(n), col(m);
            for(int i = 0; i < n; i++)
                cin >> row[i];
            for(int i = 0; i < m; i++)
                cin >> col[i];
            vector<string> wall(n, string(m, 0));
            vector<string> first_valid_paint;
            int cnt_valid_paint = 0;
            paint(wall, row, col, cnt_valid_paint, first_valid_paint);
            if(cnt_valid_paint == 1)
                print_wall(first_valid_paint);
            else if(cnt_valid_paint == 0)
                cout << "No Possible Way\n";
            else
                cout << cnt_valid_paint << "\n";
        }
    }