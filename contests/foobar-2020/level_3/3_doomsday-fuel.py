'''
foobar:~/ abhishek252167$ cd doomsday-fuel
foobar:~/doomsday-fuel abhishek252167$ cat readme.txt
Doomsday Fuel
=============

Making fuel for the LAMBCHOP's reactor core is a tricky process because of the exotic matter involved. It starts as raw ore, then during processing, begins randomly changing between forms, eventually reaching a stable form. There may be multiple stable forms that a sample could ultimately reach, not all of which are useful as fuel. 

Commander Lambda has tasked you to help the scientists increase fuel creation efficiency by predicting the end state of a given ore sample. You have carefully studied the different structures that the ore can take and which transitions it undergoes. It appears that, while random, the probability of each structure transforming is fixed. That is, each time the ore is in 1 state, it has the same probabilities of entering the next state (which might be the same state).  You have recorded the observed transitions in a matrix. The others in the lab have hypothesized more exotic forms that the ore can become, but you haven't seen all of them.

Write a function solution(m) that takes an array of array of nonnegative ints representing how many times that state has gone to the next state and return an array of ints for each terminal state giving the exact probabilities of each terminal state, represented as the numerator for each state, then the denominator for all of them at the end and in simplest form. The matrix is at most 10 by 10. It is guaranteed that no matter which state the ore is in, there is a path from that state to a terminal state. That is, the processing will always eventually end in a stable state. The ore starts in state 0. The denominator will fit within a signed 32-bit integer during the calculation, as long as the fraction is simplified regularly. 

For example, consider the matrix m:
[
  [0,1,0,0,0,1],  # s0, the initial state, goes to s1 and s5 with equal probability
  [4,0,0,3,2,0],  # s1 can become s0, s3, or s4, but with different probabilities
  [0,0,0,0,0,0],  # s2 is terminal, and unreachable (never observed in practice)
  [0,0,0,0,0,0],  # s3 is terminal
  [0,0,0,0,0,0],  # s4 is terminal
  [0,0,0,0,0,0],  # s5 is terminal
]
So, we can consider different paths to terminal states, such as:
s0 -> s1 -> s3
s0 -> s1 -> s0 -> s1 -> s0 -> s1 -> s4
s0 -> s1 -> s0 -> s5
Tracing the probabilities of each, we find that
s2 has probability 0
s3 has probability 3/14
s4 has probability 1/7
s5 has probability 9/14
So, putting that together, and making a common denominator, gives an answer in the form of
[s2.numerator, s3.numerator, s4.numerator, s5.numerator, denominator] which is
[0, 3, 2, 9, 14].

Languages
=========

To provide a Java solution, edit Solution.java
To provide a Python solution, edit solution.py

Test cases
==========
Your code should pass the following test cases.
Note that it may also be run against hidden test cases not shown here.

-- Java cases --
Input:
Solution.solution({{0, 2, 1, 0, 0}, {0, 0, 0, 3, 4}, {0, 0, 0, 0, 0}, {0, 0, 0, 0,0}, {0, 0, 0, 0, 0}})
Output:
    [7, 6, 8, 21]

Input:
Solution.solution({{0, 1, 0, 0, 0, 1}, {4, 0, 0, 3, 2, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}})
Output:
    [0, 3, 2, 9, 14]

-- Python cases --
Input:
solution.solution([[0, 2, 1, 0, 0], [0, 0, 0, 3, 4], [0, 0, 0, 0, 0], [0, 0, 0, 0,0], [0, 0, 0, 0, 0]])
Output:
    [7, 6, 8, 21]

Input:
solution.solution([[0, 1, 0, 0, 0, 1], [4, 0, 0, 3, 2, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0]])
Output:
    [0, 3, 2, 9, 14]

Use verify [file] to test your solution and see how it does. When you are finished editing your code, use submit [file] to submit your answer. If your solution passes the test cases, it will be removed from your home folder.
foobar:~/doomsday-fuel abhishek252167$ edit solution.py
foobar:~/doomsday-fuel abhishek252167$ verify solution.py
Verifying solution...
Test 1 passed!
Test 2 passed!
Test 3 passed! [Hidden]
Test 4 passed! [Hidden]
Test 5 passed! [Hidden]
Test 6 passed! [Hidden]
Test 7 passed! [Hidden]
Test 8 passed! [Hidden]
Test 9 failed  [Hidden]
Test 10 passed! [Hidden]
foobar:~/doomsday-fuel abhishek252167$ verify solution.py
Verifying solution...
All test cases passed. Use submit solution.py to submit your solution
foobar:~/doomsday-fuel abhishek252167$ cat solution.py
from​ ​fractions​ ​import​ ​Fraction
from​ ​fractions​ ​import​ ​gcd

def​ ​getMatrixInverse(m):
​ ​​ ​​ ​​ ​I​ ​=​ ​[[int(i​ ​==​ ​j)​ ​for​ ​i​ ​in​ ​xrange(len(m))]​ ​for​ ​j​ ​in​ ​xrange(len(m))]
​ ​​ ​​ ​​ ​for​ ​i​ ​in​ ​xrange(len(m)):
​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​mul​ ​=​ ​1​ ​/​ ​m[i][i]
​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​m[i]​ ​=​ ​[mul​ ​*​ ​x​ ​for​ ​x​ ​in​ ​m[i]]
​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​I[i]​ ​=​ ​[mul​ ​*​ ​x​ ​for​ ​x​ ​in​ ​I[i]]
​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​for​ ​j​ ​in​ ​xrange(len(m)):
​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​if​ ​i​ ​!=​ ​j:
​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​mul​ ​=​ ​m[j][i]
​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​m[j]​ ​=​ ​[a​ ​-​ ​mul​ ​*​ ​b​ ​for​ ​a,​ ​b​ ​in​ ​zip(m[j],​ ​m[i])]
​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​I[j]​ ​=​ ​[a​ ​-​ ​mul​ ​*​ ​b​ ​for​ ​a,​ ​b​ ​in​ ​zip(I[j],​ ​I[i])]
​ ​​ ​​ ​​ ​return​ ​I​ ​​ ​​ ​​ ​​ ​​ ​
def​ ​solution(m):
​ ​​ ​​ ​​ ​if​ ​len(m)​ ​==​ ​1:
​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​return​ ​[1,​ ​1]
​ ​​ ​​ ​​ ​idx​ ​=​ ​[]
​ ​​ ​​ ​​ ​e​ ​=​ ​0
​ ​​ ​​ ​​ ​for​ ​i​ ​in​ ​xrange(len(m)):
​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​if​ ​sum(m[i​ ​-​ ​e])​ ​==​ ​0:
​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​idx.append(i​ ​-​ ​e)
​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​del​ ​m[i​ ​-​ ​e]
​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​e​ ​+=​ ​1
​ ​​ ​​ ​​ ​[l.append(l.pop(j))​ ​for​ ​l​ ​in​ ​m​ ​for​ ​j​ ​in​ ​idx]
​ ​​ ​​ ​​ ​m​ ​=​ ​[[Fraction(i,​ ​sum(l))​ ​for​ ​i​ ​in​ ​l]​ ​for​ ​l​ ​in​ ​m]
​ ​​ ​​ ​​ ​q​ ​=​ ​[l[0:len(m)]​ ​for​ ​l​ ​in​ ​m]
​ ​​ ​​ ​​ ​r​ ​=​ ​[l[len(m):]​ ​for​ ​l​ ​in​ ​m]
​ ​​ ​​ ​​ ​q​ ​=​ ​[[1​ ​-​ ​n​ ​if​ ​i​ ​==​ ​j​ ​else​ ​-n​ ​for​ ​j,​ ​n​ ​in​ ​enumerate(l)]​ ​for​ ​i,​ ​l​ ​in​ ​enumerate(q)]
​ ​​ ​​ ​​ ​q​ ​=​ ​getMatrixInverse(q)
​ ​​ ​​ ​​ ​result​ ​=​ ​[[sum(i*j​ ​for​ ​i,j​ ​in​ ​zip(qRow,​ ​rCol))​ ​for​ ​rCol​ ​in​ ​zip(*r)]​ ​for​ ​qRow​ ​in​ ​q]
​ ​​ ​​ ​​ ​lcm​ ​=​ ​result[0][0].denominator
​ ​​ ​​ ​​ ​for​ ​x​ ​in​ ​result[0][1:]:
​ ​​ ​​ ​​ ​​ ​​ ​​ ​​ ​lcm​ ​=​ ​lcm​ ​//​ ​gcd(lcm,​ ​x.denominator)​ ​*​ ​x.denominator
​ ​​ ​​ ​​ ​result​ ​=​ ​[(x​ ​*​ ​lcm).numerator​ ​for​ ​x​ ​in​ ​result[0]]
​ ​​ ​​ ​​ ​result.append(lcm)
​ ​​ ​​ ​​ ​return​ ​result
foobar:~/doomsday-fuel abhishek252167$ submit solution.py
Are you sure you want to submit your solution?
[Y]es or [N]o: y
Submitting solution...
Excellent! You've destroyed Commander Lambda's doomsday device and saved Bunny Planet! But there's one small problem: the LAMBCHOP was a wool-y important part of her space station, and when you blew it up, you triggered a chain reaction that's tearing the station apart. Can you rescue the imprisoned bunnies and escape before the entire thing explodes?
Submission: SUCCESSFUL. Completed in: 3 days, 4 hrs, 17 mins, 47 secs.

Level 3 complete
You are now on level 4
Challenges left to complete level: 2

Level 1: 100% [==========================================]
Level 2: 100% [==========================================]
Level 3: 100% [==========================================]
Level 4:   0% [..........................................]
Level 5:   0% [..........................................]

Refer a friend: "https://foobar.withgoogle.com/?eid=NJWRW" (Used)

Type request to request a new challenge now, or come back later.

The code is strong with this one...
You can now share your solutions with a Google recruiter!
If you opt in, Google staffing may reach out to you regarding career opportunities.
We will use your information in accordance with our Applicant and Candidate Privacy Policy.
[#1] Do you wish to proceed?
[Y]es [N]o [A]sk me later: 
'''

from fractions import Fraction
from fractions import gcd

def getMatrixInverse(m):
    I = [[int(i == j) for i in xrange(len(m))] for j in xrange(len(m))]
    for i in xrange(len(m)):
        mul = 1 / m[i][i]
        m[i] = [mul * x for x in m[i]]
        I[i] = [mul * x for x in I[i]]
        for j in xrange(len(m)):
            if i != j:
                mul = m[j][i]
                m[j] = [a - mul * b for a, b in zip(m[j], m[i])]
                I[j] = [a - mul * b for a, b in zip(I[j], I[i])]
    return I

def solution(m):
    idx = []
    e = 0
    for i in xrange(len(m)):
        if sum(m[i - e]) == 0:
            idx.append(i - e)
            del m[i - e]
            e += 1
    [l.append(l.pop(j)) for l in m for j in idx]
    m = [[Fraction(i, sum(l)) for i in l] for l in m]
    q = [l[0:len(m)] for l in m]
    r = [l[len(m):] for l in m]
    q = [[1 - n if i == j else -n for j, n in enumerate(l)] for i, l in enumerate(q)]
    q = getMatrixInverse(q)
    result = [[sum(i*j for i,j in zip(qRow, rCol)) for rCol in zip(*r)] for qRow in q]
    lcm = result[0][0].denominator
    for x in result[0][1:]:
        lcm = lcm // gcd(lcm, x.denominator) * x.denominator
    result = [(x * lcm).numerator for x in result[0]]
    result.append(lcm)
    return result

# TEST 1
# m = [[0, 2, 1, 0, 0], [0, 0, 0, 3, 4], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0]]
# a = [7, 6, 8, 21]

# TEST 2
# m = [[0, 1, 0, 0, 0, 1], [4, 0, 0, 3, 2, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0]]
# a = [0, 3, 2, 9, 14]

# TEST 3
# m = [[1, 2, 3, 0, 0, 0], [4, 5, 6, 0, 0, 0], [7, 8, 9, 1, 0, 0], [0, 0, 0, 0, 1, 2], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0]]
# a = [1, 2, 3]

#TEST 4
# m = [[0]]
# a = [1, 1]

# TEST 5
# m = [[0, 0, 12, 0, 15, 0, 0, 0, 1, 8], [0, 0, 60, 0, 0, 7, 13, 0, 0, 0], [0, 15, 0, 8, 7, 0, 0, 1, 9, 0], [23, 0, 0, 0, 0, 1, 0, 0, 0, 0], [37, 35, 0, 0, 0, 0, 3, 21, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]]
# a = [1, 2, 3, 4, 5, 15]

# TEST 6
# m = [[ 0,  7,  0, 17,  0,  1,  0,  5,  0,  2], [ 0,  0, 29,  0, 28,  0,  3,  0, 16,  0], [ 0,  3,  0,  0,  0,  1,  0,  0,  0,  0], [48,  0,  3,  0,  0,  0, 17,  0,  0,  0], [ 0,  6,  0,  0,  0,  1,  0,  0,  0,  0], [ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0], [ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0], [ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0], [ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0], [ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0]]
# a = [4, 5, 5, 4, 2, 20]

# TEST 7
# m = [[1, 1, 1, 1, 1, 1, 1, 1, 1, 1], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [1, 1, 1, 1, 1, 1, 1, 1, 1, 1], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [1, 1, 1, 1, 1, 1, 1, 1, 1, 1], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [1, 1, 1, 1, 1, 1, 1, 1, 1, 1], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [1, 1, 1, 1, 1, 1, 1, 1, 1, 1], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]]
# a = [1, 1, 1, 1, 1, 5]

# TEST 8
# m = [[1, 1, 1, 0, 1, 0, 1, 0, 1, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [1, 0, 1, 1, 1, 0, 1, 0, 1, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [1, 0, 1, 0, 1, 1, 1, 0, 1, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [1, 0, 1, 0, 1, 0, 1, 1, 1, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [1, 0, 1, 0, 1, 0, 1, 0, 1, 1], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]]
# a = [2, 1, 1, 1, 1, 6]

# TEST 9
# m = [[0, 86, 61, 189, 0, 18, 12, 33, 66, 39], [0, 0, 2, 0, 0, 1, 0, 0, 0, 0], [15, 187, 0, 0, 18, 23, 0, 0, 0, 0], [1, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]]
# a = [6, 44, 4, 11, 22, 13, 100]

# TEST 10
# m = [[0, 0, 0, 0, 3, 5, 0, 0, 0, 2], [0, 0, 4, 0, 0, 0, 1, 0, 0, 0], [0, 0, 0, 4, 4, 0, 0, 0, 1, 1], [13, 0, 0, 0, 0, 0, 2, 0, 0, 0], [0, 1, 8, 7, 0, 0, 0, 1, 3, 0], [1, 7, 0, 0, 0, 0, 0, 2, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]]
# a = [1, 1, 1, 2, 5]

# print solution(m)

# Concept https://github.com/ivanseed/google-foobar-help/blob/master/challenges/doomsday_fuel/doomsday_fuel.md

# StackOverFlow code to invert a Matrix

# def transposeMatrix(m):
#     return map(list,zip(*m))

# def getMatrixMinor(m,i,j):
#     return [row[:j] + row[j+1:] for row in (m[:i]+m[i+1:])]

# def getMatrixDeternminant(m):
#     #base case for 2x2 matrix
#     if len(m) == 2:
#         return m[0][0]*m[1][1]-m[0][1]*m[1][0]

#     determinant = 0
#     for c in range(len(m)):
#         determinant += ((-1)**c)*m[0][c]*getMatrixDeternminant(getMatrixMinor(m,0,c))
#     return determinant

# def getMatrixInverse(m):
#     determinant = getMatrixDeternminant(m)
#     #special case for 2x2 matrix:
#     if len(m) == 2:
#         return [[m[1][1]/determinant, -1*m[0][1]/determinant],
#                 [-1*m[1][0]/determinant, m[0][0]/determinant]]

#     #find matrix of cofactors
#     cofactors = []
#     for r in range(len(m)):
#         cofactorRow = []
#         for c in range(len(m)):
#             minor = getMatrixMinor(m,r,c)
#             cofactorRow.append(((-1)**(r+c)) * getMatrixDeternminant(minor))
#         cofactors.append(cofactorRow)
#     cofactors = transposeMatrix(cofactors)
#     for r in range(len(cofactors)):
#         for c in range(len(cofactors)):
#             cofactors[r][c] = cofactors[r][c]/determinant
#     return cofactors