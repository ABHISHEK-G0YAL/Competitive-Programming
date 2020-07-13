// 

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main()
{
    srand(time(0));
    int t=5;
    cout<<t<<endl;
    while(t--)
    {
        int n=90000+(rand()%10000)+1;
        int m=90000+(rand()%10000)+1;
        cout<<n<<" "<<m<<endl;
        for(int i=0;i<m;i++)
            cout<<(rand()%100000000)+1<<" ";
        cout<<endl;
        for(int i=0;i<n;i++)
            cout<<(rand()%100000000)+1<<" ";
        cout<<endl;
        for(int i=0;i<n;i++)
            cout<<(rand()%100000000)+1<<" ";
        cout<<endl;
    }
    return 0;
}
