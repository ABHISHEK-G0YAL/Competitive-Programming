#include <bits/stdc++.h>
using namespace std;
int uniquePaintings(int begin,int end,int *paintings)
{
    unordered_map<int, int> hm;
    int i,j,c=0;
    for(i=begin-1;i<end;i++)
    hm[*(paintings+i)]++;
    for(i=begin-1;i<end;i++)
        if(hm[*(paintings+i)]==1)
            ++c;
    return c;
}
    
int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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
        cout << uniquePaintings(sdata[i][0],sdata[i][1],paintings) << '\n';
    return 0;
}

