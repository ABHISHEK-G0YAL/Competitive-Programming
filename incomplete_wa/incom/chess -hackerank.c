#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() 
{
    int i,j,t,p,r; 
    scanf("%d", &t);
    while(t--)
    {
        char b[9][9];
        for(i=0;i<8;i++)
            for(j=0;j<8;j++)
                scanf("%c",&b[i][j]);
        for(j=0;j<8;j++)
            if(b[1][j]=='P')
                p=j;
        printf("%d",p);
        if( (p-2>=0 && b[1][p-2]=='k') ||  (p+2<8 && b[1][p+2]=='k') ||  (p-1>=0 && b[2][p-1]=='k') ||  (p+1<8 && b[2][p+1]=='k') )
            r=1;
       else
        {
           r=0;
            for(i=1;i<8;i++)
            {
                if(p-i>=0 && b[0][p-i]=='k')
                {
                    for(j=p-i+1;j<p;j++)
                    {
                        if(b[0][j]!='#')
                        {r=0;break;}
                        else
                        {r=2;break;}
                    }
                }
                else if(p+i<8 && b[0][p+i]=='k')
                {
                    for(j=p+1;j<p+i;j++)
                    {
                        if(b[0][j]!='#')
                        {r=0;break;}
                        else
                        {r=2;break;}
                    }
                }
                else if(b[i][p]=='k')
                {
                    for(j=2;j<i;j++)
                    {
                        if(b[j][p]!='#')
                        {r=0;break;}
                        else
                        {r=2;break;}
                    }
                }
                else if(p-i>=0 && b[i][p-i]=='k')
                {
                    for(j=1;j<i;j++)
                    {
                        if(b[j][p-j]!='#')
                        {r=0;break;}
                        else
                        {r=2;break;}
                    }
                }
                else if(p+i<8 && b[i][p+i]=='k')
                {
                    for(j=1;j<i;j++)
                    {
                        if(b[j][p+j]!='#')
                        {r=0;break;}
                        else
                        {r=2;break;}
                    }
                }
            }
        }
        printf("%d\n",r);
    }
    return 0;
}
