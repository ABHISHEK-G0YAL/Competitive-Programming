// https://www.hackerrank.com/challenges/encryption/problem

#include <bits/stdc++.h>
using namespace std;

string encryption(string s) {
    s.erase(remove(s.begin(),s.end(),' '),s.end());
    int row=floor(sqrt(s.length())),col=ceil(sqrt(s.length()));
    if(row*col<s.length());
        row+=1;
    char c[col][row+1];
    memset(c,0,col*(row+1));
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            if(((i*col)+j)<s.length())
                c[j][i]=s[(i*col)+j];
    s.clear();
    for(int j=0;j<col;j++)
        s=s+c[j]+" ";
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
