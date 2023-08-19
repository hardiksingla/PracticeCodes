fil = open("q3-1.txt","r")
data = fil.read().split(" ")

f2 = open("q3-2.txt","w")

if (int(data[1][0]+data[1][-1])%2==0):
  f2.write("even")
else:
  f2.write("odd")

print(int(data[0]*int(data[1]))%int(data[2]))