// https://www.hackerrank.com/challenges/birthday-cake-candles/problem

#include <bits/stdc++.h>

using namespace std;

int birthdayCakeCandles(int n, vector <int> ar) {
    // Complete this function
    int max=ar[0],count=0;
    for(int i=0;i<n;i++)
    {
        if(ar[i]>max)
        {
            max=ar[i];
            count=0;
        }
        if(ar[i]==max)
            count+=1;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    int result = birthdayCakeCandles(n, ar);
    cout << result << endl;
    return 0;
}
