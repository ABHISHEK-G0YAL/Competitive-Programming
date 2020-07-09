// https://www.hackerrank.com/challenges/extra-long-factorials/problem
// Accepted

#!/bin/python3

# Complete the extraLongFactorials function below.
def extraLongFactorials(n):
    f=1
    while n:
        f=f*n
        n=n-1
    print(f)


if __name__ == '__main__':
    n = int(input())

    extraLongFactorials(n)
