// https://www.hackerrank.com/challenges/funny-string/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the funnyString function below.
string funnyString(string s) {
    int n=s.length();
    for(int i=1;i<n+1/2;i++)
        if(abs(s[i]-s[i-1])!=abs(s[n-i-1]-s[n-i]))
            return "Not Funny";
    return "Funny";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        string result = funnyString(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
