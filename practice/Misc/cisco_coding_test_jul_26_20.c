#include<stdio.h>
#include<string.h>

int f(char** log, char* start, char* end, int n) {
    int count = 0;
    for(int i = 0; i < n; i++) {
        char *name = strtok(log[i][1], ",");
        char *t1 = strtok(NULL, ",");
        char *t2 = strtok(NULL, ",");
        if(strcmp(t1, start) <= 0 && strcmp(end, t2) <= 0) {
            ++count;
        }
    }
    return count;
}