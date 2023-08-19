inp = input("enter string: ").split("-")

inp.sort()

for i in inp:
  print(f"{i}",end="")
  print("-",end="") if i != inp[-1] else print("",end="")
