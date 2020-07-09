// https://www.hackerrank.com/challenges/weighted-uniform-string/problem
// Accepted

#include <bits/stdc++.h>

using namespace std;

// Complete the weightedUniformStrings function below.
vector<string> weightedUniformStrings(string s, vector<int> queries) {
    int count=1;
    int max_uniform[26]={};
    vector<string> answers;
    max_uniform[s[0]-'a']=1;
    for(int i=1;i<s.length();i++) {
        if(s[i]==s[i-1]) ++count;
        else count=1;
        if(count>max_uniform[s[i]-'a'])
            max_uniform[s[i]-'a']=count;
    } for(int i=0;i<queries.size();i++) {
        for(int a=1;a<=26;a++) {
            if(queries[i]%a==0 && queries[i]/a<=max_uniform[a-1]) {
                answers.push_back("Yes");
                break;
            }
        } if(answers.size() != i+1)
            answers.push_back("No");
    } return answers;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[i] = queries_item;
    }

    vector<string> result = weightedUniformStrings(s, queries);

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
