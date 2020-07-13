import os
import json

ulines = {}
exclude = {
    '.\practice': ['DSA', 'old-C-problems', 'Misc', '.jpeg', '.txt'],
    '.\contests': ['.html', '.pdf', 'Hash-Code', 'expedia_hiring_challenge_11Jan19', 'foobar_2020']
}
for root in exclude:
    for path, dirs, files in os.walk(root):
        for file in files:
            filepath = path + '\\' + file
            if any(x in filepath for x in exclude[root]):
                continue
            with open(filepath) as f:
                print(filepath)
                f.readline()
                line = f.readline()
                if ulines.get(line):
                    ulines[line].append(filepath)
                else:
                    ulines[line] = [filepath]

with open('dump.json', 'w') as f:
    json.dump(ulines, f, indent=4)

# with open('dump.json') as f:
#     ulines = json.load(f)

# del ulines['']

for uline in ulines:
    print([uline], len(ulines[uline]))
    if uline != '\n':
        print([uline])
        for filepath in ulines[uline]:
            print(filepath)
    #         if uline.find('Accepted') != -1:
    #             print([uline])
    #             with open(filepath) as f:
    #                 code = f.readlines()
    #             print(code[:5])
    #             del code[1]
    #             print(code[:4])
    #             input()
    #             with open(filepath, 'w') as f:
    #                 f.writelines(code)
    #         if uline.find('Correct') != -1:
    #             print([uline])
    #             with open(filepath) as f:
    #                 code = f.readlines()
    #             print(code[:5])
    #             del code[1]
    #             print(code[:4])
    #             input()
    #             with open(filepath, 'w') as f:
    #                 f.writelines(code)
    #         if filepath.find('old-C-problems') != -1:
    #             print([uline])
    #         if filepath.find('LeetCode') != -1:
    #             if uline.find('Accepted') != -1:
    #                 print([uline])
    #                 with open(filepath) as f:
    #                     code = f.readlines()
    #                 print(code[:5])
    #                 del code[1]
    #                 print(code[:4])
    #                 input()
    #                 with open(filepath, 'w') as f:
    #                     f.writelines(code)

# with open('dump.json', 'w') as f:
#     json.dump(ulines, f, indent=4)