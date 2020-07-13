// https://www.hackerrank.com/challenges/lilys-homework/problem
// Wrong Answer

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the lilysHomework function below.
int lilysHomework(vector<int> arr) {
    int count1=0,count2=0;
    long long sum1=0,sum2=0;
    vector<int> a(arr);
    sort(a.begin(),a.end());
    for(int i=1;i<a.size();i++)
        sum1+=abs(a[i]-a[i-1]);
    for(int i=0;i<arr.size();i++)
        if(arr[i] != a[i])
            ++count1;
    sort(a.rbegin(),a.rend());
    for(int i=1;i<a.size();i++)
        sum2+=abs(a[i]-a[i-1]);
    for(int i=0;i<arr.size();i++)
        if(arr[i] != a[i])
            ++count2;
    if(sum1<sum2)
        return (count1+1)/2;
    else if(sum2>sum1)
        return (count2+1)/2;
    else
        return min((count1+1)/2,(count2+1)/2);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = lilysHomework(arr);

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
