// https://www.hackerrank.com/challenges/gem-stones/problem
// Accepted

#include <bits/stdc++.h>

using namespace std;

// Complete the gemstones function below.
int gemstones(vector<string> arr) {
    vector<bool> gem(26,true);
    for(int i=0;i<arr.size();i++) {
        bool boo[26]={};
        for(int x=0;x<arr[i].length();x++)
            boo[arr[i][x]-'a']=true;
        for(int a=0;a<26;a++)
            gem[a]=gem[a]&boo[a];
    } int gems=0;
    for(int a=0;a<26;a++)
        gems+=gem[a];
    return gems;
}
int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        string arr_item;
        getline(cin, arr_item);
        arr[i] = arr_item;
    }
    int result = gemstones(arr);
    fout << result << "\n";
    fout.close();
    return 0;
}
