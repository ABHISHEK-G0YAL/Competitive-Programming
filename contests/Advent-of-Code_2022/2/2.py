elf1 = {
    'A': 'Rock',
    'B': 'Paper',
    'C': 'Scissors',
}

elf2 = {
    'X': 'Rock',
    'Y': 'Paper',
    'Z': 'Scissors',
}

actionScore = {
    'Rock': 1,
    'Paper': 2,
    'Scissors': 3,
}

roundScore = {
    'Rock': {
        'Rock': 3,
        'Paper': 6,
        'Scissors': 0,
    },
    'Paper': {
        'Rock': 0,
        'Paper': 3,
        'Scissors': 6,
    },
    'Scissors': {
        'Rock': 6,
        'Paper': 0,
        'Scissors': 3,
    },
}

actualRoundScore = {
    'X': 0,
    'Y': 3,
    'Z': 6,
}

actualElf2 = {
    'Rock': {
        'X': 'Scissors',
        'Y': 'Rock',
        'Z': 'Paper',
    },
    'Paper': {
        'X': 'Rock',
        'Y': 'Paper',
        'Z': 'Scissors',
    },
    'Scissors': {
        'X': 'Paper',
        'Y': 'Scissors',
        'Z': 'Rock',
    },
}

with open('input.txt') as f:

    elf2TotalScore = 0
    actualElf2TotalScore = 0

    for line in f:
        c1, c2 = line.strip().split()
        a1, a2 = elf1[c1], elf2[c2]
        elf2TotalScore += actionScore[a2] + roundScore[a1][a2]
        aa2 = actualElf2[a1][c2]
        actualElf2TotalScore += actionScore[aa2] + actualRoundScore[c2]

    print(elf2TotalScore)
    print(actualElf2TotalScore)

