import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

data = {
    "country":["Afganistan","US","UK","germany","France","China","India","Brazil","Australia","Russia"],
    "continent":["AS","NA","EU","EU","EU","AS","AS","SA","AU","AS"],
    "GDP": [4500,9500,6200,3200,3400,7400,1400,5200,3600,8500],
    "income":[9874,6572,9875,3258,6512,3214,8521,7412,9632,9674],
    "litracy":[98,78,85,74,96,82,91,73,84,94],
    "militaty":[5.3,4.5,8.9,2.6,5.9,7.2,7.6,8.2,1.6,6.5]
}
df = pd.DataFrame(data)
print(df)

plt.scatter(df["continent"], df["country"],color=["red","blue","pink","pink","pink","red","red","black","yellow","red"])
plt.title("number of countries")
plt.show()
 

plt.bar(df["continent"],df["litracy"],)
plt.title("litracy rate by continent")
plt.xlabel("continent")
plt.ylabel("litracy")
plt.show()

plt.pie(df["income"],labels =df["country"],radius = 1.2,autopct = '%1.1f%%')
plt.title("income of countries")
plt.show()

plt.bar(df["country"],df["GDP"],color=["red","blue","pink","violet","green","indigo","grey","black","yellow","purple"])
plt.title("GDP of countries")
plt.xlabel("country")
plt.ylabel("GDP")
plt.show()

plt.pie(df["income"],labels =df["country"],radius = 1.2,autopct = '%1.1f%%')
plt.title("income of countries")
plt.show()

asia = df[df["continent"]=="AS"]
asia_income = asia["income"].sum()
other = df[df["continent"]!="AS"]
other_income = other["income"].sum()
plt.pie([asia_income,other_income],labels = ["asia","other"],radius = 1.2,autopct = '%1.1f%%')
plt.show()

plt.stackplot(df["country"],df["income"],colors=["red"])
plt.xlabel("country")
plt.title("income of countries")
plt.ylabel("income")
plt.show()