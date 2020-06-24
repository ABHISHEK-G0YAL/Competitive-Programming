// https://www.codechef.com/problems/HOMDEL

#include <iostream>
using namespace std;
 
int main()
{
	int N;
	cin>>N;
	int T[N][N];
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin>>T[i][j];
	for(int k=0;k<N;k++)
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				if(T[i][k]+T[k][j] < T[i][j])
                    T[i][j]=T[i][k]+T[k][j];
    int m,s,g,d;
	cin>>m;
	while(m--)
	{
		cin>>s>>g>>d;
		cout<<T[s][g]+T[g][d]<<" "<<T[s][g]+T[g][d]-T[s][d]<<endl;
	}
	return 0;
}