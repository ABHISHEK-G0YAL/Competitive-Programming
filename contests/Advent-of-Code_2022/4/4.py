def rangeContains(l1, r1, l2, r2):
    return l1 <= l2 and r2 <= r1

def rangeOverlap(l1, r1, l2, r2):
    return l1 <= r2 and l2 <= r1

with open('input.txt') as f:
    contain = 0
    overlap = 0
    for line in f:
        line = line.strip()
        elf1, elf2 = line.split(',')
        l1, r1 = map(int, elf1.split('-'))
        l2, r2 = map(int, elf2.split('-'))
        if rangeContains(l1, r1, l2, r2) or rangeContains(l2, r2, l1, r1):
            # print(l1, '-', r1, ',', l2, '-', r2)
            contain += 1

        if rangeOverlap(l1, r1, l2, r2):
            # print(l1, '-', r1, ',', l2, '-', r2)
            overlap += 1

    print(contain)
    print(overlap)

