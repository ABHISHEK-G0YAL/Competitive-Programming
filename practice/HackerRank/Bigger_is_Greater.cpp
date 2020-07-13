// https://www.hackerrank.com/challenges/bigger-is-greater/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the biggerIsGreater function below.
string biggerIsGreater(string w) {
    for(int i=w.length()-1;i>=0;i--) {
        for(int j=w.length()-1;j>i;j--) {
            if(w[j]>w[i]) {
                swap(w[j],w[i]);
                sort(w.begin()+i+1,w.end());
                return w;
            }
        }
    }
    return "no answer";
}
int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);
        fout << biggerIsGreater(w) << "\n";
    }
    fout.close();
    return 0;
}
