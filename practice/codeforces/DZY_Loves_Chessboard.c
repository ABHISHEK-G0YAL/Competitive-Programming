// http://codeforces.com/contest/445/problem/A

#include <stdio.h>
int main()
{
    int i,j,n,m;
    scanf("%d %d",&n,&m);
    char board[n][m];
    for(i=0;i<n;i++)
    for(j=0;j<m;j++)
    scanf(" %c",&board[i][j]);
    
    for(i=0;i<n;i++)
    {
    	for(j=0;j<m;j++)
		{
			if(board[i][j]=='.' && i % 2 == 0 )
			{
				if(j % 2 == 0)
				board[i][j]='B';
				else
				board[i][j]='W';
			}
			if(board[i][j]=='.' && i % 2 == 1)
			{
				if(j % 2 == 1)
				board[i][j]='B';
				else
				board[i][j]='W';
			}
		}
	}
    for(i=0;i<n;i++)
    {
    	for(j=0;j<m;j++)
    	printf("%c",board[i][j]);
    	printf("\n");
	}
}