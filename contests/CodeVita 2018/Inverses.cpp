//This is The Coding Area
#include <iostream>
using namespace std;
int phi(int n)
{    
    int result = n;   // Initialize result as n

    // Consider all prime factors of n and subtract their
    // multiples from result
    for (int p=2; p*p<=n; ++p)
    {
        // Check if p is a prime factor.
        if (n % p == 0)
        {
            // If yes, then update n and result 
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }

    // If n has a prime factor greater than sqrt(n)
    // (There can be at-most one such prime factor)
    if (n > 1)
        result -= result / n;
    return result;
}
int main()
{
    int n;
    cin>>n;
    cout<<phi(n);
    return 0;
}

//https://cs.stackexchange.com/questions/88877/time-complexity-of-euler-totient-function
//was too easy , just a direct question