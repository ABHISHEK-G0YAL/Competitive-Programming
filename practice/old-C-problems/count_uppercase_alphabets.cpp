// WAP to count uppercase alphabets in input string

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char a[1000];int i,count=0;
    gets(a);
    for(i=0;i<strlen(a);i++)
        if(a[i]>=65 && a[i]<=90)
            ++count;
    printf("%d",count);  
    return 0;
}