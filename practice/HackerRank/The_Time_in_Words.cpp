// https://www.hackerrank.com/challenges/the-time-in-words/problem
// Accepted

#include <bits/stdc++.h>

using namespace std;

string mins[] = {
    "o' clock",
    "one minute",
    "two minutes",
    "three minutes",
    "four minutes",
    "five minutes",
    "six minutes",
    "seven minutes",
    "eight minutes",
    "nine minutes",
    "ten minutes",
    "eleven minutes",
    "twelve minutes",
    "thirteen minutes",
    "fourteen minutes",
    "quarter",
    "sixteen minutes",
    "seventeen minutes",
    "eighteen minutes",
    "nineteen minutes",
    "twenty minutes",
    "twenty one minutes",
    "twenty two minutes",
    "twenty three minutes",
    "twenty four minutes",
    "twenty five minutes",
    "twenty six minutes",
    "twenty seven minutes",
    "twenty eight minutes",
    "twenty nine minutes",
    "half"
};
string hours[] = {
    "",      "one",   "two",  "three", "four",   "five",  "six",
    "seven", "eight", "nine", "ten",   "eleven", "twelve"
};
string timeInWords(int h, int m) {
    if(m==0) return hours[h]+" "+mins[m];
    else if(m<=30) return mins[m]+" past "+hours[h];
    else return mins[60-m]+" to "+hours[h+1];
}
int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    int h;
    cin >> h;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string result = timeInWords(h, m);
    fout << result << "\n";
    fout.close();
    return 0;
}
