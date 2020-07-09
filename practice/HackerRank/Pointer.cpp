// https://www.hackerrank.com/challenges/c-tutorial-pointer/problem
// Accepted

#include <stdio.h>
void abs(int *b) {
    if(*b < 0) *b *= -1;
}
void update(int *a,int *b) {
    *a += *b;
    *b = *a - 2 * *b;
    abs(b);
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);
    return 0;
}

