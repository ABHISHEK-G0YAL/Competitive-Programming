// https://www.hackerrank.com/challenges/equal/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
void print(vector<int> a) {
  for (int i = 0; i < a.size(); i++)
    cout << a[i] << " ";
  cout << endl;
}
int equal_helper(vector<int> a,int min) {
  int n = a.size(), steps = 0;
  for (int i = 0; i < n; i++) {
    int diff = a[i] - min;
    int m = diff / 5;
    diff = diff % 5;
    steps += m;
    if (diff == 1 || diff == 2)
      steps += 1;
    else if (diff == 3 || diff == 4)
      steps += 2;
    a[i] = min;
  }
  return steps;
}
// Complete the equal function below.
int equal(vector<int> a) {
    sort(a.begin(), a.end());
    int min_steps=INT_MAX;
    for(int i=0;i<5;i++)
        min_steps=min(min_steps,equal_helper(a,a[0]-i));
    return min_steps;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
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

        int result = equal(arr);

        fout << result << "\n";
    }

    fout.close();

    return 0;}

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

    return splits;}
