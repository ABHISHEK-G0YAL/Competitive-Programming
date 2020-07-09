// https://www.hackerrank.com/challenges/strong-password/problem
// Accepted

#include <bits/stdc++.h>
using namespace std;

int minimumNumber(int n, string pass) {
    bool type[4]={};
    for(int i=0;i<n;i++) {
        if(pass[i]>='0' && pass[i]<='9') type[0]=true;
        else if(pass[i]>='A' && pass[i]<='Z') type[1]=true;
        else if(pass[i]>='a' && pass[i]<='z') type[2]=true;
        else type[3]=true;
    } int cnt=0;
    for(int i=0;i<4;i++)
        if(!type[i]) cnt++;
    return max(cnt,6-n);
}
int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string password;
    getline(cin, password);
    int answer = minimumNumber(n, password);
    fout << answer << "\n";
    fout.close();
    return 0;
}
