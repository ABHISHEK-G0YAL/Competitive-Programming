// https://www.hackerrank.com/challenges/the-power-sum/problem
// Accepted

#include <bits/stdc++.h>

using namespace std;

// Complete the powerSum function below.
int powerSum(int x, int n, int i=1) {
    if(x==0 || pow(i,n)>x) return x==0;
    return powerSum(x-pow(i,n),n,i+1) + powerSum(x,n,i+1);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int X;
    cin >> X;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = powerSum(X, N);

    fout << result << "\n";

    fout.close();

    return 0;
}
