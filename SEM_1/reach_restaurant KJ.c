#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int cases;
    scanf("%d",&cases);
    if((cases<1) || (cases>200))
    {
        printf("Enter cases between 1-200");
        return 0;
    }
    int cinemas[cases];
     int n,sum,time;
    for(int i=0;i<cases;i++)
    {
        scanf("%d",&cinemas[i]);
        if((cinemas[i]<1) ||(cinemas[i]>109))
        {
            printf("You don't know right location,enter point between 1-109");
            continue;
        }
         n=1;sum=0;time=0;
        while(sum<cinemas[i])
        {
            sum = ((n*(n+1))/2);
            if(sum>cinemas[i])
            {
                sum=((n-1)*n)/2;
                break;
            }
            n++;
            time++;
        }
        if(sum==cinemas[i])
            printf("%d\n",time);
        else
        {
    ((((n*(n+1))/2)-cinemas[i])<(cinemas[i]-(((n-1)*(n))/2))) ? (time+=(1+(((n*(n+1))/2)-cinemas[i]))):(time+=(cinemas[i]-(((n-1)*    (n))/2)));
        printf("%d\n",time);
        }
    }
    return 0;
}

