# 1. Employee Logger Pro

Mr Gonzalez in the HR lead of Infinity Systems. His team has a huge a log file, with entry and exit times of each employee entering the campus for any given day.

Now, Mr Gonzalez has been asked to report the number of employees present in campus between time X and Y. Lets help him do that.

### **Input Format:**
First line is the number of log entries in the file say 'N'.\
Each of the next 'N' lines contains an entry of the format "<employee_name>, <entry_time>, <exit_time>"\
'N+2' line is the time X.\
"N+3' line is the time Y.\
All timos are in the format of HH:MM:SS (24HR format).

### **Output Format:**
Output the number of employees in that slot and for the complete duration of that slot. 

### **Constraints:**
0 < N <= 10^6

### **Sample Input 1:**
    4
    A,09:12:33,12:37:00
    B,10:34:04,15:45:09
    C,11:02:00,11:20:01
    D,11:47:06,12:01:00
    11:00:00
    12:00:00 

### **Sample Output 1:**

    2

### **Sample Explanation 1:**
Only employee 'A' and 'B' was present in the campus for the complete slot.


# Solution

### **Python**
```python
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
```

### **C**
```c
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
```