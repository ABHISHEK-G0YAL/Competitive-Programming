#include <bits/stdc++.h>

using namespace std;

int primeCount(long n)
{
    bool arr[100000]={};
    int x=n/100000,count=0,i,j,k,s;
    vector<int> prime;
    n=(n+1)%100000;
    arr[0]=true;
    arr[1]=true;
    for(i=0;i<x;i++)
    {
        for(j=i*100000;j<=sqrt(100000*(i+1));j++)
        {
            if(!arr[j-(i*100000)])
            {
                k=2;
                while((j*k)<(100000*(i+1)))
                {
                    arr[(j*k)-(i*100000)]=true;
                    ++k;
                }
            }
        }
        for(s=0;s<100000;s++)
            if(!arr[s])
                prime.push_back(s);
        for(s=0;s<100000;s++)
            arr[s]=false;
        for(s=0;s<prime.size();s++)
        {
            int k=ceil(j/prime[s]);
            while(k*prime[s]<=j+9999)
            {
                arr[(k*prime[s])-j]=true;
                ++k;
            }
        }
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = primeCount(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
