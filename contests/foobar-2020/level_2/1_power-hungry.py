def solution(xs):
    nmax = -1001
    power = 1
    cnt = 0
    for panel in xs:
        if panel > 0:
            power *= panel
        elif panel < 0:
            power *= panel
            if panel > nmax:
                nmax = panel
        else:
            cnt += 1
    if len(xs) == 1:
        print xs[0]
    if cnt == len(xs):
        print 0
    elif cnt == len(xs) - 1:
        print max(0, power)
    else:
        if power < 0:
            power /= nmax
        print power