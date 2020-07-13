// https://www.hackerrank.com/challenges/30-operators/problem

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    double meal_cost; 
    scanf("%lf", &meal_cost);
    int tip_percent; 
    scanf("%i", &tip_percent);
    int tax_percent; 
    scanf("%i", &tax_percent);
    double total_cost=meal_cost+(((double)tip_percent+(double)tax_percent)/100*meal_cost);
    if(!(total_cost-(int)total_cost<0.5))
        total_cost=total_cost+1;
    printf("The total meal cost is %d dollars.",(int)total_cost);
    return 0;
}