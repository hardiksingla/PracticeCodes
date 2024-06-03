m = int(input("enter m: "))
n = int(input("enter n: "))

for i in range(1,n):
  print(f"{m}^{i} mod {n} = {(m**i)%n}")

def primitiveCheck2(m,n):
  lis = []
  for x in range (0,m-1):
    num = (n**x)%m
    if num in lis:
      return -1
    else:
      lis.append(num)
  if (x==m-2):
    return n

pr = open("pr.txt","w")
npr = open("npr.txt","w")

for i in range(2,m):
  if primitiveCheck2(m,i) != -1:
    pr.write(str(i)+"\n")
  else:
    npr.write(str(i)+"\n")




