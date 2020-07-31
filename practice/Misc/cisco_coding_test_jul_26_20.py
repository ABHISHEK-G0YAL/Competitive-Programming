# https://github.com/ABHISHEK-G0YAL/Competitive-Programming/blob/master/practice/Misc/cisco_coding_test_jul_26_20.md

# string time to sec
def st2s(s):
    h, m, s = int(x) for x in s.split(':')
    return ((h * 60 + m) * 60 + s)

n = int(input())
logs = list()
for i in range(n):
    name, t1, t2 = input().split(',')
    logs.append(st2s(t1), st2s(t2))
start_time = st2s(input())
end_time = st2s(input())
cnt = 0
for e in logs:
    cnt += (e[0] <= start_time and end_time <= e[1])
print(cnt)