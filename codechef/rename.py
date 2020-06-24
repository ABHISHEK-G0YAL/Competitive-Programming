import os

def main():
    for filename in os.listdir():
        if filename.split('.')[-1] == 'cpp':
            newfilename = f"{filename.split('_')[0]}.cpp"
            print(f'{filename} -> {newfilename}')
            os.rename(filename, newfilename)

if __name__ == '__main__':
    main() 