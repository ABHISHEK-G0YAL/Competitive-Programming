// https://www.hackerrank.com/challenges/queens-attack-2/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the queensAttack function below.
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> ob) {
   int h_start=0,h_end=n+1,v_start=0,v_end=n+1,d1_start=max(r_q-c_q,0),d1_end=n+1-max(c_q-r_q,0),d2_start=max(0,r_q+c_q-n-1),d2_end=min(n+1,r_q+c_q);
   for(int i=0;i<k;i++) {
       if(ob[i][0]==r_q && ob[i][1]<c_q && h_start<ob[i][1]) h_start=ob[i][1];
       if(ob[i][0]==r_q && ob[i][1]>c_q && h_end>ob[i][1]) h_end=ob[i][1];
       if(ob[i][1]==c_q && ob[i][0]<r_q && v_start<ob[i][0]) v_start=ob[i][0];
       if(ob[i][1]==c_q && ob[i][0]>r_q && v_end>ob[i][0]) v_end=ob[i][0];
       if(abs(r_q-ob[i][0])==abs(c_q-ob[i][1])) {
           if(ob[i][0]<r_q && ob[i][1]<c_q && d1_start<ob[i][0]) d1_start=ob[i][0];
           if(ob[i][0]>r_q && ob[i][1]>c_q && d1_end>ob[i][0]) d1_end=ob[i][0];
           if(ob[i][0]<r_q && ob[i][1]>c_q && d2_start<ob[i][0]) d2_start=ob[i][0];
           if(ob[i][0]>r_q && ob[i][1]<c_q && d2_end>ob[i][0]) d2_end=ob[i][0];
       }
    }
    return h_end-h_start-2+v_end-v_start-2+d1_end-d1_start-2+d2_end-d2_start-2;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string r_qC_q_temp;
    getline(cin, r_qC_q_temp);

    vector<string> r_qC_q = split_string(r_qC_q_temp);

    int r_q = stoi(r_qC_q[0]);

    int c_q = stoi(r_qC_q[1]);

    vector<vector<int>> ob(k);
    for (int i = 0; i < k; i++) {
        ob[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> ob[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = queensAttack(n, k, r_q, c_q, ob);

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
