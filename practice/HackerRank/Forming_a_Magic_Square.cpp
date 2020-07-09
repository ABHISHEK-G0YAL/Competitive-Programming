// https://www.hackerrank.com/challenges/magic-square-forming/problem
// Accepted

#include <bits/stdc++.h>

using namespace std;

int formingMagicSquare(vector < vector<int> > s)
{
    // Complete this function
    int a[3][3]={8,1,6,3,5,7,4,9,2},sum[8]={0,0,0,0,0,0,0,0};
    int i,j,k,min;
    for(k=0;k<8;k++)
    {
        if(k==4)
        {
            //mirror array
            for(int i=0;i<3;i++)
            {
                a[i][0]=a[i][0]+a[i][2];
                a[i][2]=a[i][0]-a[i][2];
                a[i][0]=a[i][0]-a[i][2];
            }
        }
        else
        {
            //rotate array
            int temp=a[0][0]; a[0][0]=a[2][0]; a[2][0]=a[2][2]; a[2][2]=a[0][2]; a[0][2]=temp;
            temp=a[0][1]; a[0][1]=a[1][0]; a[1][0]=a[2][1]; a[2][1]=a[1][2]; a[1][2]=temp;
        }
        for(i=0;i<3;i++)
            for(j=0;j<3;j++)
                sum[k]+=abs(a[i][j]-s[i][j]);
    }
    min=sum[0];
    for(k=1;k<8;k++)
        if(min>sum[k])
            min=sum[k];
    return min;
}

int main() {
    vector< vector<int> > s(3,vector<int>(3));
    for(int s_i = 0;s_i < 3;s_i++){
       for(int s_j = 0;s_j < 3;s_j++){
          cin >> s[s_i][s_j];
       }
    }
    int result = formingMagicSquare(s);
    cout << result << endl;
    return 0;
}
