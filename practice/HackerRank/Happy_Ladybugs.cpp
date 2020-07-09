// https://www.hackerrank.com/challenges/happy-ladybugs/problem
// Accepted

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the happyLadybugs function below.
 */
string happyLadybugs(string b) {
    /*
     * Write your code here.
     */
    int l=b.length(),frequency[26]={0};
    bool us=false;
    for(int i=0;i<l;i++)
        if(b[i]!='_')
            ++frequency[b[i]-'A'];
        else
            us=true;
    for(int i=0;i<26;i++)
        if(frequency[i]==1)
            return "NO";
    if(us)
        return "YES";
    else
    {
        for(int i=1;i<l-1;i++)
            if(!(b[i-1]==b[i] || b[i]==b[i+1]))
                return "NO";
        if(b[0]==b[1] && b[l-2]==b[l-1])
            return "YES";
        else
            return "NO";
    }

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int g;
    cin >> g;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int g_itr = 0; g_itr < g; g_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string b;
        getline(cin, b);

        string result = happyLadybugs(b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
