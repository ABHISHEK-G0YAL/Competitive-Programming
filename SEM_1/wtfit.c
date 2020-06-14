#include <stdio.h>
#include <string.h>
int main()
{
    int n,i,j,sum=0;
    scanf("%d",&n);
    char a[50];
    for(i=0;i<n;i++)
    {
        scanf("%s",a);
        for(j=0;j<strlen(a);j++)
        printf("%d",a[j]);
        printf(" ");
    }
    return 0;
}

