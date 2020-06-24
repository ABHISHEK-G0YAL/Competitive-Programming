//This is The Coding Area

#include <bits/stdc++.h>
using namespace std;
string one[] = { "", "One ", "Two ", "Three ", "Four ", "Five ",
                "Six ", "Seven ", "Eight ", "Nine ", "Ten ", "Eleven ",
                "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ",
                "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen " };
string ten[] = { "", "", "Twenty ", "Thirty ", "Forty ", "Fifty ",
                "Sixty ", "Seventy ", "Eighty ", "Ninety " };
string numToWords(int n, string s)
{
    string str = "";
    if (n > 19)
        str += ten[n / 10] + one[n % 10];
    else
        str += one[n];
    if (n)
        str += s;
    return str;
}
string convertToWords(long n){
    string out;
    out += numToWords((n / 10000000), "Crore ");
    out += numToWords(((n / 100000) % 100), "Lakh ");
    out += numToWords(((n / 1000) % 100), "Thousand ");
    out += numToWords(((n / 100) % 10), "Hundred ");
    out += numToWords((n % 100), "");
    return out;
}
int main()
{
    int a,b;
    cin>>a>>b;
    if(a>b)
    {
        a=a+b;
        b=a-b;
        a=a-b;
    }
    else if(a==b)
    {
        cout<<a;
        return 0;
    }
    while(1)
    {
        if( (a+b>99999))
        {
            cout<<"Out of bounds";
            break;
        }
        string sa=convertToWords(a);
        string sb=convertToWords(b);
        if(sa>sb)
        {
            cout<<a+b;
            break;
        }
        else
        {
            a*=2;
            b*=2;
        }
    }
    return 0;
}

//https://www.geeksforgeeks.org/program-to-convert-a-given-number-to-words-set-2/
//:p
