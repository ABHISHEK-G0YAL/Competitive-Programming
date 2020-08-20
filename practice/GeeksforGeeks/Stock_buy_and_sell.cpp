// https://practice.geeksforgeeks.org/problems/stock-buy-and-sell2615/1

// { Driver Code Starts


// Program to find best buying and selling days
#include <bits/stdc++.h>

using namespace std;

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int *, int);

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, i;
        cin >> n;
        int price[n];
        for (i = 0; i < n; i++) cin >> price[i];
        // function call
        stockBuySell(price, n);
    }
    return 0;
}
// } Driver Code Ends


// User function template for C++

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int price[], int n) {
    int i = 1;
    bool noprofit = true;
    while(i < n) {
        while(i < n and price[i] <= price[i - 1])
            ++i;
        int buy = i - 1;
        if(i == n)
            break;
        while(i < n and price[i - 1] <= price[i])
            ++i;
        int sell = i - 1;
        cout << '(' << buy << ' ' << sell << ')' << ' ';
        noprofit = false;
    }
    if(noprofit)
        cout << "No Profit";
    cout << endl;
}