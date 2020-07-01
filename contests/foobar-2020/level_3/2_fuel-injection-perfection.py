# converted the recursive solution written bellow to iterative

map = {}
stack = []
def solution(n):
    n = int(n)
    stack.append(n)
    while len(stack) > 0:
        n = stack[-1]
        if map.get(n):
            stack.pop()
        elif n == 1:
            map[n] = 0
            stack.pop()
        elif n % 2 == 0:
            if map.get(n / 2) is not None:
                map[n] = 1 + map[n / 2]
                stack.pop()
            else:
                stack.append(n / 2)
        else:
            if map.get(n + 1) is not None and map.get(n - 1) is not None:
                map[n] = 1 + min(map[n + 1], map[n - 1])
                stack.pop()
            else:
                stack.append(n - 1)
                stack.append(n + 1)
    return map[n]

# import sys is BLACKLISTED_CODE

# import sys
# sys.setrecursionlimit(15000)
# map = {}
# def solution(n):
#     n = int(n)
#     if map.get(n):
#         return map[n]
#     if n == 1:
#         map[n] = 0
#     elif n % 2 == 0:
#         map[n] = 1 + solution(n / 2)
#     else:
#         map[n] = 1 + min(solution(n + 1), solution(n - 1))
#     return map[n]