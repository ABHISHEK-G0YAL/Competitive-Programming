// https://www.hackerrank.com/challenges/strange-advertising/problem
// Accepted

#include <bits/stdc++.h>

using namespace std;

// Complete the viralAdvertising function below.
int viralAdvertising(int n)
{
    int cum=0,p=5;
    for(int i=1;i<=n;i++)
    {
        cum+=p/2;
        p=p/2*3;
    }
    return cum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = viralAdvertising(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
