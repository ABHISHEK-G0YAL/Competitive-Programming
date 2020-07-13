// https://www.hackerrank.com/challenges/strange-code/problem

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the strangeCounter function below.
 */
long strangeCounter(long t) {
    /*
     * Write your code here.
     */
    long i,count=0,T;
    for(i=1;3*i<t;i=2*i+1)++count;
    i=(i-1)/2;
    t=t-3*i;
    T=3*pow(2,count);
    //cout<<i<<" "<<count<<" "<<t<<" "<<T<<endl;
    return T-t+1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    long t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = strangeCounter(t);

    fout << result << "\n";

    fout.close();

    return 0;
}
