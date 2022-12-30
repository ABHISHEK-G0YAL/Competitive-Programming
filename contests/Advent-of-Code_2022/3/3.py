from collections import Counter
from itertools import islice

def getPriority(item):
    if 'a' <= item <= 'z':
        return (ord(item) - ord('a')) + 1
    elif 'A' <= item <= 'Z':
        return (ord(item) - ord('A')) + 27
    else:
        return 0

with open('input.txt') as f:
    pSum = 0
    for line in f:
        firstComp, secondComp = line[:len(line)//2], line[len(line)//2:]
        commonItems = Counter(firstComp) & Counter(secondComp)
        for item in commonItems:
            pSum += getPriority(item)

    print(pSum)

with open('input.txt') as f:
    pSum = 0
    while next3Lines:= tuple(islice(f, 3)):
        elf1, elf2, elf3 = next3Lines
        commonItems = Counter(elf1) & Counter(elf2) & Counter(elf3)
        for item in commonItems:
            pSum += getPriority(item)

    print(pSum)
