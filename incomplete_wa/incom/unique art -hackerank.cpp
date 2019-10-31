#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int uniquePaintings(int begin,int end,int *paintings)
{
    int i,j,count1,count2=0;
    for(i=begin-1;i<end;i++)
    {
        count1=0;
        for(j=begin-1;j<end;j++)
        {
            if(*(paintings+i)==*(paintings+j))
                ++count1;
        }
        if(count1==1)
            ++count2;
    }
    return count2;
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int i,j,n,sn;
    cin >> n;
    int paintings[n];
    for(i=0;i<n;i++)
    cin >> paintings[i];
    cin >> sn;
    int sdata[sn][2];
    for(i=0;i<sn;i++)
    cin >> sdata[i][0] >> sdata[i][1];
    for(i=0;i<sn;i++)
        cout << uniquePaintings(sdata[i][0],sdata[i][1],paintings);
    return 0;
}

