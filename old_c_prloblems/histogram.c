//WAP to make a histogram of entered data.

#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    int n,i,j;
    printf("Enter the number of values you want to enter\n");
    scanf("%d",&n);
    
    int v[n];
    
    printf("Enter the values\n");
    for(i=0;i<n;i++)
    scanf("%d",&v[i]);
    
    int max = v[0];
    for(i=0;i<n;i++)
        if (max < v[i])
            max = v[i];
    
    char hist[max][n];
    
    for(i=0;i<max;i++)
        for(j=0;j<n;j++)
            hist[i][j]=' ';
    
    for(j=0;j<n;j++)
        for(i=max-1;i>=max-v[j];i--)
            hist[i][j]='*';
    
    printf("\n\n\n");
    
    for(i=0;i<max;i++)
    {
        for(j=0;j<n;j++)
            printf("%c",hist[i][j]);
        printf("\n");
    }
}