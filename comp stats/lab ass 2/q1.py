def dictPrint(n):
  dic={}
  for i in range(1,n+1):
    dic.update({i:i**2})
  print(dic)
  
n = int(input("enter n: "))

dictPrint(n)