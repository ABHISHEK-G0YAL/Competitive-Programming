charToBraile = {}
chars = 'abcdefghijklmnopqrstuvwxyz'
chars += chars.upper()
braile = '100000110000100100100110100010110100110110110010010100010110101000111000101100101110101010111100111110111010011100011110101001111001010111101101101111101011'
braile += braile
b = 0
for c in chars:
    charToBraile[c] = braile[b:b+6]
    b += 6
charToBraile[' '] = '000000'
def solution(s):
    b = ''
    for c in s:
        if c.isupper():
            b += '000001'
        b += charToBraile[c]
    return b