from copy import deepcopy

def find_top_crates(stacks, moves, crane):
    # Create a dictionary to store the final top crates for each stack
    # print("Stacks before moves:\n", stacks, '\n')
    for move in moves:
        # print(move)
        move_parts = move.split()
        # num_crates = int(move_parts[1])
        # src_stack = int(move_parts[3])
        # dest_stack = int(move_parts[5])
        num_crates, src_stack, dest_stack = (int(move_parts[i]) for i in [1, 3, 5])
        
        if crane == 9000:
            for _ in range(num_crates):
                stacks[dest_stack] = [ stacks[src_stack].pop(0) ] + stacks[dest_stack]
        elif crane == 9001:
            crates = []
            for _ in range(num_crates):
                crates.append(stacks[src_stack].pop(0))
            stacks[dest_stack] = crates + stacks[dest_stack]

        # print("Stacks after move:\n", stacks, '\n')

    return ''.join([ stack[0] for stack in stacks.values() ])

with open('input.txt', 'r') as f:
    lines = f.readlines()

stacks = {}
moves = []
for line in lines:
    if line.startswith('move'):
        moves.append(line.strip())
    else:
        for i, ch in enumerate(line):
            if ch.isalpha():
                stacks.setdefault(int((i + 3) / 4), []).append(ch)

stacks = dict(sorted(stacks.items()))
print(find_top_crates(deepcopy(stacks), moves, 9000))
print(find_top_crates(deepcopy(stacks), moves, 9001))
