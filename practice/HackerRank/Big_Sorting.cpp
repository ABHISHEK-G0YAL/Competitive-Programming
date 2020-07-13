// https://www.hackerrank.com/challenges/big-sorting/problem

#include <bits/stdc++.h>

using namespace std;

bool isSmall(string a, string b) {
    if(a.length() < b.length()) return true;
    else if(a.length() > b.length()) return false;
    else if(a < b) return true;
    else return false;
}

// Complete the bigSorting function below.
vector<string> bigSorting(vector<string> unsorted) {
    sort(unsorted.begin(),unsorted.end(),isSmall);
    return unsorted;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> unsorted(n);

    for (int i = 0; i < n; i++) {
        string unsorted_item;
        getline(cin, unsorted_item);

        unsorted[i] = unsorted_item;
    }

    vector<string> result = bigSorting(unsorted);

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
