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