// https://www.hackerrank.com/challenges/30-conditional-statements/problem

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int N; 
    scanf("%d",&N);
    if(N%2==0)
    {
        if(N>=6 && N<=20)
            printf("Weird");
        else
            printf("Not Weird");
    }
    else
        printf("Weird");
    return 0;
}
