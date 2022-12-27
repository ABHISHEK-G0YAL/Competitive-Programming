ROOT = {
    'type': 'dir',
    'size': None,
    'files': {},
}

pwd = ROOT

def cd(name):
    global pwd
    if(name == '/'):
        pwd = ROOT
    else:
        pwd = pwd['files'][name]

def mkdir(name):
    global pwd
    pwd['files'][name] = {
        'type': 'dir',
        'size': None,
        'files': {
            '..': pwd,
        },
    }

def touch(name, size)::
    global pwd
    pwd['files'][name] = {
        'type': 'file',
        'size': int(size),
    }


with open('input.txt') as f:
    while line := f.readline().rstrip():
        if line.startswith('$ cd'):
            _, _, dir = line.split(' ')
            cd(dir)
        elif line.startswith('$ ls'):
            continue
        elif line.startswith('dir'):
            _, name = line.split(' ')
            mkdir(name)
        else:
            size, name = line.split(' ')
            touch(name, size)


dirSum, SIZE_LIMIT = 0, 100000
def computeSize(file):
    global dirSum
    if file['type'] == 'dir':
        childs = file['files']
        file['size'] = sum(computeSize(childs[f]) for f in childs if f != '..')

        if file['size'] <= SIZE_LIMIT:
            dirSum += file['size']

    return file['size']


computeSize(ROOT)
print(dirSum)
print(ROOT)


TOTAL_SPACE, NEEDED_SPACE = 70000000, 30000000
FREE_SPACE = TOTAL_SPACE - ROOT['size']
NEED_TO_FREE = NEEDED_SPACE - FREE_SPACE
minDirSize = float('inf')

# find smallest directory to delete
def dfs(dir):
    global minDirSize
    if NEED_TO_FREE <= dir['size'] < minDirSize:
        minDirSize = dir['size']
    
    childs = dir['files']
    for fName in childs:
        if fName != '..':
            file = childs[fName]
            if file['type'] == 'dir':
                dfs(file)

dfs(ROOT)
print(minDirSize)

