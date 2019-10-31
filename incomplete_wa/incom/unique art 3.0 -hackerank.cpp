#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int student(int begin,int end,vector<int> t)
{
    unordered_map<int, int> hm;
    int i,j,c=0;
    for(i=begin-1;i<end;i++)
    hm[t[i]]++;
    for(i=begin-1;i<end;i++)
        if(hm[t[i]]==1)
            ++c;
    return c;
}


int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string t_temp_temp;
    getline(cin, t_temp_temp);

    vector<string> t_temp = split_string(t_temp_temp);

    vector<int> t(n);

    for (int t_itr = 0; t_itr < n; t_itr++) {
        int t_item = stoi(t_temp[t_itr]);

        t[t_itr] = t_item;
    }

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string ij_temp;
        getline(cin, ij_temp);

        vector<string> ij = split_string(ij_temp);

        int i = stoi(ij[0]);

        int j = stoi(ij[1]);

        int result = student(i, j, t);

        cout << result << "\n";
    }

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

