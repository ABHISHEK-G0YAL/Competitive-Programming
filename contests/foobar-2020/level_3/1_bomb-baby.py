def solution(x, y):
    x = int(x)
    y = int(y)
    gen = 0
    while x != 0 and y != 0:
        if x < y:
            gen += y / x
            y %= x
        else:
            gen += x / y
            x %= y
    if x == 1 or y == 1:
        print gen - 1
    else:
        print 'impossible'