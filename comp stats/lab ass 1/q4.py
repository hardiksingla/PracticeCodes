n = input("eneter the number: ")
mul=1
sum=0

for i in n:
  i = int (i)
  mul = mul*i
  sum = sum + i

if int(n)%mul==0 and int(n)%sum==0 :
  print ("yes")
else:
  print("no")
