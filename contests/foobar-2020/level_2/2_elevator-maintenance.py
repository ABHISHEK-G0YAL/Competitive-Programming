def solution(l):
    def cmpv(v1, v2):
        v1 = map(int, v1.split('.'))
        v2 = map(int, v2.split('.'))
        le = min(len(v1), len(v2))
        for i in xrange(le):
            if v1[i] - v2[i] != 0:
                return v1[i] - v2[i]
        return len(v1) - len(v2)
    l = sorted(l, cmp=cmpv)
    return l