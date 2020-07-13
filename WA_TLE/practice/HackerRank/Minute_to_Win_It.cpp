// https://www.hackerrank.com/contests/w38/challenges/minute-to-win-it/problem
// Wrong Answer

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minuteToWinIt function below.
int minuteToWinIt(vector<long long> a, int k) {
    // Return the minimum amount of time in minutes.
    int n=a.size();
    vector<long long> b;
    long long pos=0,count=0,max=0;
    for(int i=1;i<n;i++)
    {
        b.push_back(a[i]-a[i-1]);
        if(b[i-1]==k)
            ++count;
        else
            count=0;
        if(count>max)
        {
            pos=i;
            max=count;
        }
    }
    int min=0;
    for(int i=pos-max;i>0;i--)
    {
        if(a[i]-a[i-1]!=k)
        {
            a[i-1]=a[i]-k;
            ++min;
        }
    }
    for(int i=pos;i<n-1;i++)
    {
        if(a[i+1]-a[i]!=k)
        {
            a[i+1]=a[i]+k;
            ++min;
        }
    }
    return min;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<long long> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    int result = minuteToWinIt(a, k);

    fout << result << "\n";

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
