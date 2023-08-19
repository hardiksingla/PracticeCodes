import re
inp = input("enter string: ")

all = set([chr(ord('a')+i) for i in range(26)])

alpa = set(re.findall("[a-z]",inp))

print(alpa==all)