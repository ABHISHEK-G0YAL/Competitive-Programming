# https://practice.geeksforgeeks.org/problems/next-permutation/0

def next_permutation(d):
    for i in range(len(d) - 2, -1, -1):
        if d[i] < d[i + 1]:
            break
    ind = i
    gi = i + 1
    for i in range(i + 1, len(d)):
        if d[i] > d[ind]:
            gi = i
    d[ind], d[gi] = d[gi], d[ind]
    d[ind + 1:] = sorted(d[ind + 1:])
    return d

t = int(input())
for i in range(t):
    n = int(input())
    d = [int(x) for x in input().split()]
    d = next_permutation(d)
    for i in d:
        print(i, end=' ')
    print()