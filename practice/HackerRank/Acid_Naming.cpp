// https://www.hackerrank.com/contests/w36/challenges/acid-naming/problem
// Accepted

#include <bits/stdc++.h>

using namespace std;

string acidNaming(string acid_name) {
    // Complete this function
    if(acid_name.substr(acid_name.length()-2)=="ic")
    {
        if(acid_name.substr(0,5)=="hydro")
            return "non-metal acid";
        else
            return "polyatomic acid";
    }
    else
        return "not an acid";
}

int main() {
    int n;
    cin >> n;
    for(int a0 = 0; a0 < n; a0++){
        string acid_name;
        cin >> acid_name;
        string result = acidNaming(acid_name);
        cout << result << endl;
    }
    return 0;
}
