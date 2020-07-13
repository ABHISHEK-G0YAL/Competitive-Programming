// https://www.hackerrank.com/challenges/find-digits/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the findDigits function below.
int findDigits(int n)
{
    int d,i,N=n,count=0;
    for(i=log10(n);i>=0;i--)
    {
        d=n%10;
        n=n/10;
        if(d!=0 && N%d==0)
            ++count;
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = findDigits(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
