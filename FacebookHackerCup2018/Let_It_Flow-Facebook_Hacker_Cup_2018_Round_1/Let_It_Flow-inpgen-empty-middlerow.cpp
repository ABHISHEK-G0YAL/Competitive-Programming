#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main()
{
    srand(time(0));
    int t=(rand()%100)+1;
    cout<<t<<endl;
    while(t--)
    {
        again:;
        int n=(rand()%1000)+1;
        if(n%2==1)
            goto again;
        cout<<n<<endl;
        for(int i=1;i<=3;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==2)
                    cout<<".";
                else
                    cout<<((rand()%32)?".":"#");
            }
            cout<<endl;
        }
    }
    return 0;
}
// g++ Let_It_Flow-inpgen-empty-middlerow.cpp 
// ./a.out >input1.txt
// ./a.out >input2.txt
// ./a.out >input3.txt
// g++ Let_It_Flow-Facebook_Hacker_Cup_2018_Round_1.cpp 
// ./a.out <input1.txt >out1.txt
// ./a.out <input2.txt >out2.txt
// ./a.out <input3.txt >out3.txt
// g++ let_it_flow_1.cpp 
// ./a.out <input1.txt >out11.txt
// ./a.out <input2.txt >out22.txt
// ./a.out <input3.txt >out33.txt
// diff out1.txt out11.txt                                                                               
// diff out2.txt out22.txt                                                                               
// diff out3.txt out33.txt